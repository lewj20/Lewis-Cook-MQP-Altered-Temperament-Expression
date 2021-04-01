/*
  ==============================================================================

    OneOctaveSample.cpp
    Created: 10 Nov 2020 9:49:13am
    Author:  MT

  ==============================================================================
*/
#include "OneOctaveSample.h"

OneOctaveSample::OneOctaveSample(double sampleList[], int octaveSize, double startFrequency, int startLocation, int size)
    :sampleList(sampleList), octaveSize(octaveSize)
{
    systemMap = new SystemMap(startFrequency, startLocation, size);
    initialize();
}

OneOctaveSample::~OneOctaveSample()
{
    free(sampleList);
}

void OneOctaveSample::initialize()
{
    // Added a simple start
    midiMap[0] = systemMap->getStartFrquency();
    int sampleIndex = 0;
    double sampleStartValue = midiMap[0];

    for (int i = 1; i < systemMap->getSize(); i++)
    {
        if (sampleIndex == octaveSize)
        {
            sampleStartValue = midiMap[i-1];

            sampleIndex = 0;
        }

        midiMap[i] = sampleList[sampleIndex] * sampleStartValue;

        double v = sampleList[sampleIndex];

        sampleIndex++;
    }
    // TODO: create this method
}
