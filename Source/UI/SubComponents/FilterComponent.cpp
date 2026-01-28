/*
  ==============================================================================

    FilterComponent.cpp
    Created: 15 Jan 2026 12:57:35pm
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent()
    : lpFreq("lp freq"), lpQ("lp res"), hpFreq("hp freq"), hpQ("hp res")
{

    addAndMakeVisible(lpFreq);
	addAndMakeVisible(lpQ);
	
    addAndMakeVisible(hpFreq);
    addAndMakeVisible(hpQ);

    setSize(100, 200);
}

FilterComponent::~FilterComponent()
{
}

void FilterComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::transparentWhite);
}

void FilterComponent::resized()
{
    int pad{ 10 };
    lpFreq.setBounds(10, 25, 40, 40);
    lpQ.setBounds(10,lpFreq.getBottom()+5, 40, 40);

    hpFreq.setBounds(lpFreq.getRight() + pad, 25, 40, 40);
    hpQ.setBounds(lpQ.getRight() + pad, lpFreq.getBottom() + 5, 40, 40);

}
