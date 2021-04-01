/*
  ==============================================================================

    SystemMap.cpp
    Created: 6 Nov 2020 3:14:53pm
    Author:  MT

  ==============================================================================
*/


#include "SystemMap.h"

SystemMap::SystemMap(double startFrequency, int startLocation, int size)
    : startFrequency(startFrequency), startLocation(startLocation), size(size)
{}

SystemMap::SystemMap()
{
    startFrequency = 440;
    startLocation = 69;
    size = 127;
}

SystemMap::~SystemMap()
{
}

double SystemMap::getStartFrquency()    { return this->startFrequency; }
int SystemMap::getStartLocation()       { return this->startLocation; }
int SystemMap::getSize()                { return this->size; }
