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

    Lfo();

    void prepare(const juce::dsp::ProcessSpec& spec);
    void update(const float frequency, const float amp, bool lfoHold);
    void setSample(juce::AudioSampleBuffer& wavetable);
    
    float getNextSample();
    float getAmplitude() const;

   
private:
    bool isActive{ false };

    juce::SmoothedValue<float> amplitude;
    float freq, sample, sampleRate;
    float currentIndex, tableDelta, angleDelta;

    const int tableSize;

};
