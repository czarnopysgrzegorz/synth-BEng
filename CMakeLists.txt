cmake_minimum_required(VERSION 3.15)
#creating project named Synth
project(Synth)

#connecting to submodule JUCE
add_subdirectory(JUCE)

#creating gui app
juce_add_gui_app(Synth)

# connecting src files
target_sources(SimpleSynth PRIVATE
    src/dsp/Oscillator.cpp
    src/gui/App.cpp
    src/synth/Synth.cpp
    src/main.cpp
)

# linking juce modules
target_link_libraries(SimpleSynth PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_devices
    juce::juce_audio_basics
    juce::juce_dsp
    juce::juce_gui_basics
)