/*
  ==============================================================================

    OscillatorIds.h
    Created: 28 Jan 2026 11:42:08am
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class OscillatorIds
{
public:
    OscillatorIds() = default;
    OscillatorIds(juce::String prefix, int idx);

    juce::String freqMult;
    juce::String tune;
    juce::String tuneLfoRate;
    juce::String tuneLfoAmp;
    juce::String tuneLfoHold;

    juce::String depth;
    juce::String depthLfoRate;
    juce::String depthLfoAmp;
    juce::String depthLfoHold;

    juce::String attack;
    juce::String decay;
    juce::String sustain;
    juce::String release;
};
