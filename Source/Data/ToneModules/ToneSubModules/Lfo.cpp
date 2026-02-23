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
    //if (!frequency || lfoHold)
    {
        isActive = false;
        return;
    }

    isActive = true;

    auto cyclesPerSample = freq / sampleRate;
    angleDelta = cyclesPerSample * juce::MathConstants<double>::twoPi;
}

void Lfo::setSample()
{
    // incorporating amplitude here messes up depth Lfo calcs
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

float Lfo::getAmplitude() const 
{ 
    return amplitude.getCurrentValue(); 
}

void Lfo::updateAngle() 
{ 
    angle += angleDelta; 
}
