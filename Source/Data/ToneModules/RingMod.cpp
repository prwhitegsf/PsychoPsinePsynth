/*
  ==============================================================================

    RmOsc.cpp
    Created: 16 Jan 2026 2:59:12pm
    Author:  User

  ==============================================================================
*/

#include "RingMod.h"


RingMod::RingMod()  {}

float RingMod::getNextSample(float carrierSample)
{
    process();

    auto depth = getOutputLevel();
    return (carrierSample * (1.0f - depth)) + (carrierSample * getSample() * depth);
}




