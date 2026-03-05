/*
  ==============================================================================

    Scale.h
    Created: 28 Jan 2026 11:39:52am
    Author:  User

  ==============================================================================
*/

#pragma once


#include <JuceHeader.h>

class Scale
{
public:
    Scale();

    bool hasChanged{ false };
    size_t currScale{};
    int baseNote{ 69 };
    int notesPerOctave{};

    inline const juce::StringArray& getNames() { return names; }
    inline const std::vector<double>& getRatios(int idx) { return ratios[idx]; }

    void setKeyboard(std::array<double, 128>& keyboard, int idx);

private:
    void setLowerOctaves(std::array<double, 128>& keyboard, int numNotes) const;
    void setUpperOctaves(std::array<double, 128>& keyboard, int numNotes) const;

    double midiToHz(int midiNote) { return 440.0 * std::pow(2, (double)(midiNote - 69) / (double)12); }

    juce::StringArray names;
    std::vector<std::vector<double>> ratios;
    void getBinary();

};
