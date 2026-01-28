/*
  ==============================================================================

    CustomCB.cpp
    Created: 17 Jan 2026 8:37:02am
    Author:  User

  ==============================================================================
*/

#include "CustomCB.h"


juce::Font CustomCB::getComboBoxFont(juce::ComboBox&)
{
    return juce::Font(juce::FontOptions("Arial", 12.0f, juce::Font::plain));
}

juce::Font CustomCB::getPopupMenuFont()
{

    return juce::Font(juce::FontOptions("Arial", 12.0f, juce::Font::plain));
}
