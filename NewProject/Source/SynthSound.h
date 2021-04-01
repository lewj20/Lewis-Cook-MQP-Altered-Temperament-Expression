/*
  ==============================================================================

    SynthSound.h
    Created: 29 Oct 2020 1:00:50pm
    Author:  Lewis Cook

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote(int /*midiNoteNumber*/)
    {
        return true;
    }

    bool appliesToChannel(int /*midiChannel*/)
    {
        return true;
    }
};
