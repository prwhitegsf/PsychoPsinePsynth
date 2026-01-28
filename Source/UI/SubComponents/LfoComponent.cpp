/*
  ==============================================================================

    LfoComponent.cpp
    Created: 11 Jan 2026 2:34:47pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "LfoComponent.h"

//==============================================================================
LfoComponent::LfoComponent(juce::String rateText, juce::String ampText, bool verticalOrientation)
    : rate(rateText), amp(ampText), isVertical(verticalOrientation)
{
  
    addAndMakeVisible(rate);
    addAndMakeVisible(amp);

    hold.setButtonText("hold");
    hold.changeWidthToFitText();
    hold.setClickingTogglesState(true);
    hold.setColour(juce::TextButton::buttonColourId, juce::Colour(20,40,20));
    hold.setColour(juce::TextButton::buttonOnColourId, juce::Colours::darkred);
    hold.setColour(juce::TextButton::textColourOnId, juce::Colours::white);
    hold.setColour(juce::TextButton::textColourOffId, juce::Colours::white);
    addAndMakeVisible(hold);

    setSize(115, 70);
}

LfoComponent::~LfoComponent()
{
}

void LfoComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::transparentBlack);
}

void LfoComponent::resized()
{
    if (isVertical)
    {
        rate.setBounds(0, 0, 40, 40);
        amp.setBounds(0, rate.getBottom() + 5, 40, 40);
        hold.setBounds(0, amp.getBottom() + 5, 40, 15);
        return;
    }

    rate.setBounds(0, 0, 40, 40);
    amp.setBounds(rate.getRight()+35, 0, 40, 40);
}
