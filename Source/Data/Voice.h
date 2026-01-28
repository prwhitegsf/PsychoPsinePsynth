/*
  ==============================================================================

    Voice.h
    Created: 28 Jan 2026 11:37:03am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "ToneModules/Tone.h"


struct SynthSound : public juce::SynthesiserSound
{
    bool appliesToNote(int) override { return true; }
    bool appliesToChannel(int) override { return true; }
};

class Voice : public juce::SynthesiserVoice
{
public:
    explicit Voice(std::array<double, 128>& keyboard);

    bool canPlaySound(juce::SynthesiserSound* sound) override;

    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);

    void startNote(int midiNoteNumber, float/*velocity*/,
        juce::SynthesiserSound*, int /*currentPitchWheelPosition*/) override;

    void stopNote(float /*velocity*/, bool allowTailOff) override;

    void pitchWheelMoved(int) override {}
    void controllerMoved(int, int) override {}

    void renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

    void updateCarriers(int idx, const float freqMult,
        const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
        const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
        const float attack, const float decay, const float sustain, const float release);

    void updateFreqMods(int idx, const float freqMult,
        const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold, const float depth, const float depthLfoRate,
        const float depthLfoAmp, bool depthLfoHold, const float attack, const float decay, const float sustain, const float release);

    void updateRingMods(int idx, const float freqMult,
        const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
        const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
        const float attack, const float decay, const float sustain, const float release);


    bool allTonesOff();

    void clearActiveOffNotes();
    //private:

    std::array<double, 128>& kboard;

    std::array<Tone, 4> tones;
    float currNoteHz{};

    bool latched{ false };

    int numSamps{}, start{};

};

