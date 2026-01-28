/*
  ==============================================================================

    MixerComponent.h
    Created: 15 Jan 2026 12:58:20pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SubComponents/CustomComponents/SmallRotaryDial.h"

#include "SubComponents/FilterComponent.h"
#include "SubComponents/LevelComponent.h"
//==============================================================================
/*
*/
class MixerComponent  : public juce::Component
{
public:
    MixerComponent(juce::AudioProcessorValueTreeState& apvts, int index);
    ~MixerComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::String idx;


    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;

    FilterComponent filter;
    std::unique_ptr<SliderAttachment> lpFreqAttachment;
    std::unique_ptr<SliderAttachment> lpQAttachment;
    std::unique_ptr<SliderAttachment> hpFreqAttachment;
    std::unique_ptr<SliderAttachment> hpQAttachment;
    void initFilter(juce::AudioProcessorValueTreeState& apvts);

    LevelComponent level;
    std::unique_ptr<SliderAttachment> gainAttachment;
    std::unique_ptr<SliderAttachment> panAttachment;
    void initLevel(juce::AudioProcessorValueTreeState& apvts);




    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MixerComponent)
};
