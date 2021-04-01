/*
  ==============================================================================

    System.cpp
    Created: 6 Nov 2020 2:34:30pm
    Author:  MT

  ==============================================================================
*/

#include "System.h"

System::~System()
{
   
}

SystemMap* System::getSystemMap()
{
    return systemMap;
}

double* System::getMidiMap()
{
    return midiMap;
}
