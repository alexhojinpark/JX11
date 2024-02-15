# Polyphonic Synthesizer using C++ and JUCE

This project is a polyphonic synthesizer developed using C++ and the JUCE framework.
Referred to the book **Creating Synthesizer Plug-Ins with C++ and JUCE**. The focus of this project was primarily on DSP and some aspects of UI.

## Features

- **Oscillators:** The core of the synthesizer, capable of generating basic waveforms with customable Tune, Fine, and Mix.
- **Glide:** Also known as portamento, this feature allows for a smooth pitch transition between notes, adding expressiveness to the performance.
- **Filters:** Includes Filter Freq, Reso, Env, LFO, Velocity, Attack, Decay, Sustain, and Release.
- **ADSR Envelopes:** Attack, Decay, Sustain, and Release envelopes provide dynamic control over the amplitude and filter cutoff, allowing for shaping the sound's temporal characteristics.
- **Polyphony & Voice Management:** Supports multiple simultaneous notes, enabling complex chords and textures. The voice management system efficiently allocates and deallocates voices as needed.

### Requirements

- JUCE Framework: Ensure you have the latest version of JUCE installed, which provides the necessary libraries and Projucer for project management.
- C++ Development Environment: A compatible compiler and development environment for C++ (such as Visual Studio, Xcode, or CLion).

### Building the Project

1. **Open Projucer:** Start by opening the `.jucer` project file with the Projucer application included with JUCE.
2. **Configure the Project:** Verify the project settings, including the paths to the JUCE modules and your preferred compiler.
3. **Save and Open in IDE:** Use Projucer to generate the project files for your IDE and open them in your development environment.
4. **Compile:** Build the project from your IDE, which should result in a standalone application or plugin, depending on the project configuration.
