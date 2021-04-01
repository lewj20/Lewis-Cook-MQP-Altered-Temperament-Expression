/*
  ==============================================================================

    OneOctaveSample.h
    Created: 10 Nov 2020 10:02:19am
    Author:  MT

    Covers any system that can be built with a one octave sample
    For now the systems are hard-coded.

  ==============================================================================
*/

#pragma once
#include "System.h"

class OneOctaveSample : public System
{
public:
    OneOctaveSample(double sampleList[], int octaveSize, double startFrequency, int startLocation, int size);
    ~OneOctaveSample();
    void initialize();

private:
    double* sampleList;
    int octaveSize;
};
