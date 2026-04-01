#include <JuceHeader.h>
#include "Oscilator.h" 

class MainComponent : public juce::AudioAppComponent
{
public:
    MainComponent()
    {
        setAudioChannels(0, 2); // 0 inputs, 2 outputs (stereo)
        oscillator.setFrequency(1000.0, 44100.0);
    }

    ~MainComponent() override
    {
        shutdownAudio();
    }

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override
    {
        oscillator.setFrequency(440.0, sampleRate);
    }

    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override
    {
        auto* leftBuffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);
        auto* rightBuffer = bufferToFill.buffer->getWritePointer(1, bufferToFill.startSample);

        for (int i = 0; i < bufferToFill.numSamples; ++i)
        {
            float sample = oscillator.getNextSample();
            leftBuffer[i] = sample;
            rightBuffer[i] = sample;
        }
    }

    void releaseResources() override {}

private:
    Oscillator oscillator;
};

class MainWindow : public juce::DocumentWindow
{
public:
    MainWindow() : DocumentWindow("Synth",
                                  juce::Colours::black,
                                  DocumentWindow::allButtons)
    {
        setContentOwned(new MainComponent(), true);
        centreWithSize(400, 200);
        setVisible(true);
    }

    void closeButtonPressed() override
    {
        juce::JUCEApplication::getInstance()->systemRequestedQuit();
    }
};

class SynthApplication : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override       { return "SimpleSynth"; }
    const juce::String getApplicationVersion() override    { return "1.0.0"; } // <-- konieczne
    bool moreThanOneInstanceAllowed() override             { return true; }

    void initialise(const juce::String&) override { mainWindow.reset(new MainWindow()); }
    void shutdown() override                        { mainWindow = nullptr; }

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(SynthApplication)