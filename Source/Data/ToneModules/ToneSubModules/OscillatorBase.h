/*
  ==============================================================================

    OscillatorBase.h
    Created: 24 Jan 2026 3:39:36pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Lfo.h"

class OscillatorBase
{
public:
    OscillatorBase();
    virtual ~OscillatorBase() = default;

    void prepare(const juce::dsp::ProcessSpec& spec);
    void setFrequency(const float frequency);
    void updateParameters(const float freqMult, const float tune, const float amp);
    void reset();

    void process(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample);
    void process(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample, const float fmSample);

    forcedinline float getSample() const { return sample; }
    forcedinline float getFreq() const { return freq; }
    forcedinline float getOutputLevel() const { return outputLevel; }

    virtual float getNextSample(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample);
    virtual float getNextSample(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample, float sample);
    
    juce::ADSR adsr;

private:
    void setSample();
    void setSample(juce::AudioSampleBuffer& wavetable);
    void updateAngle(const float tuneSample);
    void updateAngle(const float tuneSample, const float fmSample);
    void setOutputLevel(const float depthSample);

    juce::SmoothedValue<float> offsetHz;
    juce::SmoothedValue<float> amplitude;

    
    float  outputLevel{};
    float frequencyMultiple{ 1.0f };
    float freq{}, noteHz{}, sample{};
    double angle{}, angleDelta{}, sampleRate{ 44100.0 };

    const int tableSize = 127;
    float currentIndex = 0.0f, tableDelta = 0.0f;

};
