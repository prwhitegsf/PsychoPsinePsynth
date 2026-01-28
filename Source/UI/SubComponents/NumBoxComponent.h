/*
  ==============================================================================

    NumBoxComponent.h
    Created: 13 Jan 2026 10:48:28am
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomComponents/NumBox.h"

//==============================================================================
/*
*/
class NumBoxComponent  : public juce::Component
{
public:
    NumBoxComponent(juce::String label,  
        bool verticalOrientation = true,
        juce::Colour labelColor = juce::Colours::grey, 
        juce::Colour numBoxColour = juce::Colours::white);
    ~NumBoxComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::Label numLabel;
    
    NumBox customNum;
    juce::Slider numBox;
  
    bool isVertical;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NumBoxComponent)
};
