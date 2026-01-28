/*
  ==============================================================================

    SmallRotaryDial.cpp
    Created: 15 Jan 2026 12:54:07pm
    Author:  User

  ==============================================================================
*/

#include "SmallRotaryDial.h"


SmallRotaryDial::SmallRotaryDial(juce::Colour color) : colors(color)
{
    setColour(juce::Slider::thumbColourId, colors);
}

void SmallRotaryDial::drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider&)
{
    float radius = ((float)juce::jmin(width / 2, height / 2) - 4.0f)*0.7f;
    float centerX = (float)x + (float)width * 0.5f;
    float centerY = (float)y + (float)height * 0.5f;
  //  float rx = centerX - radius;
  //  float ry = centerY - radius;
 //   float rw = radius * 2.0f;
    float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

    float bRadius = radius * 1.25f;
    float bX = centerX - bRadius;
    float bY = centerY - bRadius;

    // outline
    g.setColour(juce::Colour(30,30,30));
    g.drawEllipse(bX, bY, bRadius * 2.0f, bRadius * 2.0f, 10.0f);

    // fill
  //  g.setColour(juce::Colours::transparentWhite);
   // g.fillEllipse(rx, ry, rw, rw);


    // Pointer object
    juce::Path p;
    float pointerLength = radius * 0.4f * -1.0f;
    float pointerThickness = 4.0f;
    p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
    p.applyTransform(juce::AffineTransform::rotation(angle).translated(centerX, centerY));

    // pointer
    g.setColour(colors);

    g.fillPath(p);

}

juce::Slider::SliderLayout SmallRotaryDial::getSliderLayout(juce::Slider& slider)
{
    juce::Slider::SliderLayout layout;
    layout.sliderBounds = slider.getLocalBounds();
   
    layout.textBoxBounds = slider.getLocalBounds().withSizeKeepingCentre(40, 24);

    return layout;
}

void SmallRotaryDial::setPointerColor(juce::Colour color)
{
    colors = color;
}

juce::Label* SmallRotaryDial::createSliderTextBox(juce::Slider& slider)
{
    juce::Label* textBox = juce::LookAndFeel_V4::createSliderTextBox(slider);

    // 4. Customize the Label (e.g., set font, colours, border, etc.)
    textBox->setColour(juce::Label::textColourId, juce::Colours::white);
    textBox->setColour(juce::Label::backgroundColourId, juce::Colours::transparentBlack);
    textBox->setColour(juce::Label::outlineColourId, juce::Colours::transparentWhite);

    textBox->setFont(juce::FontOptions(10.0f, juce::Font::plain));
    textBox->setBorderSize(juce::BorderSize<int>(1, 1, 1, 1));
    textBox->setJustificationType(juce::Justification::centred);


    // 5. Return the customized Label
    return textBox;
}
