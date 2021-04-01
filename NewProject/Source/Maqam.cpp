/*
  ==============================================================================

    Maqam.cpp
    Created: 10 Nov 2020 11:17:13am
    Author:  Lewis Cook

  ==============================================================================
*/

#include "System.h"
#pragma once

class Maqam : public System
{
public:
	Maqam() {
		initialize();

	}

	void initialize() {
		double count = 0;
		double referencePoint = 27.5;
		for (int i = 0; i < 128; i++) {
			if (count >= 24) {
				count = 0;
				referencePoint *= 2;
				
			}
			

			float frequency = referencePoint * (pow(2, (count / 24)));
			midiMap[i] = frequency;
			count++;
			
		}

	
	}

private:
};
