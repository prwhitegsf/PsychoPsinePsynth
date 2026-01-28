/*
  ==============================================================================

    Carrier.cpp
    Created: 12 Jan 2026 1:01:22pm
    Author:  User

  ==============================================================================
*/

#include "Carrier.h"

Carrier::Carrier() {}


float Carrier::getNextSample(float fmSample)
{
    process(fmSample);
    
    return  getSample() * getOutputLevel() * amplitudeScalar;
}



