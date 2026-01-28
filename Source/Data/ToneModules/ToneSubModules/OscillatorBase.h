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

    void process();
    void process(const float fmSample);

    inline float getSample() const { return sample; }
    inline float getFreq() const { return freq; }
    inline float getOutputLevel() const { return outputLevel; }

    virtual float getNextSample();
    virtual float getNextSample(float sample);
    
    Lfo tuneLfo;
    Lfo depthLfo;
    juce::ADSR adsr;

private:
    void setSample();
    void updateAngle();
    void updateAngle(const float fmSample);
    void setOutputLevel();

    juce::SmoothedValue<float> offsetHz;
    juce::SmoothedValue<float> amplitude;

    const double twoPi = 2.0 * juce::MathConstants<double>::pi;
    
    float  outputLevel{};
    float frequencyMultiple{ 1.0 };
    float freq{}, noteHz{}, sample{};
    double angle{}, angleDelta{}, sampleRate{ 44100.0 };
};
