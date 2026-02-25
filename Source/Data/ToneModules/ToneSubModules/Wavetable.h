/*
  ==============================================================================

    Wavetable.h
    Created: 25 Feb 2026 12:04:54pm
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Wavetable
{
public:
    Wavetable(juce::AudioSampleBuffer& wavetableToUse);

    void setFrequency(float frequency, float sampleRate);
   
    float getNextSample() noexcept;
   
private:
    juce::AudioSampleBuffer& wavetable;
    const int tableSize;
    float currentIndex = 0.0f, tableDelta = 0.0f;
};
