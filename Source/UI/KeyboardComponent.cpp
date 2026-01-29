/*
  ==============================================================================

    KeyboardComponent.cpp
    Created: 19 Jan 2026 2:59:45am
    Author:  User

  ==============================================================================
*/

#include <JuceHeader.h>
#include "KeyboardComponent.h"

//==============================================================================

KeyboardComponent::KeyboardComponent(juce::MidiKeyboardState& state, Orientation orientation)
    : juce::MidiKeyboardComponent(state, orientation), kbState(state)
{
    setBlackNoteLengthProportion(0.5f);

    setSize(720, 99);
}

KeyboardComponent::~KeyboardComponent()
{
}

void KeyboardComponent::mouseDown(const juce::MouseEvent& e)
{
    auto newNote = getNoteAndVelocityAtPosition(e.position).note;

    if (kbState.isNoteOn(2,newNote)) 
    {
     //  heldNotes.erase(newNote);
        kbState.noteOff(2,newNote,0);
        return;
    }



    kbState.noteOn(2, newNote, 1);
 //   heldNotes.insert(newNote);

   }

void KeyboardComponent::mouseUp(const juce::MouseEvent& e)
{
    return;
}

juce::String KeyboardComponent::getWhiteNoteText(int midiNoteNumber)
{
    if (baseNote == midiNoteNumber)
        return "0";

    if (midiNoteNumber < baseNote)
    { 
        auto diff = baseNote - midiNoteNumber;
        if (diff % notesPerOctave == 0)
            return juce::String(-1 * diff / notesPerOctave);


        return {};
    }
    else
    {
        auto diff =  midiNoteNumber - baseNote;
        if (diff % notesPerOctave == 0)
            return juce::String(diff / notesPerOctave);


        return {};
    }

}



void KeyboardComponent::drawWhiteNote(int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
    bool isDown, bool isOver, juce::Colour lineColour, juce::Colour textColour)
{
    auto c = juce::Colours::transparentWhite;

    if (isDown)  c = c.overlaidWith(findColour(keyDownOverlayColourId));
    if (isOver)  c = c.overlaidWith(findColour(mouseOverKeyOverlayColourId));

    g.setColour(c);
    g.fillRect(area);

    const auto currentOrientation = getOrientation();

    auto text = getWhiteNoteText(midiNoteNumber);

    if (text.isNotEmpty())
    {
        auto fontHeight = juce::jmin(12.0f, getKeyWidth() * 0.9f);

        g.setColour(textColour);
        g.setFont(withDefaultMetrics(juce::FontOptions{ fontHeight }).withHorizontalScale(0.8f));

        switch (currentOrientation)
        {
        case horizontalKeyboard:            g.drawText(text, area.withTrimmedLeft(1.0f).withTrimmedBottom(2.0f), juce::Justification::centredBottom, false); break;
        case verticalKeyboardFacingLeft:    g.drawText(text, area.reduced(2.0f), juce::Justification::centredLeft, false); break;
        case verticalKeyboardFacingRight:   g.drawText(text, area.reduced(2.0f), juce::Justification::centredRight, false); break;
        default: break;
        }
    }

    if (!lineColour.isTransparent())
    {
        g.setColour(lineColour);

        switch (currentOrientation)
        {
        case horizontalKeyboard:            g.fillRect(area.withWidth(1.0f)); break;
        case verticalKeyboardFacingLeft:    g.fillRect(area.withHeight(1.0f)); break;
        case verticalKeyboardFacingRight:   g.fillRect(area.removeFromBottom(1.0f)); break;
        default: break;
        }

        if (midiNoteNumber == getRangeEnd())
        {
            switch (currentOrientation)
            {
            case horizontalKeyboard:            g.fillRect(area.expanded(1.0f, 0).removeFromRight(1.0f)); break;
            case verticalKeyboardFacingLeft:    g.fillRect(area.expanded(0, 1.0f).removeFromBottom(1.0f)); break;
            case verticalKeyboardFacingRight:   g.fillRect(area.expanded(0, 1.0f).removeFromTop(1.0f)); break;
            default: break;
            }
        }
    }
}



void KeyboardComponent::drawBlackNote(int midiNoteNumber, juce::Graphics& g, juce::Rectangle<float> area,
    bool isDown, bool isOver, juce::Colour noteFillColour)
{
    auto c = noteFillColour;

    if (isDown)  c = c.overlaidWith(findColour(keyDownOverlayColourId));
    if (isOver)  c = c.overlaidWith(findColour(mouseOverKeyOverlayColourId));

    g.setColour(c);
    g.fillRect(area);

    auto text = getWhiteNoteText(midiNoteNumber);
    const auto currentOrientation = getOrientation();
     
    if (isDown)
    {
        g.setColour(noteFillColour);
        g.drawRect(area);
    }
    else
    {
        g.setColour(c.brighter());
        auto sideIndent = 1.0f / 8.0f;
        auto topIndent = 7.0f / 8.0f;
        auto w = area.getWidth();
        auto h = area.getHeight();

        switch (currentOrientation)
        {
        case horizontalKeyboard:            g.fillRect(area.reduced(w * sideIndent, 0).removeFromTop(h * topIndent)); break;
        case verticalKeyboardFacingLeft:    g.fillRect(area.reduced(0, h * sideIndent).removeFromRight(w * topIndent)); break;
        case verticalKeyboardFacingRight:   g.fillRect(area.reduced(0, h * sideIndent).removeFromLeft(w * topIndent)); break;
        default: break;
        }
    }

  
    if (text.isNotEmpty())
    {
        auto fontHeight = juce::jmin(11.0f, getKeyWidth() * 0.9f);

        g.setColour(juce::Colour(255,255,255));
        g.setFont(withDefaultMetrics(juce::FontOptions{ fontHeight }).withHorizontalScale(0.8f));

        switch (currentOrientation)
        {
        case horizontalKeyboard:            g.drawText(text, area.withTrimmedLeft(1.0f).withTrimmedBottom(2.0f), juce::Justification::centred, false); break;
        case verticalKeyboardFacingLeft:    g.drawText(text, area.reduced(1.0f), juce::Justification::centredLeft, false); break;
        case verticalKeyboardFacingRight:   g.drawText(text, area.reduced(1.0f), juce::Justification::centredRight, false); break;
        default: break;
        }
    }

}



void KeyboardComponent::setBaseNote(int base)
{
    baseNote = base;
}

void KeyboardComponent::setNotesPerOctave(int npo)
{
    notesPerOctave = npo;
}

