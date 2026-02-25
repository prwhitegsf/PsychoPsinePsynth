/*
  ==============================================================================

    ToneLfos.cpp
    Created: 22 Feb 2026 9:11:40am
    Author:  User

  ==============================================================================
*/

#include "ToneLfos.h"

ToneLfos::ToneLfos(std::array<juce::AudioSampleBuffer,1>& wt)
    : fmTuneLfo(wt),
    fmDepthLfo(wt),
    crTuneLfo(wt),
    crDepthLfo(wt),
    rmTuneLfo(wt),
    rmDepthLfo(wt)
{ }

void ToneLfos::prepare(const juce::dsp::ProcessSpec& spec)
{
    fmTuneLfo.prepare(spec);
    fmDepthLfo.prepare(spec);
   
    crTuneLfo.prepare(spec);
    crDepthLfo.prepare(spec);
   
    rmTuneLfo.prepare(spec);
    rmDepthLfo.prepare(spec);
}


void ToneLfos::updateLfos(const float fmTuneRate, const float fmTuneAmp, const bool fmTuneHold,
    const float fmDepthRate, const float fmDepthAmp, const bool fmDepthHold,
    const float crTuneRate, const float crTuneAmp, const bool crTuneHold,
    const float crDepthRate, const float crDepthAmp, const bool crDepthHold,
    const float rmTuneRate, const float rmTuneAmp, const bool rmTuneHold,
    const float rmDepthRate, const float rmDepthAmp, const bool rmDepthHold)
{
    fmTuneLfo.update(fmTuneRate ? 1.0f / fmTuneRate : 0.0f, fmTuneAmp, fmTuneHold);
    fmDepthLfo.update(fmDepthRate ? 1.0f / fmDepthRate : 0.0f, fmDepthAmp, fmDepthHold);
   
    crTuneLfo.update(crTuneRate ? 1.0f / crTuneRate : 0.0f, crTuneAmp, crTuneHold);
    crDepthLfo.update(crDepthRate ? 1.0f / crDepthRate : 0.0f, crDepthAmp, crDepthHold);
    
    rmTuneLfo.update(rmTuneRate ? 1.0f / rmTuneRate : 0.0f, rmTuneAmp, rmTuneHold);
    rmDepthLfo.update(rmDepthRate ? 1.0f / rmDepthRate : 0.0f, rmDepthAmp, rmDepthHold);
}

void ToneLfos::setSamples()
{
    fmTuneLfo.setSample();
    fmDepthLfo.setSample();
   
    crTuneLfo.setSample();
    crDepthLfo.setSample();
   
    rmTuneLfo.setSample();
    rmDepthLfo.setSample();
}

float ToneLfos::getFmTuneSample() 
{
    return fmTuneLfo.getNextSample();
}

float ToneLfos::getFmDepthSample() 
{
    auto depth = (fmDepthLfo.getNextSample() + 1.0f) / 2.0f;
    auto amp = fmDepthLfo.getAmplitude();
    return (1.0f - amp) + (depth * amp);
}

float ToneLfos::getCrTuneSample() 
{
    return crTuneLfo.getNextSample();
}

float ToneLfos::getCrDepthSample() 
{
    auto depth = (crDepthLfo.getNextSample() + 1.0f) / 2.0f;
    auto amp = crDepthLfo.getAmplitude();
    return (1.0f - amp) + (depth * amp);
}

float ToneLfos::getRmTuneSample() 
{
    return rmTuneLfo.getNextSample();
}

float ToneLfos::getRmDepthSample() 
{
    auto depth = (rmDepthLfo.getNextSample() + 1.0f) / 2.0f;
    auto amp = rmDepthLfo.getAmplitude();
    return (1.0f - amp) + (depth * amp);
}
