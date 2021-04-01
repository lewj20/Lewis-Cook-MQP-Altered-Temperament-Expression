/*
  ==============================================================================

    System.h
    Created: 6 Nov 2020 2:34:30pm
    Author:  MT

  ==============================================================================
*/

#include "SystemMap.h"

#pragma once
class System
{
public:
    const static int START_FREQUENCY_MIDI = 440;
    const static int START_LOCATION_MIDI = 69;
    const static int SYSTEM_SIZE_MIDI = 128;

    // Common methods
    SystemMap* getSystemMap();
    double* getMidiMap();
    
    virtual void initialize() = 0;
    virtual ~System() = 0;
   
    // TODO: not sure if these should be private or protected
protected:
    SystemMap* systemMap;
    double midiMap[SYSTEM_SIZE_MIDI];
};

