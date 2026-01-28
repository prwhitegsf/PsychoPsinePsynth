/*
  ==============================================================================

    MixerIds.h
    Created: 28 Jan 2026 11:41:28am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>


class MixerIds
{
public:
    MixerIds(int index);

    juce::String idx;

    juce::String lpFreq;
    juce::String lpQ;
    juce::String hpFreq;
    juce::String hpQ;
    juce::String gain;
    juce::String pan;
};
