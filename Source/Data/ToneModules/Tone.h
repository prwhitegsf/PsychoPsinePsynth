/*
  ==============================================================================

    Tone.h
    Created: 14 Jan 2026 7:40:43am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Carrier.h"
#include "FreqMod.h"
#include "RingMod.h"
#include "ToneLfos.h"

class Tone
{

public:

    void prepare(juce::dsp::ProcessSpec& spec);
    void setFrequency(const float currNoteHz);
    
    void noteOn();
    void noteOff();
    void reset();
    
    bool isActive() const;

   
    float getNextSample(ToneLfos& toneLfos);
    
    void updateFreqMod(const float freqMult, const float tune, const float depth,        
        const float attack, const float decay, const float sustain, const float release);

    void updateCarrier(const float freqMult, const float tune, const float depth,
        const float attack, const float decay, const float sustain, const float release);

    void updateRingMod(const float freqMult, const float tune, const float depth,
        const float attack, const float decay, const float sustain, const float release);

  
   /* void updateCarrier(const float freqMult, 
        const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold, 
        const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
        const float attack, const float decay, const float sustain, const float release);

    void updateFreqMod(const float freqMult, 
        const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold, 
        const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold, 
        const float attack, const float decay, const float sustain, const float release);


    void updateRingMod(const float freqMult, 
        const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
        const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
        const float attack, const float decay, const float sustain, const float release);*/

    FreqMod fm;
    Carrier cr;
    RingMod rm;

};
