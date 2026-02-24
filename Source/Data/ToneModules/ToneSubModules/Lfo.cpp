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
        angleDelta = 0;
        return;
    }


    auto cyclesPerSample = freq / sampleRate;
    angleDelta = cyclesPerSample * juce::MathConstants<double>::twoPi;
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

float Lfo::getAmplitude() const 
{ 
    return amplitude.getCurrentValue(); 
}

void Lfo::updateAngle() 
{ 
    angle += angleDelta; 
}
