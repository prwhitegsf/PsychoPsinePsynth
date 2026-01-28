/*
  ==============================================================================

    Mixer.h
    Created: 15 Jan 2026 1:00:24pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Filter.h"

class Mixer
{
public:
    Mixer();

    void update(const float lpFreq, const float lpQ, const float hpFreq, const float hpQ, const float gain, const float pan);
    void prepare(juce::dsp::ProcessSpec& spec);
    std::pair<float, float> getNextLeftAndRightSamples(const float toneSample);
    
    
private:
    juce::SmoothedValue<float> level, leftGain, rightGain;
    Filter lowPass, highPass;
   
    void updateLevel(const float gain);
    void updatePan(const float pan);
    void updateFilter(const float lpFreq, const float lpQ, const float hpFreq, const float hpQ);
   

};
