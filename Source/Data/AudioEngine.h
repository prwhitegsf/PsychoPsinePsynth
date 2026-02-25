/*
  ==============================================================================

    AudioEngine.h
    Created: 28 Jan 2026 11:36:50am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "MixerModules/Mixer.h"
#include "Voice.h"

class AudioEngine : public juce::Synthesiser
{
public:
    AudioEngine();

private:
    std::array<juce::AudioSampleBuffer, 1> wavetables;


public:
    std::array<double, 128> keyboard;
    std::array<ToneLfos, 4> toneLfos;
    std::array<Mixer, 4> mixers;
    
    void renderVoices(juce::AudioBuffer<float>& buffer, int startSample, int numSamples) override;

  
    void updateMixers(int idx, const float lpFreq, const float lpQ,
        const float hpFreq, const float hpQ, const float gain, const float pan);


private:
    static const int numVoices = 8;
    juce::AudioBuffer<float> tempBuff;

};

