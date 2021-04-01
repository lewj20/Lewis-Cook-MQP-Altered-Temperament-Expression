/*
  ==============================================================================

    UI_unitTesting.h
    Created: 28 Oct 2020 4:06:21pm
    Author:  MT
    
    This class is a testing suite for UI functions added to the keyboard.
    Adding it creates a combo box at the top of the screen. Each entry is
    a test case. Each case should be display how the test case is named.

  ==============================================================================
*/
#include <JuceHeader.h>
#include "Test_UI.h"
#include "KeyboardLayout.h"
#pragma once

enum TEST_MIDI_KEYBOARD
{
    T_1 = 2,
    T_2 = 3,
    T_3 = 4,
    T_4 = 5,
    T_5 = 6,
    T_6 = 7,
};

namespace testing
{
    //==============================================================================
    /**
    */
    class Test_CustomMidiKeyboard : Test_UI
    {
    public:
        Test_CustomMidiKeyboard(Tuning::Structures::KeyboardLayout* keyboardLayoutIn, juce::ComboBox* testBoxIn);
        ~Test_CustomMidiKeyboard();

        // Test case selector
        void testSelect();

    private:
        Tuning::Structures::KeyboardLayout* keyboardLayout;
        juce::ComboBox* testBox;
        
        // Test case methods
        void reset() override;
        void disableKeyPerOctave();
        void whiteKeyLayout12NotesPerOctave();
        void whiteKeyLayoutAnyNotesPerOctave();
        void Total128Notes();
        void TotalAnyNotes();
        void PianoLayout();
        void customLayout();
    };
}
