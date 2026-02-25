/*
  ==============================================================================

    AudioEngine.cpp
    Created: 28 Jan 2026 11:36:50am
    Author:  User

  ==============================================================================
*/

#include "AudioEngine.h"


AudioEngine::AudioEngine() 
    : tempBuff(1, 1)
{
    createWavetables();
    addSound(new SynthSound());

    setNoteStealingEnabled(false);

    for (int i = 0; i < numVoices; ++i)
    {
        addVoice(new Voice(keyboard, toneLfos));
    }
}

void AudioEngine::createWavetables()
{

    // Create sine wave in first slot
    wavetables[0].setSize(1, (int)tableSize + 1);
    wavetables[0].clear();

    auto* samples = wavetables[0].getWritePointer(0);
 
    auto angleDelta = juce::MathConstants<double>::twoPi / (double)(tableSize - 1);
    auto currentAngle = 0.0;

    for (unsigned int i{}; i < tableSize; ++i)
    {
        auto sample = std::sin(currentAngle);
        samples[i] += (float)sample;
        currentAngle += angleDelta;
    }       

    samples[tableSize] = samples[0];
}

void AudioEngine::updateMixers(int idx, const float lpFreq, const float lpQ,
    const float hpFreq, const float hpQ, const float gain, const float pan)
{
    mixers[idx].update(lpFreq, lpQ, hpFreq, hpQ, gain, pan);
}


void AudioEngine::renderVoices(juce::AudioBuffer<float>& buffer, int startSample, int numSamples)
{
    while (--numSamples >= 0)
    {
        for (int i{}; i < 4; ++i)
        {
            tempBuff.clear();

            // Set Lfos
            toneLfos[i].setSamples();
         
            for (auto* voice : voices)
            {
                
                // add all the notes played on a single tone module into the single sample tempBuff
                voice->renderNextBlock(tempBuff, 0, i);

            }

            // read the sample we just made from all the voices on this single tone,
            const float toneSample = *tempBuff.getReadPointer(0, 0);

            // apply filters, gain and pan
            const auto [left, right] = mixers[i].getNextLeftAndRightSamples(toneSample);

            buffer.addSample(1, startSample, right);
            buffer.addSample(0, startSample, left);
        }

        ++startSample;
    }

}
