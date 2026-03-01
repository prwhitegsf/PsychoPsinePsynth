/*
  ==============================================================================

    FmOsc.cpp
    Created: 14 Jan 2026 9:21:57am
    Author:  User

  ==============================================================================
*/

#include "FreqMod.h"

float FreqMod::getNextSample(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample)
{
    process(wavetable, tuneSample,depthSample);
    
    auto fmIndex = (getFreq() + tuneSample) * getOutputLevel();

    return getSample() * fmIndex;   
}



