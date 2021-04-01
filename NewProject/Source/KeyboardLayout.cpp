/*
  ==============================================================================

    Layout.cpp
    Created: 28 Oct 2020 9:10:19pm
    Author:  MT

  ==============================================================================
*/

#include "KeyboardLayout.h"

Tuning::Structures::KeyboardLayout::KeyboardLayout(juce::MidiKeyboardComponent* keyboard, juce::Array<juce::uint8> whiteNotes, juce::Array<juce::uint8> blackNotes, juce::Array<juce::uint8> disabledNotes, int rangeStart, int rangeEnd, int notesPerOctave)
    : keyboard(keyboard), whiteNotes(whiteNotes), blackNotes(blackNotes), disabledNotes(disabledNotes), rangeStart(rangeStart), rangeEnd(rangeEnd), notesPerOctave(notesPerOctave)
{
    updateLayout();
}

Tuning::Structures::KeyboardLayout::KeyboardLayout(juce::MidiKeyboardComponent* keyboard)
    : keyboard(keyboard)
{
    whiteNotes = { 0, 2, 4, 5, 7, 9, 11 };
    blackNotes = { 1, 3, 6, 8, 10 };
    disabledNotes = {};
    rangeStart = 0;
    rangeEnd = 127;
    notesPerOctave = 12;

    updateLayout();
}

Tuning::Structures::KeyboardLayout::~KeyboardLayout()
{
    //whiteNotes.~Array();
    //blackNotes.~Array();
    //disabledNotes.~Array();
}

//==============================================================================
juce::Array<juce::uint8> Tuning::Structures::KeyboardLayout::getWhiteNotes()    { return whiteNotes; }
juce::Array<juce::uint8> Tuning::Structures::KeyboardLayout::getBlackNotes()    { return blackNotes; }
juce::Array<juce::uint8> Tuning::Structures::KeyboardLayout::getDisabledNotes() { return disabledNotes; }
int Tuning::Structures::KeyboardLayout::getRangeStart()                         { return rangeStart; }
int Tuning::Structures::KeyboardLayout::getRangeEnd()                           { return rangeEnd; }
int Tuning::Structures::KeyboardLayout::getNotesPerOctave()                     { return notesPerOctave; }

void Tuning::Structures::KeyboardLayout::setWhiteNotes(juce::Array<juce::uint8> whiteNotesIn)
{ 
    whiteNotes = whiteNotesIn; 
    updateLayout();
}

void Tuning::Structures::KeyboardLayout::setBlackNotes(juce::Array<juce::uint8> blackNotesIn)
{ 
    blackNotes = blackNotesIn; 
    updateLayout();
}

void Tuning::Structures::KeyboardLayout::setDisabledNotes(juce::Array<juce::uint8> disabledNotesIn)   
{ 
    disabledNotes = disabledNotesIn;
    updateLayout();
}
void Tuning::Structures::KeyboardLayout::setRangeStart(int rangeStartIn)
{
    rangeStart = rangeStartIn;
    updateLayout();
}

void Tuning::Structures::KeyboardLayout::setRangeEnd(int rangeEndIn)
{
    rangeEnd = rangeEndIn;
    updateLayout();
}

void Tuning::Structures::KeyboardLayout::setNotesPerOctave(int notesPerOctaveIn)
{
    notesPerOctave = notesPerOctaveIn;
    updateLayout();
}

//==============================================================================
void Tuning::Structures::KeyboardLayout::updateLayout()
{
    keyboard->setAvailableRange(rangeStart, rangeEnd);
    
    // It's a lot harder to make this work
    // Gonna have to change the layout for how this is drawn
    keyboard->setNotes(whiteNotes, blackNotes);
    keyboard->setDisabledNotes(disabledNotes);

    // TODO: add an update function to the keyboard componet
}
