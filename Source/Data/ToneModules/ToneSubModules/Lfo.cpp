/*
  ==============================================================================

    Lfo.cpp
    Created: 14 Jan 2026 6:00:16am
    Author:  User

  ==============================================================================
*/

#include "Lfo.h"


void Lfo::prepare(const juce::dsp::ProcessSpec& spec)
{
    sampleRate = spec.sampleRate;
   
}

void Lfo::update(const float frequency, const float amp, bool lfoHold)
{
    amplitude.setTargetValue(amp);
    freq = frequency;
    
    if (lfoHold)
    {
        isActive = false;
        return;
    }

    isActive = true;
    
    auto tableSizeOverSampleRate = (float)tableSize / sampleRate;
    tableDelta = frequency * tableSizeOverSampleRate;
}


void Lfo::setSample(juce::AudioSampleBuffer& wavetable)
{
    if (!isActive)
        return;

    auto index0 = (unsigned int)currentIndex;
    auto index1 = index0 + 1;
    auto frac = currentIndex - (float)index0;

    auto* table = wavetable.getReadPointer(0);
    auto value0 = table[index0];
    auto value1 = table[index1];

    sample = value0 + frac * (value1 - value0);

    if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;
}


void Lfo::reset()
{
    angleDelta = 0;
}

float Lfo::getNextSample() 
{
    return sample * amplitude.getNextValue();
}

float Lfo::getAmplitude() const 
{ 
    return amplitude.getCurrentValue(); 
}

