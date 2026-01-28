/*
  ==============================================================================

    ScaleComponent.h
    Created: 17 Jan 2026 8:35:21am
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SubComponents/NumBoxComponent.h"
#include "SubComponents/CustomComponents/CustomCB.h"

//==============================================================================
/*
*/
class ScaleComponent  : public juce::Component
{
public:
    ScaleComponent(juce::AudioProcessorValueTreeState& apvts, juce::StringArray names);
    ~ScaleComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::Label componentLabel;
    juce::Label npoLabel;
    juce::Label notesPerOctave;

private:

    NumBoxComponent baseNote;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> baseNoteAttachment;

    CustomCB customCB;
    juce::ComboBox selectScale;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> selectScaleAttachment;
    void initSelectScale(juce::StringArray scales);

  
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ScaleComponent)
};
