#pragma once
#include <JuceHeader.h>

class Oscillator
{
public:
    Oscillator() = default;

    void setFrequency(double freq, double sampleRate)
    {
        frequency = freq;
        this->sampleRate = sampleRate;
        phaseIncrement = 2.0 * juce::MathConstants<double>::pi * frequency / sampleRate;
    }

    float getNextSample()
    {
        float sample = std::sin(phase);
        phase += phaseIncrement;
        if (phase > 2.0 * juce::MathConstants<double>::pi)
            phase -= 2.0 * juce::MathConstants<double>::pi;
        return sample;
    }

private:
    double frequency = 440.0;
    double sampleRate = 44100.0;
    double phase = 0.0;
    double phaseIncrement = 0.0;
};