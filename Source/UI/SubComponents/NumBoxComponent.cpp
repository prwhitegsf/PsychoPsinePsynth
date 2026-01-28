/*
  ==============================================================================

    NumBoxComponent.cpp
    Created: 13 Jan 2026 10:48:28am
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "NumBoxComponent.h"

//==============================================================================
NumBoxComponent::NumBoxComponent(juce::String label,  
    bool verticalOrientation,
    juce::Colour labelColor,
    juce::Colour numBoxColour) 
    : isVertical(verticalOrientation)
{
    numLabel.setFont(juce::FontOptions(12.0f,juce::Font::plain));
    numLabel.setText(label, juce::dontSendNotification);
    numLabel.setColour(juce::Label::textColourId, labelColor);
    numLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(numLabel);

    numBox.setLookAndFeel(&customNum);
    numBox.setSliderStyle(juce::Slider::LinearBarVertical);
    numBox.setSliderSnapsToMousePosition(false);
    numBox.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 40, 20);
    numBox.setColour(juce::Slider::trackColourId, juce::Colours::transparentBlack);
    numBox.setColour(juce::Slider::textBoxTextColourId, numBoxColour);
    numBox.setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentWhite);
    numBox.setSize(40, 20);
    numBox.setNumDecimalPlacesToDisplay(2);
    addAndMakeVisible(numBox);

    setSize(40, 40);
}

NumBoxComponent::~NumBoxComponent()
{
}

void NumBoxComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::transparentBlack);            
}

void NumBoxComponent::resized()
{
     if (isVertical) 
    {
        numLabel.setBounds(0, 0, 40, 15);
        numBox.setBounds(0, numLabel.getBottom()+5, 40, 20);
        return;
    }
 
    numLabel.setBounds(0, 0, 15, 15);
    numBox.setBounds(numLabel.getRight() + 5,0,40,20);

}
