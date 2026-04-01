# synth-BEng
Synthesizer app for my Engineering Thesis

# How to run
First you have to download the JUCE repo:

git submodule add https://github.com/juce-framework/JUCE.git

Build commands:

rm -rf build
mkdir build
cd build
cmake ..
cmake --build .

If any changes happen in the code just type 

cmake --build .

If any changes happen to the structure (JUCE folder or CMakeLists.txt)

mkdir build
cd build
cmake ..
cmake --build .

