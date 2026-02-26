/*
  ==============================================================================

    ToneLfos.h
    Created: 22 Feb 2026 9:11:40am
    Author:  User

  ==============================================================================
*/

#pragma once
#include "ToneSubModules/Lfo.h"



class ToneLfos
{

public:


    void prepare(const juce::dsp::ProcessSpec& spec);

    void updateLfos(
        const float fmTuneRate,  const float fmTuneAmp,  const bool fmTuneHold,
        const float fmDepthRate, const float fmDepthAmp, const bool fmDepthHold,
        const float crTuneRate,  const float crTuneAmp,  const bool crTuneHold,
        const float crDepthRate, const float crDepthAmp, const bool crDepthHold,
        const float rmTuneRate,  const float rmTuneAmp,  const bool rmTuneHold,
        const float rmDepthRate, const float rmDepthAmp, const bool rmDepthHold);
    
    void setSamples(juce::AudioSampleBuffer& wavetable);

    float getFmTuneSample();
    float getFmDepthSample();
    
    float getCrTuneSample();
    float getCrDepthSample();

    float getRmTuneSample();
    float getRmDepthSample();


private:
    Lfo fmTuneLfo;
    Lfo fmDepthLfo;
    Lfo crTuneLfo;
    Lfo crDepthLfo;
    Lfo rmTuneLfo;
    Lfo rmDepthLfo;
 

  

};
