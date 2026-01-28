/*
  ==============================================================================

    Scale.cpp
    Created: 28 Jan 2026 11:39:52am
    Author:  User

  ==============================================================================
*/

#include "Scale.h"

Scale::Scale()
{
}


void Scale::setKeyboard(std::array<double, 128>& keyboard, int idx)
{

    int numNotes = (int)ratios[idx].size();

    notesPerOctave = numNotes; //need to clean this up

    if (baseNote > 127 - ratios[idx].size() || baseNote < 1)
        return;

    double baseFreq = midiToHz(baseNote);

    for (size_t i{}; i < numNotes; ++i)
        keyboard[baseNote + i] = ratios[idx][i] * baseFreq;

    setLowerOctaves(keyboard, numNotes);
    setUpperOctaves(keyboard, numNotes);

}

void Scale::setLowerOctaves(std::array<double, 128>& keyboard, int numNotes) const
{
    int fundamental = baseNote - numNotes;

    while (fundamental >= 0)
    {
        for (size_t i = 0; i < numNotes; ++i)
            keyboard[fundamental + i] = keyboard[fundamental + i + numNotes] / 2.0;

        fundamental -= numNotes;
    }

    // Fill in remaining values
    if (fundamental != 0)
    {
        fundamental += numNotes;

        for (size_t i = 0; i < fundamental; ++i)
            keyboard[i] = keyboard[i + numNotes] / 2.0;
    }
}

void Scale::setUpperOctaves(std::array<double, 128>& keyboard, int numNotes) const
{
    int fundamental = baseNote + numNotes;

    while (fundamental <= 127 - numNotes)
    {
        for (size_t i = 0; i < numNotes; ++i)
            keyboard[fundamental + i] = keyboard[fundamental + i - numNotes] * 2.0;

        fundamental += numNotes;
    }

    if (fundamental > 127 - numNotes)
        for (size_t i = fundamental; i <= 127; ++i)
            keyboard[i] = keyboard[i - numNotes] * 2.0;
}

