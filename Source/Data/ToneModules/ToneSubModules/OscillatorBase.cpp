/*
  ==============================================================================

    OscillatorBase.cpp
    Created: 24 Jan 2026 3:39:36pm
    Author:  User

  ==============================================================================
*/

#include "OscillatorBase.h"

OscillatorBase::OscillatorBase() 
: outputLevel(0.0f), 
  freqMult(1.0f), freq(0.0f), noteHz(0.0f),
  sample (0.0f), sampleRate(44100.0f),
  currentIndex(0.0f), tableDelta (0.0f), angleDelta(0.0f),
  tableSize(127)
{}


void OscillatorBase::prepare(const juce::dsp::ProcessSpec& spec)
{
    sampleRate = (float)spec.sampleRate;
    
    offsetHz.reset(spec.sampleRate, 0.05);
    amplitude.reset(spec.sampleRate, 0.05);
    
    adsr.setSampleRate(spec.sampleRate);
}

void OscillatorBase::setFrequency(const float frequency)
{
    noteHz = frequency;
    freq = noteHz * freqMult;

    auto tableSizeOverSampleRate = (float)tableSize / sampleRate;
    tableDelta = frequency * tableSizeOverSampleRate;
}

void OscillatorBase::updateParameters(const float frequencyMult, const float tune, const float amp)
{
    freqMult = frequencyMult;
    freq = noteHz * freqMult;
    offsetHz.setTargetValue(tune);
    amplitude.setTargetValue(amp);
}
 
void  OscillatorBase::process(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample)
{
    setSample(wavetable);
    updateAngle(tuneSample);
    setOutputLevel(depthSample);
}
    
void  OscillatorBase::process(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample,const float fmSample)
{
    setSample(wavetable);
    updateAngle(tuneSample,fmSample);
    setOutputLevel(depthSample);
}


void OscillatorBase::reset()
{
    angleDelta = 0;
    tableDelta = 0;
    adsr.reset();
}



void OscillatorBase::setOutputLevel(const float depthSample)
{   
    outputLevel = depthSample * amplitude.getNextValue() * adsr.getNextSample();
}


float OscillatorBase::getNextSample(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample)
{
    process(wavetable, tuneSample, depthSample);

    return getSample() * getOutputLevel();
}


float OscillatorBase::getNextSample(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample, float fmSample)
{
    process(wavetable, tuneSample, depthSample,fmSample);

    return getSample() * getOutputLevel();
}


void OscillatorBase::setSample(juce::AudioSampleBuffer& wavetable)
{
    auto index0 = (unsigned int)currentIndex;
    auto index1 = index0 + 1;
    auto frac = currentIndex - (float)index0;

    auto* table = wavetable.getReadPointer(0);
    auto value0 = table[index0];
    auto value1 = table[index1];

    sample = value0 + frac * (value1 - value0);
}

void OscillatorBase::updateAngle(const float tuneSample)
{
    angleDelta = (freq + tuneSample + offsetHz.getNextValue()) / sampleRate;
    
    if ((tableDelta = (float)tableSize * angleDelta) < 0)
        tableDelta += (float)tableSize;

    if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;
}

void OscillatorBase::updateAngle(const float tuneSample, const float fmSample)
{
    angleDelta = (freq + tuneSample + + fmSample + offsetHz.getNextValue()) / sampleRate;
   
    if ((tableDelta = (float)tableSize * angleDelta) < 0)
        tableDelta += (float)tableSize;
   
    if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;
}
