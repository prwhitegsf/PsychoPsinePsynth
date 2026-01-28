/*
  ==============================================================================

    FreqMultComponent.cpp
    Created: 11 Jan 2026 3:33:48pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FreqMultComponent.h"

//==============================================================================
FreqMultComponent::FreqMultComponent() 
{
    initFreqMultLabel();
    initRadioButtons();

    setSize(280, 60);
}

FreqMultComponent::~FreqMultComponent()
{
}

void FreqMultComponent::paint (juce::Graphics& g)
{
       g.fillAll(juce::Colours::transparentWhite);
}   


void FreqMultComponent::resized()
{
    freqMultLabel.setBounds(0, 0, 40, 20);
    radioButtons[0].setBounds(0, freqMultLabel.getBottom()+10, 40, 18);

    for (size_t i{ 1 }; i < 7; ++i)
    {
        radioButtons[i].setBounds(0,radioButtons[i - 1].getBottom(), 40, 18);
    }
}

void FreqMultComponent::setTextButtonParams(juce::TextButton& textButton, juce::String buttonText)
{
    textButton.setButtonText(buttonText);
    textButton.changeWidthToFitText();
    textButton.setClickingTogglesState(true);
    textButton.setRadioGroupId(FreqMults);
    addAndMakeVisible(textButton);
}

void FreqMultComponent::initRadioButtons()
{
    for (int i{}; i < 7; ++i)
    {
        setTextButtonParams(radioButtons[i], labels[i]);
        radioButtons[i].onClick = [this,i]{ this->freqMult.setValue(freqMults[i]); };
        radioButtons[i].setColour(juce::TextButton::buttonOnColourId, juce::Colours::white);
        radioButtons[i].setColour(juce::TextButton::textColourOnId, juce::Colours::black);
    }
  
    radioButtons[0].setColour(juce::TextButton::buttonColourId, juce::Colour(50,0,0));
    radioButtons[1].setColour(juce::TextButton::buttonColourId, juce::Colour(0,0,50));
    radioButtons[2].setColour(juce::TextButton::buttonColourId, juce::Colour(0,50,0));
    radioButtons[3].setColour(juce::TextButton::buttonColourId, juce::Colour(50,50,0));
    radioButtons[4].setColour(juce::TextButton::buttonColourId, juce::Colour(50,0,50));
    radioButtons[5].setColour(juce::TextButton::buttonColourId, juce::Colour(50,50,50));
    radioButtons[6].setColour(juce::TextButton::buttonColourId, juce::Colour(30,0,50));

}

void FreqMultComponent::initFreqMultLabel()
{
    freqMultLabel.setFont(juce::FontOptions(12.0f,juce::Font::plain));
    freqMultLabel.setText("mult",juce::dontSendNotification);
    freqMultLabel.setColour(juce::Label::textColourId, juce::Colours::grey);
    freqMultLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(freqMultLabel);

}




void FreqMultComponent::setInitialFreqMult()
{
    freqMultIndex = setFreqMultIndexFromFloat((float)freqMult.getValue());
    radioButtons[freqMultIndex].setToggleState(true,juce::sendNotification);
}

size_t  FreqMultComponent::setFreqMultIndexFromFloat(float mult)
{
    if (juce::approximatelyEqual<float>(mult, 4.0f))
        return 0;
    else if (juce::approximatelyEqual<float>(mult, 3.0f))
        return 1;
    else if (juce::approximatelyEqual<float>(mult, 2.0f))
        return 2;
    else if (juce::approximatelyEqual<float>(mult, 1.5f))
        return 3;
    else if (juce::approximatelyEqual<float>(mult, 1.0f))
        return 4;
    else if (juce::approximatelyEqual<float>(mult, 0.5f))
        return 5;
    else 
        return 6;
}
