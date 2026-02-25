/*
  ==============================================================================

    Wavetable.cpp
    Created: 25 Feb 2026 12:04:54pm
    Author:  User

  ==============================================================================
*/

#include "Wavetable.h"

Wavetable::Wavetable(juce::AudioSampleBuffer& wavetableToUse)
    : wavetable(wavetableToUse), tableSize(128)//(wavetable.getNumSamples() - 1)
{
}

void Wavetable::setFrequency(float frequency, float sampleRate)
{
    auto tableSizeOverSampleRate = (float)tableSize / sampleRate;
    tableDelta = frequency * tableSizeOverSampleRate;
}

float Wavetable::getNextSample() noexcept
{
    auto index0 = (unsigned int)currentIndex;
    auto index1 = index0 + 1;
    auto frac = currentIndex - (float)index0;

    auto* table = wavetable.getReadPointer(0);
    auto value0 = table[index0];
    auto value1 = table[index1];

    auto currentSample = value0 + frac * (value1 - value0);

    if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;

    return currentSample;
}
