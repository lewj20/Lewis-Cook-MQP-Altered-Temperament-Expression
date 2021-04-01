/*
  ==============================================================================

    SystemBuilder.h
    Created: 11 Nov 2020 12:05:36am
    Author:  MT

    Builds and supplies a system based on a preset number.
    For now the instructions are hard-coded, but any complexity or other methods
    can be loaded behind this static class.

    Note that these presets are only versions of each system. 
    So this system is not very efficient.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "System.h"
#include "EqualTemperament.h"
#include "OneOctaveSample.h"

#include "Maqam.cpp"
#include "Gamelan.cpp"

constexpr auto WELL_TEMPERAMENT_SIZE = 12;
constexpr auto MEANTONE_TEMPERAMENT_SIZE = 12;
constexpr auto JUST_INTONATION_SIZE = 12;
constexpr auto GENESIS_SIZE = 43;


class SystemBuilder
{
public:
    System* makeEqualTemperament(); 
    System* makeEqualTemperament(float base, float octaveSize, float startFrequency);
    System* makeWellTemperament();
    System* makeMeanToneTemperament();
    System* makeJustIntonation();
    System* makeMaqam();
    System* makeGamelanSlendro();
    System* makeHarryPartch();

private:
    // preset values (TODO: should be moved into some other medium)
    double WELL_TEMPERAMENT_SAMPLE[WELL_TEMPERAMENT_SIZE] = 
    { 
        1.063329484, 1.120608339, 1.193686502, 1.26068438, 1.336679365,
        1.417772645, 1.497490482, 1.594994225, 1.680912507, 1.78558518,
        1.891026569, 2.0 
    };

    double MEANTONE_TEMPERAMENT_SAMPLE[MEANTONE_TEMPERAMENT_SIZE] =
    { 
        1.068168972, 1.119690594, 1.196089683, 1.253724131, 1.337600314,
        1.428492274, 1.49679977, 1.599053223, 1.675899158, 1.787734062,
        1.874185735, 2.0 
    };

    double JUST_INTONATION_SAMPLE[JUST_INTONATION_SIZE] = 
    {   
        16.0 / 15.0, 9.0 / 8.0, 6.0 / 5.0, 5.0 / 4.0, 4.0 / 3.0,
        17.0 / 12.0, 3.0 / 2.0, 8.0 / 5.0, 5.0 / 3.0, 16.0 / 9.0,
        15.0 / 8.0, 2.0 
    };

    double GENESIS_SAMPLE[GENESIS_SIZE] =
    {
        81.0 / 80.0, 33.0 / 32.0, 21.0 / 20.0, 16.0 / 15.0, 12.0 / 11.0,
        11.0 / 10.0, 10.0 / 9.0, 9.0 / 8.0, 8.0 / 7.0, 7.0 / 6.0, 32.0 / 27.0,
        6.0 / 5.0, 11.0 / 9.0, 5.0 / 4.0, 14.0 / 11.0, 9.0 / 7.0, 21.0 / 16.0,
        4.0 / 3.0, 27.0 / 20.0, 11.0 / 8.0, 7.0 / 5.0, 10.0 / 7.0, 16.0 / 11.0,
        40.0 / 27.0, 3.0 / 2.0, 32.0 / 21.0, 14.0 / 9.0, 11.0 / 7.0, 8.0 / 5.0,
        18.0 / 11.0, 5.0 / 3.0, 27.0 / 16.0, 12.0 / 7.0, 7.0 / 4.0, 16.0 / 9.0,
        9.0 / 5.0, 20.0 / 11.0, 11.0 / 6.0, 15.0 / 8.0, 40.0 / 21.0, 64.0 / 33.0,
        160.0 / 81.0, 2.0


        /*
        1, (pow(2, (21.5 / 1200))), (pow(2, (53.2 / 1200))), (pow(2, (84.5 / 1200))),
        (pow(2, (111.7 / 1200))), (pow(2, (150.6 / 1200))), (pow(2, (165.0 / 1200))), 
        (pow(2, (182.4 / 1200))), (pow(2, (203.9 / 1200))), (pow(2, (231.2 / 1200))), 
        (pow(2, (266.9 / 1200))), (pow(2, (294.1 / 1200))), (pow(2, (315.6 / 1200))),
        (pow(2, (347.4 / 1200))), (pow(2, (386.3 / 1200))), (pow(2, (417.5 / 1200))),
        (pow(2, (435.1 / 1200))), (pow(2, (470.8 / 1200))), (pow(2, (498.0 / 1200))),
        (pow(2, (519.5 / 1200))), (pow(2, (551.3 / 1200))),(pow(2, (582.5 / 1200))),
        (pow(2, (617.5 / 1200))), (pow(2, (648.7 / 1200))), (pow(2, (680.5 / 1200))),
        (pow(2, (702.0 / 1200))), (pow(2, (729.2 / 1200))), (pow(2, (764.9 / 1200))),
        (pow(2, (782.5 / 1200))), (pow(2, (813.7 / 1200))), (pow(2, (852.6 / 1200))), 
        (pow(2, (884.4 / 1200))), (pow(2, (905.9 / 1200))), (pow(2, (933.1 / 1200))),
        (pow(2, (968.8 / 1200))), (pow(2, (996.1 / 1200))), (pow(2, (1017.6 / 1200))), 
        (pow(2, (1035.0 / 1200))), (pow(2, (1049.4 / 1200))), (pow(2, (1088.3 / 1200))),
        (pow(2, (1115.5 / 1200))), (pow(2, (1146.8 / 1200))), (pow(2, (1178.5 / 1200)))
        */
    };
    
    int currentPresetNumber;
    System* system;
};