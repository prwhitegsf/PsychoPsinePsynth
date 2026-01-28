/*
  ==============================================================================

    NumBox.h
    Created: 19 Jan 2026 12:23:53am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class NumBox : public juce::LookAndFeel_V4
{
public:
 //   NumBox();


    juce::Label* createSliderTextBox(juce::Slider& slider) override;

};
