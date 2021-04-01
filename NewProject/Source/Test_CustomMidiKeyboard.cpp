/*
  ==============================================================================

    UI_unitTesting.cpp
    Created: 28 Oct 2020 4:06:21pm
    Author:  MT

  ==============================================================================
*/

#include "Test_CustomMidiKeyboard.h"

testing::Test_CustomMidiKeyboard::Test_CustomMidiKeyboard(Tuning::Structures::KeyboardLayout* keyboardLayoutIn, juce::ComboBox* testBoxIn)
    : keyboardLayout(keyboardLayoutIn), testBox(testBoxIn)
{
    // Each item is a test case
    testBox->addItem("none", TEST_NONE);
    testBox->addItem("disableKeyPerOctave", TEST_MIDI_KEYBOARD::T_1);
    testBox->addItem("whiteKeyLayout12NotesPerOctave", TEST_MIDI_KEYBOARD::T_2);
    testBox->addItem("whiteKeyLayoutAnyNotesPerOctave", TEST_MIDI_KEYBOARD::T_3);
    testBox->addItem("Total128Notes", TEST_MIDI_KEYBOARD::T_4);
    testBox->addItem("TotalAnyNotes", TEST_MIDI_KEYBOARD::T_5);
    testBox->addItem("customLayout", TEST_MIDI_KEYBOARD::T_6);

    testBox->onChange = [this] { testSelect(); };

    testBox->setSelectedId(TEST_NONE);
}

testing::Test_CustomMidiKeyboard::~Test_CustomMidiKeyboard()
{

}

void testing::Test_CustomMidiKeyboard::testSelect()
{
    switch (testBox->getSelectedId())
    {
        case TEST_NONE: reset(); break;
        case TEST_MIDI_KEYBOARD::T_1: disableKeyPerOctave(); break;
        case TEST_MIDI_KEYBOARD::T_2: whiteKeyLayout12NotesPerOctave(); break;
        case TEST_MIDI_KEYBOARD::T_3: whiteKeyLayoutAnyNotesPerOctave(); break;
        case TEST_MIDI_KEYBOARD::T_4: Total128Notes(); break;
        case TEST_MIDI_KEYBOARD::T_5: TotalAnyNotes(); break;
        case TEST_MIDI_KEYBOARD::T_6: customLayout(); break;
        default: break;
    }
}

// For each of these tests the enabled/disabled keys should work with 
// 1. clicking events
// 2. MIDI input (should not work with notes above 127)
// 3. keyboard input "awsedftgyhujkolp;" (default, would take more work to make re-configurable)

// TODO: key naming is not yet implemented

void testing::Test_CustomMidiKeyboard::reset()
{
    keyboardLayout->setWhiteNotes({ 0, 2, 4, 5, 7, 9, 11 });
    keyboardLayout->setBlackNotes({ 1, 3, 6, 8, 10 });
    keyboardLayout->setDisabledNotes({});
    keyboardLayout->setRangeStart(0);
    keyboardLayout->setRangeEnd(127);
    keyboardLayout->setNotesPerOctave(12);
}

void testing::Test_CustomMidiKeyboard::disableKeyPerOctave()
{
    keyboardLayout->setWhiteNotes({ 0, 2, 4, 5, 7, 9, 11 });
    keyboardLayout->setBlackNotes({ 1, 3, 6, 8, 10 });
    keyboardLayout->setDisabledNotes({ 4, 10 });
    keyboardLayout->setRangeStart(0);
    keyboardLayout->setRangeEnd(127);
    keyboardLayout->setNotesPerOctave(12);
}

void testing::Test_CustomMidiKeyboard::whiteKeyLayout12NotesPerOctave()
{
    keyboardLayout->setWhiteNotes({ 0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11 });
    keyboardLayout->setBlackNotes({});
    keyboardLayout->setDisabledNotes({});
    keyboardLayout->setRangeStart(0);
    keyboardLayout->setRangeEnd(127);
    keyboardLayout->setNotesPerOctave(12);
}

void testing::Test_CustomMidiKeyboard::whiteKeyLayoutAnyNotesPerOctave()
{
    /*
    constexpr auto ANY = 15;
    juce::Array<juce::uint8> whiteNotes = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    juce::Array<juce::uint8> blackNotes = {};
    juce::Array<juce::uint8> disabledNotes = {};
    Tuning::Structures::KeyboardLayout layout{ keyboard, whiteNotes, blackNotes, disabledNotes, 0, ANY, 1 };
    whiteNotes->~Array();
    blackNotes->~Array();
    disabledNotes->~Array();
    */
}

void testing::Test_CustomMidiKeyboard::Total128Notes()
{
    keyboardLayout->setWhiteNotes({ 0, 2, 4, 5, 7, 9, 11 });
    keyboardLayout->setBlackNotes({ 1, 3, 6, 8, 10 });
    keyboardLayout->setDisabledNotes({});
    keyboardLayout->setRangeStart(0);
    keyboardLayout->setRangeEnd(127);
    keyboardLayout->setNotesPerOctave(12);
}

void testing::Test_CustomMidiKeyboard::TotalAnyNotes()
{
    constexpr auto ANY = 88;
    keyboardLayout->setWhiteNotes({ 0, 2, 4, 5, 7, 9, 11 });
    keyboardLayout->setBlackNotes({ 1, 3, 6, 8, 10 });
    keyboardLayout->setDisabledNotes({});
    keyboardLayout->setRangeStart(0);
    keyboardLayout->setRangeEnd(ANY);
    keyboardLayout->setNotesPerOctave(12);
}

void testing::Test_CustomMidiKeyboard::PianoLayout()
{
    /*
    juce::Array<juce::uint8> whiteNotes = { 0, 2, 4, 5, 7, 9, 11 };
    juce::Array<juce::uint8> blackNotes = { 1, 3, 6, 8, 10 };
    juce::Array<juce::uint8> disabledNotes = {};
    Tuning::Structures::KeyboardLayout layout{ keyboard, whiteNotes, blackNotes, disabledNotes, 0, 127, 12 };
    whiteNotes->~Array();
    blackNotes->~Array();
    disabledNotes->~Array();
    */
}

void testing::Test_CustomMidiKeyboard::customLayout()
{
    /*
    juce::Array<juce::uint8> whiteNotes = { 0, 1, 4, 8, 9, 11 };
    juce::Array<juce::uint8> blackNotes = { 2, 3, 5, 6, 7, 10 };
    juce::Array<juce::uint8> disabledNotes = {};
    Tuning::Structures::KeyboardLayout layout{ keyboard, whiteNotes, blackNotes, disabledNotes, 0, 127, 12 };
    whiteNotes->~Array();
    blackNotes->~Array();
    disabledNotes->~Array();
    */
}
