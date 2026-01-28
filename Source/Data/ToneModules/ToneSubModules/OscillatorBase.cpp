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
    tuneLfo.prepare(spec);
    depthLfo.prepare(spec);

}

void OscillatorBase::setFrequency(const float frequency)
{
    angle = 0.0;
    noteHz = frequency;
    freq = noteHz * frequencyMultiple;
    auto cyclesPerSample = frequency / sampleRate;
    angleDelta = cyclesPerSample * twoPi;
}

void OscillatorBase::updateParameters(const float freqMult, const float tune, const float amp)
{
    frequencyMultiple = freqMult;
    freq = noteHz * freqMult;
    offsetHz.setTargetValue(tune);
    amplitude.setTargetValue(amp);
}
 
void  OscillatorBase::process()
{
    setSample();
    updateAngle();
    setOutputLevel();
}
    
void  OscillatorBase::process(const float fmSample) 
{
    setSample();
    updateAngle(fmSample);
    setOutputLevel();
}


void OscillatorBase::reset()
{
    angleDelta = 0;
    tuneLfo.reset();
    depthLfo.reset();
    adsr.reset();
}



void OscillatorBase::setOutputLevel()
{
    if (depthLfo.isActive)
        depthLfo.setSample();

    auto depth = (depthLfo.getNextSample() + 1.0f) / 2.0f;
    auto amp = depthLfo.getAmplitude();
    outputLevel = ((1.0f - amp) + (depth * amp)) * amplitude.getNextValue() * adsr.getNextSample();
}


float OscillatorBase::getNextSample()
{
    process();

    return getSample() * getOutputLevel();
}
float OscillatorBase::getNextSample(float fmSample)
{
    process(fmSample);

    return getSample() * getOutputLevel();
}
void OscillatorBase::setSample()
{
    sample = angle == 0 ? 0 : (float)(std::sin(angle));
}


void OscillatorBase::updateAngle()
{
    if (tuneLfo.isActive)
        tuneLfo.setSample();

    angleDelta = ((freq + tuneLfo.getNextSample() + offsetHz.getNextValue()) / sampleRate) * twoPi;
    angle += angleDelta;
}

void OscillatorBase::updateAngle(const float fmSample)
{

    if (tuneLfo.isActive)
        tuneLfo.setSample();

    angleDelta = ((freq + tuneLfo.getNextSample() + fmSample + offsetHz.getNextValue()) / sampleRate) * twoPi;
    angle += angleDelta;
}
