/*
  ==============================================================================

    LevelComponent.h
    Created: 15 Jan 2026 12:57:58pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomComponents/SmallRotaryDial.h"
#include "NumBoxComponent.h"
//==============================================================================
/*
*/
class LevelComponent  : public juce::Component
{
public:
    LevelComponent();
    ~LevelComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    SmallRotaryDial gainRotaryDial;
    juce::Slider gain;
       
    SmallRotaryDial panRotaryDial;
    juce::Slider pan;

private:

    juce::Label gainLabel;
    juce::Label panLabel;
    void initLabels(juce::Label& label, juce::String name);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LevelComponent)
};
