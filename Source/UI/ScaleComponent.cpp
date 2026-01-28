/*
  ==============================================================================

    ScaleComponent.cpp
    Created: 17 Jan 2026 8:35:21am
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ScaleComponent.h"

//==============================================================================
ScaleComponent::ScaleComponent(juce::AudioProcessorValueTreeState& apvts, juce::StringArray names)
    : baseNote("base"), notesPerOctave("count")
{
    addAndMakeVisible(baseNote);
    baseNoteAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, "SCALE_BASE_NOTE", baseNote.numBox);


    initSelectScale(names);
    selectScaleAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, "SCALE_SELECT", selectScale);
   
    
    npoLabel.setText("n/oct", juce::dontSendNotification);
    npoLabel.setFont(juce::FontOptions(12.0f,juce::Font::plain));
    npoLabel.setColour(juce::Label::textColourId, juce::Colours::grey);
    npoLabel.setJustificationType(juce::Justification::centred);
    notesPerOctave.setFont(juce::FontOptions(12.0f));
    notesPerOctave.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(npoLabel);
    addAndMakeVisible(notesPerOctave);

    componentLabel.setText("scale select", juce::dontSendNotification);
    componentLabel.setFont(juce::FontOptions(12.0f, juce::Font::plain));
    componentLabel.setColour(juce::Label::textColourId, juce::Colours::grey);
    componentLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(componentLabel);

    setSize(280, 100);
}

ScaleComponent::~ScaleComponent()
{
}

void ScaleComponent::paint (juce::Graphics& g)
{
  
    g.fillAll(juce::Colour(25,20,25));
    g.setColour(juce::Colours::grey);
    juce::Line<float> horizontalDivider(0, 0, 280, 1);
    g.drawLine(horizontalDivider);


}

void ScaleComponent::resized()
{
   
    componentLabel.setBounds(10, 5, 150, 15);
    selectScale.setBounds(10, componentLabel.getBottom()+5, 150, 20);

    baseNote.setBounds(componentLabel.getRight()+10,5, 60, 40);
    npoLabel.setBounds(componentLabel.getRight() + 10, baseNote.getBottom()+10, 40, 20);
    notesPerOctave.setBounds(componentLabel.getRight() + 10, npoLabel.getBottom(), 40, 20);


    }

void ScaleComponent::initSelectScale(juce::StringArray scales)
{
    selectScale.addItemList(scales, 1);
    selectScale.setSelectedId(1);
    selectScale.setJustificationType(juce::Justification::left);
    addAndMakeVisible(selectScale);
    selectScale.setLookAndFeel(&customCB);
}
