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
    //auto cyclesPerSample = freq / sampleRate;
    //angleDelta = cyclesPerSample * juce::MathConstants<double>::twoPi;

    auto tableSizeOverSampleRate = (float)tableSize / sampleRate;
    tableDelta = frequency * tableSizeOverSampleRate;
}

void OscillatorBase::updateParameters(const float freqMult, const float tune, const float amp)
{
    frequencyMultiple = freqMult;
    freq = noteHz * freqMult;
    offsetHz.setTargetValue(tune);
    amplitude.setTargetValue(amp);
}
 
void  OscillatorBase::process(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample)
{
    //setSample();
    setSample(wavetable);
    updateAngle(tuneSample);
    setOutputLevel(depthSample);
}
    
void  OscillatorBase::process(juce::AudioSampleBuffer& wavetable, float tuneSample, float depthSample,const float fmSample)
{
  //  setSample();
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

void OscillatorBase::setSample()
{
    sample = (float)(std::sin(angle));
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

  /*  if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;*/



}

void OscillatorBase::updateAngle(const float tuneSample)
{
    angleDelta = ((float)tableSize * (freq + tuneSample + offsetHz.getNextValue())) / sampleRate;
    tableDelta = angleDelta >= 0 ? angleDelta : angleDelta + (float)tableSize;

   // tableDelta = ((float)tableSize * (freq + tuneSample + offsetHz.getNextValue())) / sampleRate;
    if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;
   // angleDelta = ((freq + tuneSample + offsetHz.getNextValue()) / sampleRate) * juce::MathConstants<double>::twoPi;
   // angle += angleDelta;
}

void OscillatorBase::updateAngle(const float tuneSample, const float fmSample)
{
    angleDelta = ((float)tableSize * (freq + tuneSample + fmSample + offsetHz.getNextValue())) / sampleRate;
    tableDelta = angleDelta >= 0 ? angleDelta : angleDelta + (float)tableSize;
    //tableDelta = ((float)tableSize * (freq + tuneSample + fmSample + offsetHz.getNextValue())) / sampleRate;
    if ((currentIndex += tableDelta) > (float)tableSize)
        currentIndex -= (float)tableSize;
  //  angleDelta = ((freq + tuneSample + fmSample + offsetHz.getNextValue()) / sampleRate) * juce::MathConstants<double>::twoPi;
   // angle += angleDelta;
}
