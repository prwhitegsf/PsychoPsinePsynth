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

float Tone::getNextSample(ToneLfos& toneLfo, juce::AudioSampleBuffer& wavetable)
{
    return  rm.getNextSample(wavetable, toneLfo.getRmTuneSample(),toneLfo.getRmDepthSample(),
                cr.getNextSample(wavetable, toneLfo.getCrTuneSample(),toneLfo.getCrDepthSample(),
                    fm.getNextSample(wavetable, toneLfo.getFmTuneSample(), toneLfo.getFmDepthSample())));
}

void Tone::updateCarrier(const float freqMult, const float tune,const float depth,
    const float attack, const float decay, const float sustain, const float release)
{
    cr.updateParameters(freqMult, tune, depth);
    cr.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
}

void Tone::updateFreqMod(const float freqMult, const float tune, const float depth,
    const float attack, const float decay, const float sustain, const float release)
{
    fm.updateParameters(freqMult, tune, depth);
    fm.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
}

void Tone::updateRingMod(const float freqMult, const float tune, const float depth,
    const float attack, const float decay, const float sustain, const float release)
{
    rm.updateParameters(freqMult, tune, depth);
    rm.adsr.setParameters(juce::ADSR::Parameters(attack, decay, sustain, release));
}
