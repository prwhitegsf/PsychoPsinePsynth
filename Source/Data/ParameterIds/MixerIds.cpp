/*
  ==============================================================================

    MixerIds.cpp
    Created: 28 Jan 2026 11:41:28am
    Author:  User

  ==============================================================================
*/

#include "MixerIds.h"


MixerIds::MixerIds(int index) : idx(juce::String(index))
{

    lpFreq = "LP_FREQ_" + idx;
    lpQ = "LP_Q_" + idx;
    hpFreq = "HP_FREQ_" + idx;
    hpQ = "HP_Q_" + idx;
    gain = "GAIN_" + idx;
    pan = "PAN_" + idx;
}
