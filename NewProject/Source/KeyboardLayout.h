/*
  ==============================================================================

    Layout.h
    Created: 28 Oct 2020 9:10:19pm
    Author:  MT

  ==============================================================================
*/

#include <JuceHeader.h>
#pragma once

namespace Tuning
{
    namespace Structures
    {
        class KeyboardLayout
        {
        public:
            KeyboardLayout( juce::MidiKeyboardComponent* keyboard,
                            juce::Array<juce::uint8> whiteNotes,
                            juce::Array<juce::uint8> blackNotes,
                            juce::Array<juce::uint8> disabledNotes,
                            int rangeStart,
                            int rangeEnd,
                            int notesPerOctave);
            KeyboardLayout(juce::MidiKeyboardComponent* keyboard);
            ~KeyboardLayout();

            juce::Array<juce::uint8> getWhiteNotes ();
            juce::Array<juce::uint8> getBlackNotes ();
            juce::Array<juce::uint8> getDisabledNotes ();
            int getRangeStart ();
            int getRangeEnd ();
            int getNotesPerOctave ();
            void setWhiteNotes (juce::Array<juce::uint8> whiteNotes);
            void setBlackNotes (juce::Array<juce::uint8> blackNotes);
            void setDisabledNotes (juce::Array<juce::uint8> disabledNotes);
            void setRangeStart (int rangeStart);
            void setRangeEnd (int rangeEnd);
            void setNotesPerOctave (int notesPerOctave);

        private:
            void updateLayout ();

            juce::MidiKeyboardComponent* keyboard;
            juce::Array<juce::uint8> whiteNotes;
            juce::Array<juce::uint8> blackNotes;
            juce::Array<juce::uint8> disabledNotes;
            int rangeStart;
            int rangeEnd;
            int notesPerOctave;
        };
    }
}  