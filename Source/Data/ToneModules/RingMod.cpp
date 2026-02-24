/*
  ==============================================================================

    RmOsc.cpp
    Created: 16 Jan 2026 2:59:12pm
    Author:  User

  ==============================================================================
*/

#include "RingMod.h"



float RingMod::getNextSample(float tuneSample, float depthSample, float carrierSample)
{
    process(tuneSample, depthSample);

    auto depth = getOutputLevel();
    return (carrierSample * (1.0f - depth)) + (carrierSample * getSample() * depth);
}




