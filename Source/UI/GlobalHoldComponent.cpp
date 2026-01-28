/*
  ==============================================================================

    GlobalHoldComponent.cpp
    Created: 21 Jan 2026 5:16:57pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "GlobalHoldComponent.h"

//==============================================================================
GlobalHoldComponent::GlobalHoldComponent()
{
    componentLabel.setText("Global LFO", juce::dontSendNotification);
    componentLabel.setFont(juce::FontOptions(12.0f, juce::Font::plain));
    componentLabel.setColour(juce::Label::textColourId, juce::Colours::grey);
    componentLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(componentLabel);

    holdAll.setButtonText("hold all");
    holdAll.changeWidthToFitText();
    holdAll.setClickingTogglesState(true);
    addAndMakeVisible(holdAll);
    
    releaseAll.setButtonText("release all");
    releaseAll.changeWidthToFitText();
    releaseAll.setClickingTogglesState(true);
    addAndMakeVisible(releaseAll);
}

GlobalHoldComponent::~GlobalHoldComponent()
{
}

void GlobalHoldComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colour(20,20,20));
    g.setColour(juce::Colours::grey);
    juce::Line<float> horizontalDivider(0, 0, 130, 1);
    g.drawLine(horizontalDivider);
}

void GlobalHoldComponent::resized()
{
    componentLabel.setBounds(0, 5, 130, 15);
    holdAll.setBounds(25, componentLabel.getBottom()+5, 80, 20);
    releaseAll.setBounds(25, holdAll.getBottom()+10, 80, 20);
}
