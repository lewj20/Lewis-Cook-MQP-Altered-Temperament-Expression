/*
  ==============================================================================

    frequencyList.cpp
    Created: 16 Nov 2020 2:17:51pm
    Author:  MT

  ==============================================================================
*/

#include "frequencyList.h"

FrequencyList::FrequencyList()
{
    frequencyList = new std::vector<double>();
}

void FrequencyList::changePreset(double preset[])
{
    for (int i = 0; i < System::SYSTEM_SIZE::MIDI; i++)
    {
        this->preset[i] = preset[i];
    }
}

void FrequencyList::processNextMidiBuffer(juce::MidiBuffer& buffer, const int startSample, const int numSamples)
{
    for (const auto metadata : buffer)
    {
        processNextMidiMessage(metadata.getMessage());
    }
        
   
}

void FrequencyList::processNextMidiMessage(const juce::MidiMessage& message)
{
    if (message.isNoteOn())
    {
        // push the frequency into the list
        frequencyList->push_back(preset[message.getNoteNumber()]);
    }
    
}

std::vector<double>* FrequencyList::getList()
{
    return frequencyList;
}
