/*
  ==============================================================================

    OscillatorIds.cpp
    Created: 28 Jan 2026 11:42:08am
    Author:  User

  ==============================================================================
*/

#include "OscillatorIds.h"



OscillatorIds::OscillatorIds(juce::String prefix, int idx)
{
    freqMult = prefix + "_FREQ_MULT_" + juce::String(idx);
    tune = prefix + "_TUNE_" + juce::String(idx);
    tuneLfoRate = prefix + "_TUNE_LFO_RATE_" + juce::String(idx);
    tuneLfoAmp = prefix + "_TUNE_LFO_AMP_" + juce::String(idx);
    tuneLfoHold = prefix + "_TUNE_LFO_HOLD_" + juce::String(idx);

    depth = prefix + "_DEPTH_" + juce::String(idx);
    depthLfoRate = prefix + "_DEPTH_LFO_RATE_" + juce::String(idx);
    depthLfoAmp = prefix + "_DEPTH_LFO_AMP_" + juce::String(idx);
    depthLfoHold = prefix + "_DEPTH_LFO_HOLD_" + juce::String(idx);

    attack = prefix + "_ATTACK_" + juce::String(idx);
    decay = prefix + "_DECAY_" + juce::String(idx);
    sustain = prefix + "_SUSTAIN_" + juce::String(idx);
    release = prefix + "_RELEASE_" + juce::String(idx);
}
