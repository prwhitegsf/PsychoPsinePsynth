/*
  ==============================================================================

    Lfo.h
    Created: 14 Jan 2026 6:00:16am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Lfo
{

public:


    void prepare(const juce::dsp::ProcessSpec& spec);
    void reset();
    void update(const float frequency, const float amp, bool lfoHold);
    void setSample(juce::AudioSampleBuffer& wavetable);
    float getNextSample();
 
    float getAmplitude() const;

    bool isActive{ false };

private:


    juce::SmoothedValue<float> amplitude;
    
    float freq{}, sample{};
    double angle{}, angleDelta{}, sampleRate{ 44100.0 };

    const int tableSize = 127;
    float currentIndex = 0.0f, tableDelta = 0.0f;

};
