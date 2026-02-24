/*
  ==============================================================================

    FmOsc.cpp
    Created: 14 Jan 2026 9:21:57am
    Author:  User

  ==============================================================================
*/

#include "FreqMod.h"

float FreqMod::getNextSample(float tuneSample, float depthSample)
{
    process(tuneSample,depthSample);
    
    auto fmIndex = (getFreq() + tuneSample) * getOutputLevel();

    return getSample() * fmIndex;   
}



