/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Data/AudioEngine.h"
#include "Scales/Scale.h"
#include "Data/Voice.h"
#include "Data/ParameterIds/OscillatorIds.h"
#include "Data/ParameterIds/MixerIds.h"

//==============================================================================
/**
*/
class PsychoPsinePsynthAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================
    PsychoPsinePsynthAudioProcessor();
    ~PsychoPsinePsynthAudioProcessor() override;

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int ) override;
    const juce::String getProgramName (int) override;
    void changeProgramName (int, const juce::String&) override;

    //==============================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    juce::AudioProcessorValueTreeState apvts;
    Scale scale;
   
private:
    static const int toneCount = 4;

    juce::AudioProcessorValueTreeState::ParameterLayout createParams();

    AudioEngine synth;

    std::array<OscillatorIds, toneCount> carrierIds{ OscillatorIds("CR",0),OscillatorIds("CR",1), OscillatorIds("CR", 2),OscillatorIds("CR",3) };
    std::array<OscillatorIds, toneCount> fmIds{ OscillatorIds("FM",0),OscillatorIds("FM",1), OscillatorIds("FM", 2),OscillatorIds("FM",3) };
    std::array<OscillatorIds, toneCount> rmIds{ OscillatorIds("RM",0),OscillatorIds("RM",1), OscillatorIds("RM", 2),OscillatorIds("RM",3) };
    std::array<MixerIds, toneCount> mixerIds{ MixerIds(0),MixerIds(1),MixerIds(2),MixerIds(3) };

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PsychoPsinePsynthAudioProcessor)
};
