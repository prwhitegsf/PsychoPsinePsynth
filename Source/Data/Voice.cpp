/*
  ==============================================================================

    Voice.cpp
    Created: 28 Jan 2026 11:37:03am
    Author:  User

  ==============================================================================
*/

#include "Voice.h"



Voice::Voice(std::array<double, 128>& keyboard) : kboard(keyboard)
{
}

bool Voice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<SynthSound*> (sound) != nullptr;
}

void Voice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels)
{
    juce::dsp::ProcessSpec spec{ sampleRate,(std::uint_fast32_t)samplesPerBlock,(std::uint_fast32_t)outputChannels };

    for (auto& tone : tones)
    {
        tone.prepare(spec);
    }
}

void Voice::startNote(int midiNoteNumber, float, juce::SynthesiserSound*, int)
{
    currNoteHz = (float)kboard[midiNoteNumber];
    for (auto& tone : tones)
    {
        tone.setFrequency(currNoteHz);
        tone.noteOn();
    }
}

void Voice::stopNote(float, bool allowTailOff)
{
    for (auto& tone : tones)
    {
        tone.noteOff();
    }

    if (!allowTailOff || allTonesOff())
    {
        clearCurrentNote();
        for (auto& tone : tones)
        {
            tone.reset();
        }
    }
}

void Voice::renderNextBlock(juce::AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    outputBuffer.addSample(0, startSample, tones[numSamples].getNextSample());
}

void Voice::updateCarriers(int idx, const float freqMult,
    const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
    const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
    const float attack, const float decay, const float sustain, const float release)
{
    tones[idx].updateCarrier(
        freqMult, tune, tuneLfoRate, tuneLfoAmp, tuneLfoHold,
        depth, depthLfoRate, depthLfoAmp, depthLfoHold,
        attack, decay, sustain, release);

}

void Voice::updateFreqMods(int idx, const float freqMult,
    const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
    const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
    const float attack, const float decay, const float sustain, const float release)
{
    tones[idx].updateFreqMod(
        freqMult, tune, tuneLfoRate, tuneLfoAmp, tuneLfoHold, depth, depthLfoRate,
        depthLfoAmp, depthLfoHold, attack, decay, sustain, release);

}

void Voice::updateRingMods(int idx, const float freqMult,
    const float tune, const float tuneLfoRate, const float tuneLfoAmp, bool tuneLfoHold,
    const float depth, const float depthLfoRate, const float depthLfoAmp, bool depthLfoHold,
    const float attack, const float decay, const float sustain, const float release)
{
    tones[idx].updateRingMod(
        freqMult, tune, tuneLfoRate, tuneLfoAmp, tuneLfoHold,
        depth, depthLfoRate, depthLfoAmp, depthLfoHold,
        attack, decay, sustain, release);

}

bool Voice::allTonesOff()
{
    for (auto& tone : tones)
        if (tone.isActive())
            return false;

    return true;
}

void Voice::clearActiveOffNotes()
{
    if (isVoiceActive() && allTonesOff())
    {
        clearCurrentNote();
        return;
    }

}
