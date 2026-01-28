/*
  ==============================================================================

    Mixer.cpp
    Created: 15 Jan 2026 1:00:24pm
    Author:  User

  ==============================================================================
*/

#include "Mixer.h"




Mixer::Mixer()
{
    lowPass.setMode(juce::dsp::LadderFilterMode::LPF24);
    highPass.setMode(juce::dsp::LadderFilterMode::HPF24);
}

void Mixer::prepare(juce::dsp::ProcessSpec& spec)
{
    lowPass.prepare(spec);
    highPass.prepare(spec);

    level.reset(spec.sampleRate, 0.05);
    leftGain.reset(spec.sampleRate, 0.05);
    rightGain.reset(spec.sampleRate, 0.05);
}

void Mixer::updateFilter(const float lpFreq, const float lpQ, const float hpFreq, const float hpQ)
{
    lowPass.setCutoffFrequencyHz(lpFreq);
    lowPass.setResonance(lpQ);
    
    highPass.setCutoffFrequencyHz(hpFreq);
    highPass.setResonance(hpQ);
}



std::pair<float, float> Mixer::getNextLeftAndRightSamples(const float toneSample)
{
    auto mixed = level.getNextValue() * highPass.getNextSample(lowPass.getNextSample(toneSample));
    return {mixed * leftGain.getNextValue(), mixed * rightGain.getNextValue()};
}


void Mixer::update(const float lpFreq, const float lpQ, const float hpFreq, const float hpQ, float gain, float pan)
{
    updateFilter(lpFreq, lpQ, hpFreq,hpQ);
    updateLevel(gain);
    updatePan(pan);
}


void Mixer::updateLevel(const float gain)
{
    level.setTargetValue(gain);
}

void Mixer::updatePan(const float pan)
{
    leftGain.setTargetValue(0.5f * (1.0f - pan));
    rightGain.setTargetValue(0.5f * (1.0f + pan));
}
