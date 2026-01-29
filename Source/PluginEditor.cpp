/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PsychoPsinePsynthAudioProcessorEditor::PsychoPsinePsynthAudioProcessorEditor (PsychoPsinePsynthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), scaleComponent(p.apvts, p.scale.getNames()),
    toneComponent0(p.apvts, 0),
    toneComponent1(p.apvts, 1),
    toneComponent2(p.apvts, 2),
    toneComponent3(p.apvts, 3),
    keyboardComponent(keyboardState, juce::MidiKeyboardComponent::Orientation::horizontalKeyboard)
{
    startTimerHz(10);

    addAndMakeVisible(toneComponent0);
    addAndMakeVisible(toneComponent1);
    addAndMakeVisible(toneComponent2);
    addAndMakeVisible(toneComponent3);


    keyboardComponent.setMidiChannel(2);
    keyboardState.addListener(&audioProcessor.getMidiMessageCollector());

    initLabel(fmLabel, "Freq Mod");
    initLabel(crLabel, "Carrier");
    initLabel(rmLabel, "Ring Mod");
    initLabel(mixerLabel, "Mixer");

    addAndMakeVisible(scaleComponent);
    addAndMakeVisible(keyboardComponent);
    addAndMakeVisible(globalHold);

    setSize(1000, 830);
}

PsychoPsinePsynthAudioProcessorEditor::~PsychoPsinePsynthAudioProcessorEditor()
{
    keyboardState.removeListener(&audioProcessor.getMidiMessageCollector());
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
    
    scaleComponent.setBounds(0, 720, 230, 100);
    keyboardComponent.setBounds(scaleComponent.getRight(), 720, 640, 100);
    globalHold.setBounds(keyboardComponent.getRight(), 720, 130, 100);
}

void PsychoPsinePsynthAudioProcessorEditor::timerCallback()
{
    scaleComponent.notesPerOctave.setText(juce::String(audioProcessor.scale.notesPerOctave), juce::dontSendNotification);
    keyboardComponent.setBaseNote(audioProcessor.scale.baseNote);
    keyboardComponent.setNotesPerOctave(audioProcessor.scale.notesPerOctave);




    if (globalHold.holdAll.getToggleState())
    {
        globalHold.holdAll.setToggleState(false, juce::dontSendNotification);
        toneComponent0.holdAllLfo();
        toneComponent1.holdAllLfo();
        toneComponent2.holdAllLfo();
        toneComponent3.holdAllLfo();
    }

    if (globalHold.releaseAll.getToggleState())
    {
        globalHold.releaseAll.setToggleState(false, juce::dontSendNotification);
        toneComponent0.releaseAllLfo();
        toneComponent1.releaseAllLfo();
        toneComponent2.releaseAllLfo();
        toneComponent3.releaseAllLfo();
    }
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
