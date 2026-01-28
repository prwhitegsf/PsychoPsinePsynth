/*
  ==============================================================================

    ToneComponent.h
    Created: 14 Jan 2026 6:14:27am
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SubComponents/OscUnitComponent.h"
#include "MixerComponent.h"


//==============================================================================
/*
*/
class ToneComponent  : public juce::Component
{
public:
    ToneComponent(juce::AudioProcessorValueTreeState& apvts, int idx);
    ~ToneComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void holdAllLfo();
    void releaseAllLfo();
private:
    OscUnitComponent fm;
    OscUnitComponent carrier;
    OscUnitComponent rm;
    MixerComponent mixer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ToneComponent)
};
