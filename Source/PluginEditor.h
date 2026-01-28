/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/ToneComponent.h"
#include "UI/ScaleComponent.h"
#include "UI/KeyboardComponent.h"
#include "UI/GlobalHoldComponent.h"

//==============================================================================
/**
*/
class PsychoPsinePsynthAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    PsychoPsinePsynthAudioProcessorEditor (PsychoPsinePsynthAudioProcessor&);
    ~PsychoPsinePsynthAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    PsychoPsinePsynthAudioProcessor& audioProcessor;

    juce::Label fmLabel;
    juce::Label crLabel;
    juce::Label rmLabel;
    juce::Label mixerLabel;

    void initLabel(juce::Label& label, juce::String text);

    ScaleComponent scaleComponent;
    ToneComponent toneComponent0;
    ToneComponent toneComponent1;
    ToneComponent toneComponent2;
    ToneComponent toneComponent3;
    GlobalHoldComponent globalHold;

    juce::MidiKeyboardState keyboardState;
    KeyboardComponent keyboardComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PsychoPsinePsynthAudioProcessorEditor)
};
