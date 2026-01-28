/*
  ==============================================================================

    LevelComponent.cpp
    Created: 15 Jan 2026 12:57:58pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LevelComponent.h"

//==============================================================================
LevelComponent::LevelComponent()
    : gainRotaryDial(juce::Colour(125,125,255)),panRotaryDial(juce::Colour(255,255,255)), gain("gain"), pan("pan")
{
   
    initLabels(gainLabel, "gain");
    initLabels(panLabel, "pan");

    addAndMakeVisible(gain);
    gain.setLookAndFeel(&gainRotaryDial);
    gain.setSliderStyle(juce::Slider::Rotary);
    gain.setNumDecimalPlacesToDisplay(2);
    
    addAndMakeVisible(pan);
    pan.setLookAndFeel(&panRotaryDial);
    pan.setSliderStyle(juce::Slider::Rotary);
    pan.setNumDecimalPlacesToDisplay(2);




    setSize(180, 200);

}

LevelComponent::~LevelComponent()
{
}

void LevelComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::transparentWhite);
}

void LevelComponent::resized()
{
    gainLabel.setBounds(0, 25, 60, 15);
    panLabel.setBounds(gainLabel.getRight()+5, 25, 60, 15);
    gain.setBounds(0, gainLabel.getBottom() + 5, 60, 60);
    pan.setBounds(gain.getRight()+5, gainLabel.getBottom()+5, 60, 60);

}

void LevelComponent::initLabels(juce::Label& label, juce::String name)
{
    label.setFont(juce::FontOptions(12.0f));
    label.setText(name, juce::dontSendNotification);
    label.setColour(juce::Label::textColourId, juce::Colours::grey);
    label.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(label);
}
