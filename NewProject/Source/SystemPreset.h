/*
  ==============================================================================

    Preset.h
    Created: 9 Jan 2021 7:11:05pm
    Author:  MT

  ==============================================================================
*/

#pragma once

class SystemPreset
{
public:
    

    enum PRESET
    {
        // Base 2, Octave size 12
        EQUAL_TEMPERAMENT = 1,
        // Francesco Antonio Vallottifs Early Eighteenth-Century Well Temperament
        WELL_TEMPERAMENT = 2,
        // 17th-centry Irregular Equal-beating mean-tone Temperament
        MEANTONE_TEMPERAMENT = 3,
        // Equal temperament represened as ratios within less than
        // 1% of Base 2, Octave size 12 equal temperament 
        JUST_INTONATION = 4,
        // Maqam (???)
        MAQUAM = 5,
        // Gamelan: Slendro (???)
        GAMELAN_SLENDRO = 6,
        // Genesis
        GENESIS = 7,
    };

private:

};
