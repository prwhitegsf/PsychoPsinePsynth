/*
  ==============================================================================

    FmOsc.cpp
    Created: 14 Jan 2026 9:21:57am
    Author:  User

  ==============================================================================
*/

#include "FreqMod.h"


FreqMod::FreqMod(){}

float FreqMod::getNextSample()
{
    process();
    
    auto fmIndex = (getFreq() + tuneLfo.getNextSample()) * getOutputLevel();

    return getSample() * fmIndex;   
}



