/*
  ==============================================================================

    RmOsc.h
    Created: 16 Jan 2026 2:59:12pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ToneSubModules/OscillatorBase.h"

class RingMod : public OscillatorBase
{
public:
    RingMod();

     float getNextSample(float sample) override;


};
