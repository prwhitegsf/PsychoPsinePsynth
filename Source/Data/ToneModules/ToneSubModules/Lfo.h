/*
  ==============================================================================

    Lfo.h
    Created: 14 Jan 2026 6:00:16am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Wavetable.h"

class Lfo
{

public:

    Lfo(std::array<juce::AudioSampleBuffer,1>& wt);

    void prepare(const juce::dsp::ProcessSpec& spec);
    void reset();
    void update(const float frequency, const float amp, bool lfoHold);
    void setSample();
    float getNextSample();
 
    float getAmplitude() const;

    bool isActive{ false };

private:

    std::array<juce::AudioSampleBuffer, 1>& wavetables;
    Wavetable wavetable;
    void updateAngle();

    juce::SmoothedValue<float> amplitude;
    
    float freq{}, sample{};
    double angle{}, angleDelta{}, sampleRate{ 44100.0 };

};
