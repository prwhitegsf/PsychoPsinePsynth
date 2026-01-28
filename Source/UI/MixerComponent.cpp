/*
  ==============================================================================

    MixerComponent.cpp
    Created: 15 Jan 2026 12:58:20pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "MixerComponent.h"

//==============================================================================
MixerComponent::MixerComponent(juce::AudioProcessorValueTreeState& apvts, int index)
    : idx(juce::String(index))
{
    initFilter(apvts);
    initLevel(apvts);
      
    setSize(250, 200);
}

MixerComponent::~MixerComponent()
{
}

void MixerComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(15, 15, 15));
    g.setColour(juce::Colours::grey);
    juce::Line<float> verticalDivider(249, 0, 250, 200);
    g.drawLine(verticalDivider);

    juce::Line<float> horizontalDivider(0, 200, 250, 200);
    g.drawLine(horizontalDivider);

}
void MixerComponent::resized()
{
    filter.setBounds(0, 5, 100, 200);
    level.setBounds(110, 5, 125, 200);
}

void MixerComponent::initFilter(juce::AudioProcessorValueTreeState& apvts)
{
     juce::String lpFreqId = juce::String("LP_FREQ_") + idx;
     lpFreqAttachment = std::make_unique<SliderAttachment>(apvts, lpFreqId, filter.lpFreq.numBox);
    
     juce::String lpQId = juce::String("LP_Q_") + idx;
     lpQAttachment = std::make_unique<SliderAttachment>(apvts, lpQId, filter.lpQ.numBox);
       
     juce::String hpFreqId = juce::String("HP_FREQ_") + idx;
     hpFreqAttachment = std::make_unique<SliderAttachment>(apvts, hpFreqId, filter.hpFreq.numBox);

     juce::String hpQId = juce::String("HP_Q_") + idx;
     hpQAttachment = std::make_unique<SliderAttachment>(apvts, hpQId, filter.hpQ.numBox);
  
     addAndMakeVisible(filter);

}

void MixerComponent::initLevel(juce::AudioProcessorValueTreeState& apvts)
{
    juce::String gainId = juce::String("GAIN_") + idx;
    gainAttachment = std::make_unique<SliderAttachment>(apvts, gainId, level.gain);

    juce::String panId = juce::String("PAN_") + idx;
    panAttachment = std::make_unique<SliderAttachment>(apvts, panId, level.pan);

    addAndMakeVisible(level);
}
