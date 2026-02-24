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

    void process(float tuneSample, float depthSample);
    void process(float tuneSample, float depthSample, const float fmSample);

    forcedinline float getSample() const { return sample; }
    forcedinline float getFreq() const { return freq; }
    forcedinline float getOutputLevel() const { return outputLevel; }

    virtual float getNextSample(float tuneSample, float depthSample);
    virtual float getNextSample(float tuneSample, float depthSample, float sample);
    
    juce::ADSR adsr;

private:
    void setSample();
    void updateAngle(const float tuneSample);
    void updateAngle(const float tuneSample, const float fmSample);
    void setOutputLevel(const float depthSample);

    juce::SmoothedValue<float> offsetHz;
    juce::SmoothedValue<float> amplitude;

   // const double twoPi = 2.0 * juce::MathConstants<double>::pi;
    
    float  outputLevel{};
    float frequencyMultiple{ 1.0f };
    float freq{}, noteHz{}, sample{};
    double angle{}, angleDelta{}, sampleRate{ 44100.0 };
};
