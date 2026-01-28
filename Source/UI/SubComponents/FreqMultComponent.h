/*
  ==============================================================================

    FreqMultComponent.h
    Created: 11 Jan 2026 3:33:48pm
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class FreqMultComponent  : public juce::Component
{
public:
    FreqMultComponent();
    ~FreqMultComponent() override;
    size_t setFreqMultIndexFromFloat(float mult);

    void paint (juce::Graphics&) override;
    void resized() override;

    
    void setInitialFreqMult();
    juce::Slider freqMult;

private:

    enum FreqMultIds
    {   
        FreqMults = 1001
    };

    size_t freqMultIndex{ 0 };

    juce::StringArray labels { "4","3","2","1.5","1","0.5","0.25" };
    juce::Array<float> freqMults{ 4.0f,3.0f,2.0f,1.5f,1.0f,0.5f,0.25f };
    std::array<juce::TextButton, 7> radioButtons;
    void setTextButtonParams(juce::TextButton& textButton, juce::String buttonText);
    void initRadioButtons();
    
    juce::Label freqMultLabel;
    void initFreqMultLabel();

   
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FreqMultComponent)
};
