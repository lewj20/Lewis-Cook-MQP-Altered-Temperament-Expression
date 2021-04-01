/*
  ==============================================================================

    SystemBuilder.cpp
    Created: 11 Nov 2020 12:05:36am
    Author:  MT

  ==============================================================================
*/

#include "SystemBuilder.h"

System* SystemBuilder::makeEqualTemperament()
{
    return new EqualTemperament(2, 12, System::START_FREQUENCY_MIDI, System::START_LOCATION_MIDI, System::SYSTEM_SIZE_MIDI);
}

System* SystemBuilder::makeEqualTemperament(float base, float octaveSize, float startFrequency)
{
    return new EqualTemperament(base, octaveSize, startFrequency, System::START_LOCATION_MIDI, System::SYSTEM_SIZE_MIDI);
}

System* SystemBuilder::makeWellTemperament()
{
    return new OneOctaveSample(WELL_TEMPERAMENT_SAMPLE, WELL_TEMPERAMENT_SIZE, 6.875, 0, System::SYSTEM_SIZE_MIDI);
}

System* SystemBuilder::makeMeanToneTemperament()
{
    return new OneOctaveSample(MEANTONE_TEMPERAMENT_SAMPLE, MEANTONE_TEMPERAMENT_SIZE, 6.875, 0, System::SYSTEM_SIZE_MIDI);
}

System* SystemBuilder::makeJustIntonation()
{
    return new OneOctaveSample(SystemBuilder::JUST_INTONATION_SAMPLE, JUST_INTONATION_SIZE, 6.875, 0, System::SYSTEM_SIZE_MIDI);
}

System* SystemBuilder::makeMaqam()
{
    return new EqualTemperament(2, 24, 27.5, 0, System::SYSTEM_SIZE_MIDI);
}

System* SystemBuilder::makeGamelanSlendro()
{
    return new Slendro();
}

System* SystemBuilder::makeHarryPartch()
{
    return new OneOctaveSample(GENESIS_SAMPLE, GENESIS_SIZE, 110, 0, System::SYSTEM_SIZE_MIDI);
}
