/*
  ==============================================================================

    LfoComponent.h
    Created: 11 Jan 2026 2:34:47pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NumBoxComponent.h"

//==============================================================================
/*
*/
class LfoComponent  : public juce::Component
{
public:
    LfoComponent(juce::String rateText, juce::String ampText, bool verticalOrientation = true);
    ~LfoComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    NumBoxComponent rate;
    NumBoxComponent amp;
    juce::TextButton hold;
    
    bool isVertical;

private:

    juce::Label rateLabel;
    juce::Label ampLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfoComponent)
};
