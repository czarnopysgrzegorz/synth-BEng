cmake_minimum_required(VERSION 3.15)
#creating project named Synth
project(Synth VERSION 1.0.0)

#connecting to submodule JUCE
add_subdirectory(JUCE)

#creating gui app
juce_add_gui_app(Synth)

juce_generate_juce_header(Synth)

# connecting src files
target_sources(Synth PRIVATE
    src/dsp/Oscilator.cpp
    src/gui/App.cpp
    src/synth/Synth.cpp
    src/main.cpp
)
#adding include path
target_include_directories(Synth PRIVATE
    src
    src/dsp
    src/gui
    src/synth
)

# linking juce modules
target_link_libraries(Synth PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_devices
    juce::juce_audio_basics
    juce::juce_dsp
    juce::juce_gui_basics
)