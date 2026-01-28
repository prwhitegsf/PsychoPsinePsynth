/*
  ==============================================================================

    OscUnitComponent.h
    Created: 23 Jan 2026 4:56:38pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FreqMultComponent.h"
#include "NumBoxComponent.h"
#include "LfoComponent.h"
#include "AdsrComponent.h"

//==============================================================================
/*
*/
class OscUnitComponent  : public juce::Component
{
public:
    OscUnitComponent(juce::AudioProcessorValueTreeState& apvts, juce::String prefix, int index, juce::Colour backgroundColor, juce::String tuneName = "tune",juce::String depthName = "depth");
    ~OscUnitComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void holdLfos();
    void releaseLfos();
    

private:

    juce::String prefix;
    juce::Colour bgColor;

    juce::String idx;
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    using ButtonAttachment = juce::AudioProcessorValueTreeState::ButtonAttachment;

    juce::Label moduleLabel;
    void initModuleLabel();

    FreqMultComponent freqMultComponent;
    std::unique_ptr<SliderAttachment> freqMultAttachment;
    void initFreqMult(juce::AudioProcessorValueTreeState& apvts);

    NumBoxComponent tune;
    std::unique_ptr<SliderAttachment> tuneAttachment;

    LfoComponent tuneLfo;
    std::unique_ptr<SliderAttachment> tuneLfoRateAttachment;
    std::unique_ptr<SliderAttachment> tuneLfoAmpAttachment;
    std::unique_ptr<ButtonAttachment> tuneLfoHoldAttachment;
    void initTuneLfo(juce::AudioProcessorValueTreeState& apvts);

    NumBoxComponent depth;
    std::unique_ptr<SliderAttachment> depthAttachment;

    LfoComponent depthLfo;
    std::unique_ptr<SliderAttachment> depthLfoRateAttachment;
    std::unique_ptr<SliderAttachment> depthLfoAmpAttachment;
    std::unique_ptr<ButtonAttachment> depthLfoHoldAttachment;
    void initDepthLfo(juce::AudioProcessorValueTreeState& apvts);

    AdsrComponent adsrComponent;
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    void initAdsr(juce::AudioProcessorValueTreeState& apvts);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscUnitComponent)
};
