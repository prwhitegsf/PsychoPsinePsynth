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
    
    if (!frequency || lfoHold)
    {
        isActive = false;
        return;
    }

    isActive = true;

    auto cyclesPerSample = freq / sampleRate;
    angleDelta = cyclesPerSample * twoPi;
}

void Lfo::setSample()
{
    sample = (float)(std::sin(angle));

    updateAngle();
}


void Lfo::reset()
{
    angleDelta = 0;
}

float Lfo::getNextSample()
{
   return sample * amplitude.getNextValue();
}
