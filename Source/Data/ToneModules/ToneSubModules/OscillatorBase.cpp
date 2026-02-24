/*
  ==============================================================================

    OscillatorBase.cpp
    Created: 24 Jan 2026 3:39:36pm
    Author:  User

  ==============================================================================
*/

#include "OscillatorBase.h"

OscillatorBase::OscillatorBase() {}


void OscillatorBase::prepare(const juce::dsp::ProcessSpec& spec)
{
    sampleRate = spec.sampleRate;
    
    offsetHz.reset(spec.sampleRate, 0.05);
    amplitude.reset(spec.sampleRate, 0.05);
    
    adsr.setSampleRate(spec.sampleRate);
}

void OscillatorBase::setFrequency(const float frequency)
{
    angle = 0.0;
    noteHz = frequency;
    freq = noteHz * frequencyMultiple;
    auto cyclesPerSample = freq / sampleRate;
    angleDelta = cyclesPerSample * juce::MathConstants<double>::twoPi;
}

void OscillatorBase::updateParameters(const float freqMult, const float tune, const float amp)
{
    frequencyMultiple = freqMult;
    freq = noteHz * freqMult;
    offsetHz.setTargetValue(tune);
    amplitude.setTargetValue(amp);
}
 
void  OscillatorBase::process(float tuneSample, float depthSample)
{
    setSample();
    updateAngle(tuneSample);
    setOutputLevel(depthSample);
}
    
void  OscillatorBase::process(float tuneSample, float depthSample,const float fmSample)
{
    setSample();
    updateAngle(tuneSample,fmSample);
    setOutputLevel(depthSample);
}


void OscillatorBase::reset()
{
    angleDelta = 0;
    adsr.reset();
}



void OscillatorBase::setOutputLevel(const float depthSample)
{   
    outputLevel = depthSample * amplitude.getNextValue() * adsr.getNextSample();
}


float OscillatorBase::getNextSample(float tuneSample, float depthSample)
{
    process(tuneSample, depthSample);

    return getSample() * getOutputLevel();
}


float OscillatorBase::getNextSample(float tuneSample, float depthSample, float fmSample)
{
    process(tuneSample, depthSample,fmSample);

    return getSample() * getOutputLevel();
}

void OscillatorBase::setSample()
{
    sample = (float)(std::sin(angle));
}


void OscillatorBase::updateAngle(const float tuneSample)
{
    angleDelta = ((freq + tuneSample + offsetHz.getNextValue()) / sampleRate) * juce::MathConstants<double>::twoPi;
    angle += angleDelta;
}

void OscillatorBase::updateAngle(const float tuneSample, const float fmSample)
{
    angleDelta = ((freq + tuneSample + fmSample + offsetHz.getNextValue()) / sampleRate) * juce::MathConstants<double>::twoPi;
    angle += angleDelta;
}
