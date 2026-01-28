/*
  ==============================================================================

    OscUnitComponent.cpp
    Created: 23 Jan 2026 4:56:38pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "OscUnitComponent.h"

//==============================================================================
OscUnitComponent::OscUnitComponent(juce::AudioProcessorValueTreeState& apvts, juce::String modPrefix, int index, juce::Colour backgroundColor, juce::String tuneName, juce::String depthName)
    : idx(juce::String(index)),
    tune(tuneName),
    tuneLfo("rate(s)", "amp(hz)"),
    depth(depthName), 
    depthLfo("rate(s)","amp"),
    prefix(modPrefix), 
    bgColor(backgroundColor)
{
    initModuleLabel();
    initFreqMult(apvts);

    juce::String tuneId = prefix + juce::String("_TUNE_") + idx;
    tuneAttachment = std::make_unique<SliderAttachment>(apvts, tuneId, tune.numBox);
    addAndMakeVisible(tune);

    juce::String depthId = prefix + juce::String("_DEPTH_") + idx;
    depthAttachment = std::make_unique<SliderAttachment>(apvts, depthId, depth.numBox);
    addAndMakeVisible(depth);


    initTuneLfo(apvts);
    initDepthLfo(apvts);
    initAdsr(apvts);

    setSize(300, 250);
}

OscUnitComponent::~OscUnitComponent()
{
}

void OscUnitComponent::paint (juce::Graphics& g)
{
    g.fillAll(bgColor);
    g.setColour(juce::Colours::grey);
    juce::Line<float> verticalDivider(249, 0, 250, 200);
    g.drawLine(verticalDivider);

    juce::Line<float> horizontalDivider(0, 200, 250, 200);
    g.drawLine(horizontalDivider);
}

void OscUnitComponent::resized()
{
    freqMultComponent.setBounds(20, 25, 60, 180);
    tune.setBounds(freqMultComponent.getRight(), 30, 40, 40);
    tuneLfo.setBounds(freqMultComponent.getRight(), tune.getBottom() + 5, 40, 110);
    depth.setBounds(tune.getRight() + 10, 30, 40, 40);
    depthLfo.setBounds(tuneLfo.getRight() + 10, depth.getBottom() + 5, 40, 110);

    adsrComponent.setBounds(depth.getRight() + 10, 28, 90, 150);

}


void OscUnitComponent::holdLfos()
{
    tuneLfo.hold.setToggleState(true, juce::sendNotification);
    depthLfo.hold.setToggleState(true, juce::sendNotification);
}

void OscUnitComponent::releaseLfos()
{
    tuneLfo.hold.setToggleState(false, juce::sendNotification);
    depthLfo.hold.setToggleState(false, juce::sendNotification);

}


void OscUnitComponent::initModuleLabel()
{
    moduleLabel.setFont(juce::FontOptions(16.0f));
    moduleLabel.setText("Freq Mod", juce::dontSendNotification);
    moduleLabel.setColour(juce::Label::textColourId, juce::Colours::white);
    moduleLabel.setJustificationType(juce::Justification::left);
    addAndMakeVisible(moduleLabel);
}

void OscUnitComponent::initFreqMult(juce::AudioProcessorValueTreeState& apvts)
{
    juce::String freqMultId = prefix + juce::String("_FREQ_MULT_") + idx;
    freqMultAttachment = std::make_unique<SliderAttachment>(apvts, freqMultId, freqMultComponent.freqMult);
    freqMultComponent.setInitialFreqMult();
    addAndMakeVisible(freqMultComponent);
}

void OscUnitComponent::initTuneLfo(juce::AudioProcessorValueTreeState& apvts)
{
    juce::String tuneLfoRateId = prefix + juce::String("_TUNE_LFO_RATE_") + idx;
    tuneLfoRateAttachment = std::make_unique<SliderAttachment>(apvts, tuneLfoRateId, tuneLfo.rate.numBox);

    juce::String tuneLfoAmpId = prefix + juce::String("_TUNE_LFO_AMP_") + idx;
    tuneLfoAmpAttachment = std::make_unique<SliderAttachment>(apvts, tuneLfoAmpId, tuneLfo.amp.numBox);

    juce::String tuneLfoHoldId = prefix + juce::String("_TUNE_LFO_HOLD_") + idx;
    tuneLfoHoldAttachment = std::make_unique<ButtonAttachment>(apvts, tuneLfoHoldId, tuneLfo.hold);

    addAndMakeVisible(tuneLfo);


}

void OscUnitComponent::initDepthLfo(juce::AudioProcessorValueTreeState& apvts)
{
    juce::String depthLfoRateId = prefix + juce::String("_DEPTH_LFO_RATE_") + idx;
    depthLfoRateAttachment = std::make_unique<SliderAttachment>(apvts, depthLfoRateId, depthLfo.rate.numBox);

    juce::String depthLfoAmpId = prefix + juce::String("_DEPTH_LFO_AMP_") + idx;
    depthLfoAmpAttachment = std::make_unique<SliderAttachment>(apvts, depthLfoAmpId, depthLfo.amp.numBox);

    juce::String depthLfoHoldId = prefix + juce::String("_DEPTH_LFO_HOLD_") + idx;
    depthLfoHoldAttachment = std::make_unique<ButtonAttachment>(apvts, depthLfoHoldId, depthLfo.hold);

    addAndMakeVisible(depthLfo);
}

void OscUnitComponent::initAdsr(juce::AudioProcessorValueTreeState& apvts)
{
    juce::String attackId = prefix + juce::String("_ATTACK_") + idx;
    attackAttachment = std::make_unique<SliderAttachment>(apvts, attackId, adsrComponent.attack.numBox);

    juce::String decayId = prefix + juce::String("_DECAY_") + idx;
    decayAttachment = std::make_unique<SliderAttachment>(apvts, decayId, adsrComponent.decay.numBox);

    juce::String sustainId = prefix + juce::String("_SUSTAIN_") + idx;
    sustainAttachment = std::make_unique<SliderAttachment>(apvts, sustainId, adsrComponent.sustain.numBox);

    juce::String releaseId = prefix + juce::String("_RELEASE_") + idx;
    releaseAttachment = std::make_unique<SliderAttachment>(apvts, releaseId, adsrComponent.release.numBox);

    addAndMakeVisible(adsrComponent);
}
