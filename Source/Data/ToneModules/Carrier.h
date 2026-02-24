/*
  ==============================================================================

    Carrier.h
    Created: 12 Jan 2026 1:01:22pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ToneSubModules/OscillatorBase.h"

class Carrier : public OscillatorBase
{
public:

    float getNextSample(float tuneSample, float depthSample,float fmSample) override;

private:
    const float amplitudeScalar{ 0.03f };

};