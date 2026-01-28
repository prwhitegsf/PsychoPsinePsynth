/*
  ==============================================================================

    ToneComponent.cpp
    Created: 14 Jan 2026 6:14:27am
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ToneComponent.h"

//==============================================================================
ToneComponent::ToneComponent(juce::AudioProcessorValueTreeState& apvts, int idx)
    : fm(apvts, "FM", idx, juce::Colour(20,15,15), "tune", "index"),
    carrier(apvts, "CR", idx, juce::Colour(15, 20, 15), "tune", "amp"),
    rm(apvts,"RM", idx,juce::Colour(15,15,20),"tune","depth"),
    mixer(apvts,idx)
{
      
    addAndMakeVisible(fm);
    addAndMakeVisible(carrier);
    addAndMakeVisible(rm);
    addAndMakeVisible(mixer);
    setSize(300, 700);
}

ToneComponent::~ToneComponent()
{
}

void ToneComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void ToneComponent::resized()
{
    fm.setBounds(0, 0, 250, 190);
    carrier.setBounds(0, fm.getBottom(), 250, 190);
    rm.setBounds(0, carrier.getBottom(), 250, 190);
    mixer.setBounds(0, rm.getBottom(), 250, 150);

}

void ToneComponent::holdAllLfo()
{
    fm.holdLfos();
    carrier.holdLfos();
    rm.holdLfos();

}

void ToneComponent::releaseAllLfo()
{
    fm.releaseLfos();
    carrier.releaseLfos();
    rm.releaseLfos();
}
