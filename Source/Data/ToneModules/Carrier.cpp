/*
  ==============================================================================

    Carrier.cpp
    Created: 12 Jan 2026 1:01:22pm
    Author:  User

  ==============================================================================
*/

#include "Carrier.h"

float Carrier::getNextSample(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample, float fmSample)
{
    process(wavetable, tuneSample, depthSample,fmSample);
    
    return  getSample() * getOutputLevel() * amplitudeScalar;
}



