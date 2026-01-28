/*
  ==============================================================================

    Lfo.h
    Created: 14 Jan 2026 6:00:16am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Lfo
{

public:


    void prepare(const juce::dsp::ProcessSpec& spec);
    void reset();
    void update(const float frequency, const float amp, bool lfoHold);
    void setSample();
    float getNextSample();
 
    inline float getAmplitude() const { return amplitude.getCurrentValue(); }

    bool isActive{ false };

private:

    inline void updateAngle() { angle += angleDelta; }

    const double twoPi = 2.0 * juce::MathConstants<double>::pi;
    juce::SmoothedValue<float> amplitude;
    
    float freq{}, sample{};
    double angle{}, angleDelta{}, sampleRate{ 44100.0 };

};
