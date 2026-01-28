/*
  ==============================================================================

    NumBox.cpp
    Created: 19 Jan 2026 12:23:53am
    Author:  User

  ==============================================================================
*/

#include "NumBox.h"

juce::Label* NumBox::createSliderTextBox(juce::Slider& slider)
{
    juce::Label* textBox = juce::LookAndFeel_V4::createSliderTextBox(slider);

    // 4. Customize the Label (e.g., set font, colours, border, etc.)
    textBox->setColour(juce::Label::textColourId, juce::Colours::white);
    textBox->setColour(juce::Label::backgroundColourId, juce::Colours::transparentWhite);
    textBox->setColour(juce::Label::outlineColourId, juce::Colours::transparentWhite);

    textBox->setFont(juce::FontOptions(12.0f, juce::Font::plain));
    textBox->setBorderSize(juce::BorderSize<int>(1, 1, 1, 1));
    textBox->setJustificationType(juce::Justification::centred);


    // 5. Return the customized Label
    return textBox;
}
