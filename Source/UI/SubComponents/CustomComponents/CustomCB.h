/*
  ==============================================================================

    CustomCB.h
    Created: 17 Jan 2026 8:37:02am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class CustomCB : public juce::LookAndFeel_V4
{
public:

    juce::Font getComboBoxFont(juce::ComboBox&) override;

    juce::Font getPopupMenuFont() override;
};
