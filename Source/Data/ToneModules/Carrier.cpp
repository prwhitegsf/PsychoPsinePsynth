/*
  ==============================================================================

    Carrier.cpp
    Created: 12 Jan 2026 1:01:22pm
    Author:  User

  ==============================================================================
*/

#include "Carrier.h"

float Carrier::getNextSample(float tuneSample, float depthSample, float fmSample)
{
    process(tuneSample, depthSample,fmSample);
    
    return  getSample() * getOutputLevel() * amplitudeScalar;
}



