/*
  ==============================================================================

    KeyboardComponent.h
    Created: 19 Jan 2026 2:59:45am
    Author:  User

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class KeyboardComponent  : public juce::MidiKeyboardComponent
  {
public:
    KeyboardComponent(juce::MidiKeyboardState& state, Orientation orientation);
    ~KeyboardComponent() override;



    void mouseDown(const juce::MouseEvent& e) override;
    void mouseUp(const juce::MouseEvent& e) override;
  /*
    void drawWhiteNote(int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
        bool isDown, bool isOver, juce::Colour lineColour, juce::Colour textColour) override;

    void drawBlackNote(int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
        bool isDown, bool isOver, juce::Colour noteFillColour) override;
        */
    juce::String getWhiteNoteText(int midiNoteNumber) override;


    void setBaseNote(int base);
    void setNotesPerOctave(int npo);

 private:
    
     int baseNote = 69;
     int notesPerOctave = 7;

     std::unordered_set<int> heldNotes;
     juce::MidiKeyboardState& kbState;
  
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardComponent)
};
