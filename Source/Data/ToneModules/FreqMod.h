/*
  ==============================================================================

    FmOsc.h
    Created: 14 Jan 2026 9:21:57am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ToneSubModules/OscillatorBase.h"

class FreqMod : public OscillatorBase
{
public:
    FreqMod();

      float getNextSample(float tuneSample, float depthSample) override;


};
