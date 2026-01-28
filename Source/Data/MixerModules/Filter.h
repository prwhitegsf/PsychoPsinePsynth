/*
  ==============================================================================

    Filter.h
    Created: 16 Jan 2026 10:43:57am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Filter : public juce::dsp::LadderFilter<float>
{
   
public:
    float getNextSample(float sample);
 
  };

