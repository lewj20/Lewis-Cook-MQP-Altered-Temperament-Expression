/*
  ==============================================================================

    frequencyList.h
    Created: 16 Nov 2020 2:17:51pm
    Author:  MT

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "System.h"

class FrequencyList
{
public:
    FrequencyList();

    void changePreset(double preset[]);
    void processNextMidiBuffer(juce::MidiBuffer& buffer, const int startSample, const int numSamples);
    void processNextMidiMessage(const juce::MidiMessage& message);

    std::vector<double>* getList();

private:
    double preset[System::SYSTEM_SIZE::MIDI] = {};
    std::vector<double>* frequencyList;
    
};