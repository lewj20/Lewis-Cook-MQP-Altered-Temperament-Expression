#include "EqualTemperament.h"

	EqualTemperament::EqualTemperament(double base, double octaveSize, double startFrequency, int startLocation, int size)
		: base(base), octaveSize(octaveSize)
	{
		systemMap = new SystemMap(startFrequency, startLocation, size);
		initialize();
	}

	EqualTemperament::~EqualTemperament()
	{
		systemMap->~SystemMap();
	}

	void EqualTemperament::setBuilderSettings(double b, double os, double sf) {
		this->base = b;
		this->octaveSize = os;
		this->startFrequency = sf;
		initialize();
	}

	void EqualTemperament::initialize()
	{
		// Formula: C * B^(i / O)
		double s = -systemMap->getStartLocation();
		for (int i = 0; i < systemMap->getSize(); i++)
		{
			midiMap[i] = systemMap->getStartFrquency() * std::pow(base, s/octaveSize);
			s++;
		}
	}
