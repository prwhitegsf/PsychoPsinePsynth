/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PsychoPsinePsynthAudioProcessorEditor::PsychoPsinePsynthAudioProcessorEditor (PsychoPsinePsynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    toneComponent0(p.apvts, 0),
    toneComponent1(p.apvts, 1),
    toneComponent2(p.apvts, 2),
    toneComponent3(p.apvts, 3),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    addAndMakeVisible(toneComponent0);
    addAndMakeVisible(toneComponent1);
    addAndMakeVisible(toneComponent2);
    addAndMakeVisible(toneComponent3);



    initLabel(fmLabel, "Freq Mod");
    initLabel(crLabel, "Carrier");
    initLabel(rmLabel, "Ring Mod");
    initLabel(mixerLabel, "Mixer");


    addAndMakeVisible(globalHold);

    setSize(1000, 830);
}

PsychoPsinePsynthAudioProcessorEditor::~PsychoPsinePsynthAudioProcessorEditor()
{
}

//==============================================================================
void PsychoPsinePsynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::whitesmoke);
}

void PsychoPsinePsynthAudioProcessorEditor::resized()
{
    toneComponent0.setBounds(0, 10, 250, 710);
    toneComponent1.setBounds(toneComponent0.getRight(), 10, 250, 710);
    toneComponent2.setBounds(toneComponent1.getRight(), 10, 250, 710);
    toneComponent3.setBounds(toneComponent2.getRight(), 10, 250, 710);



    fmLabel.setBounds(0, 0, 1000, 20);
    crLabel.setBounds(0, 200, 1000, 20);
    rmLabel.setBounds(0, 390, 1000, 20);

    mixerLabel.setBounds(0, 580, 1000, 20);
}

void PsychoPsinePsynthAudioProcessorEditor::initLabel(juce::Label& label, juce::String text)
{
    label.setFont(juce::FontOptions(16.0f));
    label.setText(text, juce::dontSendNotification);
    label.setColour(juce::Label::textColourId, juce::Colours::antiquewhite);
    label.setColour(juce::Label::backgroundColourId, juce::Colour(50, 50, 50));
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
    label.toFront(false);
}
