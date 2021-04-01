#include "System.h"
#pragma once

class Slendro : public System
{
public:
	Slendro() {
		initialize();

	}

	

	void initialize() {
		double count = 0;
		double referencePoint = 6.875;
		for (int i = 30; i < 128; i++) {
			if (count >= 5) {
				count = 0;
				referencePoint *= 2;
				midiMap[i] = 0;
			}
			else {
				
				float frequency = referencePoint * (pow(2, (count / 5)));
				midiMap[i] = frequency;
				count++;
			}
		}
	}

	double getCenterFrequency()
	{

		// TODO: implement (not that important, requires the map to be correct)
		return 0.0;
	}

private:
};


