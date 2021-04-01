/*
  ==============================================================================

    SystemMap.h
    Created: 6 Nov 2020 3:14:53pm
    Author:  MT

  ==============================================================================
*/

#pragma once
#include <iostream>
class SystemMap
{
public:
    SystemMap(double startFrequency, int startLocation, int size);
    SystemMap();
    ~SystemMap();

    double getStartFrquency();
    int getStartLocation();
    int getSize();

private:
    double startFrequency;
    int startLocation;
    int size;
};
