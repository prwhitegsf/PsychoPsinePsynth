/*
  ==============================================================================

    Tone.cpp
    Created: 14 Jan 2026 7:40:43am
    Author:  User

  ==============================================================================
*/

#include "Tone.h"


void Tone::prepare(juce::dsp::ProcessSpec& spec)
{
    fm.prepare(spec);
    cr.prepare(spec);
    rm.prepare(spec);
}

void Tone::setFrequency(float currNoteHz)
{
    fm.setFrequency(currNoteHz);
    cr.setFrequency(currNoteHz);
    rm.setFrequency(currNoteHz);
} 

void Tone::noteOn()
{
    fm.adsr.noteOn();
    cr.adsr.noteOn();
    rm.adsr.noteOn();
}

void Tone::noteOff()
{
    fm.adsr.noteOff();
    cr.adsr.noteOff();
    rm.adsr.noteOff();
}

void Tone::reset()
{
    fm.reset();
    cr.reset();
    rm.reset();
}

bool Tone::isActive() const
{
    return cr.adsr.isActive();
}

float Tone::getNextSample(ToneLfos& toneLfo)
{
    return  rm.getNextSample(toneLfo.getRmTuneSample(),toneLfo.getRmDepthSample(),
                cr.getNextSample(toneLfo.getCrTuneSample(),toneLfo.getCrDepthSample(),
                    fm.getNextSample(toneLfo.getFmTuneSample(), toneLfo.getFmDepthSample())));
}

void Tone::updateCarrier(const float freqMult, const float tune,const float depth,
    const float attack, const float decay, const float sustain, const float release)
{
    cr.updateParameters(freqMult, tune, depth);
    cr.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
   // cr.tuneLfo.update(tuneLfoRate ? 1.0f / tuneLfoRate : 0.0f, tuneLfoAmp, tuneLfoHold);
   // cr.depthLfo.update(depthLfoRate ? 1.0f / depthLfoRate : 0.0f, depthLfoAmp, depthLfoHold);
}

void Tone::updateFreqMod(const float freqMult, const float tune, const float depth,
    const float attack, const float decay, const float sustain, const float release)
{
    fm.updateParameters(freqMult, tune, depth);
    fm.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
  //  fm.tuneLfo.update(tuneLfoRate ? 1.0f / tuneLfoRate : 0.0f, tuneLfoAmp, tuneLfoHold);
 //   fm.depthLfo.update(depthLfoRate ? 1.0f / depthLfoRate : 0.0f, depthLfoAmp, depthLfoHold);
}

void Tone::updateRingMod(const float freqMult,const float tune, const float depth,    
    const float attack, const float decay, const float sustain, const float release)
{
    rm.updateParameters(freqMult, tune, depth);
    rm.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
 //   rm.tuneLfo.update(tuneLfoRate ? 1.0f / tuneLfoRate : 0.0f, tuneLfoAmp, tuneLfoHold);
  //  rm.depthLfo.update(depthLfoRate ? 1.0f / depthLfoRate : 0.0f, depthLfoAmp, depthLfoHold);
}
/*
void Tone::updateCarrier(const float freqMult, 
    const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold, 
    const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
    const float attack, const float decay, const float sustain, const float release)
{
    cr.updateParameters(freqMult, tune, depth);
    cr.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
    cr.tuneLfo.update(tuneLfoRate ? 1.0f / tuneLfoRate : 0.0f, tuneLfoAmp, tuneLfoHold);
    cr.depthLfo.update(depthLfoRate ? 1.0f / depthLfoRate : 0.0f, depthLfoAmp, depthLfoHold);
}

void Tone::updateFreqMod(const float freqMult, 
    const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold, 
    const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold, 
    const float attack, const float decay, const float sustain, const float release)
{
    fm.updateParameters(freqMult, tune, depth);
    fm.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
    fm.tuneLfo.update(tuneLfoRate ? 1.0f / tuneLfoRate : 0.0f, tuneLfoAmp, tuneLfoHold);
    fm.depthLfo.update(depthLfoRate ? 1.0f / depthLfoRate : 0.0f, depthLfoAmp, depthLfoHold);
 }

void Tone::updateRingMod(const float freqMult, 
    const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
    const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
    const float attack, const float decay, const float sustain, const float release)
{
   rm.updateParameters(freqMult, tune, depth);
   rm.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
   rm.tuneLfo.update(tuneLfoRate ? 1.0f / tuneLfoRate : 0.0f, tuneLfoAmp, tuneLfoHold);
   rm.depthLfo.update(depthLfoRate ? 1.0f / depthLfoRate : 0.0f, depthLfoAmp, depthLfoHold);
}
*/
