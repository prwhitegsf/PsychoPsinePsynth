/*
  ==============================================================================

    FilterComponent.h
    Created: 15 Jan 2026 12:57:35pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NumBoxComponent.h"
#include "CustomComponents/CustomCB.h"


//==============================================================================
/*
*/
class FilterComponent  : public juce::Component
{
public:
    FilterComponent();
    ~FilterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    CustomCB ccb;
    juce::ComboBox mode;
    juce::TextButton enable;

    NumBoxComponent lpFreq;
    NumBoxComponent lpQ;

    NumBoxComponent hpFreq;
    NumBoxComponent hpQ;



  
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
