/*
  ==============================================================================

    GlobalHoldComponent.h
    Created: 21 Jan 2026 5:16:57pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class GlobalHoldComponent  : public juce::Component
{
public:
    GlobalHoldComponent();
    ~GlobalHoldComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
   
    juce::Label componentLabel;
    juce::TextButton holdAll;
    juce::TextButton releaseAll;


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GlobalHoldComponent)
};
