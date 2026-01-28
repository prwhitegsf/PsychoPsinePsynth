/*
  ==============================================================================

    SmallRotaryDial.h
    Created: 15 Jan 2026 12:54:07pm
    Author:  User

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>

class SmallRotaryDial : public juce::LookAndFeel_V4
{
public:
    SmallRotaryDial(juce::Colour color);

    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle,
        juce::Slider&) override;

    juce::Slider::SliderLayout getSliderLayout(juce::Slider& slider) override;
    void setPointerColor(juce::Colour color);

    juce::Label* createSliderTextBox(juce::Slider& slider) override;


private:
    juce::Colour colors;

};
