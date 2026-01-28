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

    Carrier();

    float getNextSample(float sample) override;

private:
    const float amplitudeScalar{ 0.03f };

};