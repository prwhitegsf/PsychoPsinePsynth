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
    if (juce::JUCEApplication::isStandaloneApp())
    {
        addAndMakeVisible(keyboardComponent);
    }
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
    g.fillAll(juce::Colours::darkgrey);
   
    if (!juce::JUCEApplication::isStandaloneApp())
    {
        g.setColour(juce::Colour(15,15,15));
        juce::Rectangle<float> filler(250, 720, 500, 100);
        g.fillRect(filler);
      
        g.setColour(juce::Colour(105,105,105));
        g.drawText("... RESERVED FOR FUTURE USE ...",filler, juce::Justification::centred,true);
    }
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
    
    if (juce::JUCEApplication::isStandaloneApp())
    {
        scaleComponent.setBounds(0, 720, 250, 100);
        keyboardComponent.setBounds(scaleComponent.getRight(), 720, 500, 100);
        globalHold.setBounds(scaleComponent.getRight() + 500, 720, 250, 100);
    }
    else 
    {
        scaleComponent.setBounds(0, 720, 250, 100);
        globalHold.setBounds(scaleComponent.getRight() + 500, 720, 250, 100);

    }
}

void PsychoPsinePsynthAudioProcessorEditor::timerCallback()
{
    scaleComponent.notesPerOctave.setText(juce::String(audioProcessor.scale.notesPerOctave), juce::dontSendNotification);

    if (audioProcessor.scale.hasChanged)
    {
        keyboardComponent.setBaseNote(audioProcessor.scale.baseNote);
        keyboardComponent.setNotesPerOctave(audioProcessor.scale.notesPerOctave);
        audioProcessor.scale.hasChanged = false;
    }




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
