/*
  ==============================================================================

    AdsrComponent.cpp
    Created: 13 Jan 2026 1:19:44pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "AdsrComponent.h"

//==============================================================================
AdsrComponent::AdsrComponent()
    : attack("a",false), decay("d",false), sustain("s",false), release("r",false)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    initComponentLabel(componentLabel);
    addAndMakeVisible(attack);
    addAndMakeVisible(decay);
    addAndMakeVisible(sustain);
    addAndMakeVisible(release);

    setSize(280, 180);


}

AdsrComponent::~AdsrComponent()
{
}

void AdsrComponent::paint (juce::Graphics& g)
{
    
    g.fillAll(juce::Colours::transparentBlack);

}

void AdsrComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    componentLabel.setBounds(10, 0, 60, 20);
    attack.setBounds(0, componentLabel.getBottom()+5, 90, 20);
    decay.setBounds(0, attack.getBottom() + 15, 90, 20);
    sustain.setBounds(0,decay.getBottom() + 15, 90, 20);
    release.setBounds(0,sustain.getBottom() + 15,  90, 20);
  /*  attack.setBounds(0, 0, 40, 40);
    decay.setBounds(attack.getRight() + 35, 0,40, 40);
    sustain.setBounds(decay.getRight() + 35, 0,40, 40);
    release.setBounds(sustain.getRight() + 35, 0,40, 40);*/
}

void AdsrComponent::initComponentLabel(juce::Label& label)
{
    label.setFont(juce::FontOptions(12.0f,juce::Font::plain));
    label.setText("env(s)", juce::dontSendNotification);
    label.setColour(juce::Label::textColourId, juce::Colours::grey);
    label.setJustificationType(juce::Justification::left);
    addAndMakeVisible(label);
}
