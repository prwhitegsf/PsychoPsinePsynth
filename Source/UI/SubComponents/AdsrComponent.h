/*
  ==============================================================================

    AdsrComponent.h
    Created: 13 Jan 2026 1:19:44pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "NumBoxComponent.h"
//==============================================================================
/*
*/
class AdsrComponent  : public juce::Component
{
public:
    AdsrComponent();
    ~AdsrComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::Label componentLabel;
    void initComponentLabel(juce::Label& label);

    NumBoxComponent attack;
    NumBoxComponent decay;
    NumBoxComponent sustain;
    NumBoxComponent release;


private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AdsrComponent)
};
