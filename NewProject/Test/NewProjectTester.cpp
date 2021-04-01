#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <EqualTemperament.h>
#include <EqualTemperament.cpp>
#include <System.h>
#include <System.cpp>
#include <SystemMap.h>
#include <SystemMap.cpp>
#include <OneOctaveSample.h>
#include <OneOctaveSample.cpp>
#include <Gamelan.cpp>



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NewProjectTester
{


	TEST_CLASS(NewProjectTester)
	{
	public:

		// #1 Standard midi equal temperament
		TEST_METHOD(System_EqualTemperament_StandardMIDI)
		{
			EqualTemperament* eqt = new EqualTemperament(2, 12, 440, 69, 128);
			double SPACING = std::pow(2.0, 1.0 / 12.0);
			double* midiMap = eqt->getMidiMap();

			for (int i = 0; i < 127; i++)
			{
				Assert::AreEqual(SPACING, midiMap[i + 1] / midiMap[i], 0.001);
			}
			
			// Specific parts
			Assert::AreEqual(8.176, midiMap[0], 0.01);
			Assert::AreEqual(261.63, midiMap[60], 0.01);
			Assert::AreEqual(440.00, midiMap[69], 0.01);
			Assert::AreEqual(12543.9, midiMap[127], 0.1);

			eqt->~EqualTemperament();
		}
		
		// #2 Equal temperament with any tones per octave
		TEST_METHOD(System_EqualTemperament_AnyTonesPerOctave)
		{
			double ANY = 17;
			EqualTemperament* eqt = new EqualTemperament(2, ANY, 440, 69, 128);
			double SPACING = std::pow(2.0, 1.0 / ANY);
			double* midiMap = eqt->getMidiMap();

			for (int i = 0; i < 127; i++)
			{
				Assert::AreEqual(SPACING, midiMap[i + 1] / midiMap[i], 0.001);
			}

			eqt->~EqualTemperament();
		}
		
		// #3 Equal temperament with any size base
		TEST_METHOD(System_EqualTemperament_AnySizeBase)
		{
			double ANY = 7;
			EqualTemperament* eqt = new EqualTemperament(ANY, 12, 440, 69, 128);
			double SPACING = std::pow(ANY, 1.0 / 12.0);
			double* midiMap = eqt->getMidiMap();

			for (int i = 0; i < 127; i++)
			{
				Assert::AreEqual(SPACING, midiMap[i + 1] / midiMap[i], 0.001);
			}

			eqt->~EqualTemperament();
		}

		// #4 One octave sample for Just intonation
	TEST_METHOD(System_OneOctaveSample_JustIntonation)
		{
			constexpr auto JUST_INTONATION_SIZE = 12;
			double JUST_INTONATION_SAMPLE[JUST_INTONATION_SIZE] = {16.0/15.0, 9.0/8.0, 6.0/5.0, 5.0/4.0, 
				4.0/3.0, 17.0/12.0, 3.0/2.0, 8.0/5.0, 5.0/3.0, 16.0/9.0, 15.0/8.0, 2};
			OneOctaveSample* system = new OneOctaveSample(JUST_INTONATION_SAMPLE, JUST_INTONATION_SIZE, 8.176, 0, 128);
			double* midiMap = system->getMidiMap();

			int s = 0;
			// At 122, something weird happens
			for (int i = 0; i < 128; i += JUST_INTONATION_SIZE)
			{
				//Logger::WriteMessage
				for (int s = 0; s < JUST_INTONATION_SIZE; s++)
				{	
					// When another sample cannot fit fully
					if (i + s + 1 == 128)
					{
						break;
					}

					Assert::AreEqual(JUST_INTONATION_SAMPLE[s], midiMap[i + s + 1] / midiMap[i], 0.001);
				}
			}

			// TODO: should be fixed in main
			//system->~OneOctaveSample();
		}
		
		// #5 One octave sample for Well Temperament
		TEST_METHOD(System_OneOctaveSample_WellTemperament)
		{
			constexpr auto WELL_TEMPERAMENT_SIZE = 12;
			double WELL_TEMPERAMENT_SAMPLE[WELL_TEMPERAMENT_SIZE] = {
				1.063329484, 1.120608339, 1.193686502, 1.26068438, 1.336679365,
				1.417772645, 1.497490482, 1.594994225, 1.680912507, 1.78558518,
				1.891026569, 2.0
			};
			OneOctaveSample* system = new OneOctaveSample(WELL_TEMPERAMENT_SAMPLE, WELL_TEMPERAMENT_SIZE, 8.176, 0, 128);
			double* midiMap = system->getMidiMap();

			int s = 0;
			// At 122, something weird happens
			for (int i = 0; i < 128; i += WELL_TEMPERAMENT_SIZE)
			{
				//Logger::WriteMessage
				for (int s = 0; s < WELL_TEMPERAMENT_SIZE; s++)
				{
					// When another sample cannot fit fully
					if (i + s + 1 == 128)
					{
						break;
					}

					Assert::AreEqual(WELL_TEMPERAMENT_SAMPLE[s], midiMap[i + s + 1] / midiMap[i], 0.001);
				}
			}

			// TODO: should be fixed in main
			//system->~OneOctaveSample();
		}

		// #6 One Octave Sample Meantone
		TEST_METHOD(System_OneOctaveSample_MeanTone)
		{
			constexpr auto MEANTONE_TEMPERAMENT_SIZE = 12;
			double MEANTONE_TEMPERAMENT_SAMPLE[MEANTONE_TEMPERAMENT_SIZE] =
			{
				1.068168972, 1.119690594, 1.196089683, 1.253724131, 1.337600314,
				1.428492274, 1.49679977, 1.599053223, 1.675899158, 1.787734062,
				1.874185735, 2.0
			};
			OneOctaveSample* system = new OneOctaveSample(MEANTONE_TEMPERAMENT_SAMPLE, MEANTONE_TEMPERAMENT_SIZE, 8.176, 0, 128);
			double* midiMap = system->getMidiMap();

			int s = 0;
			// At 122, something weird happens
			for (int i = 0; i < 128; i += MEANTONE_TEMPERAMENT_SIZE)
			{
				//Logger::WriteMessage
				for (int s = 0; s < MEANTONE_TEMPERAMENT_SIZE; s++)
				{
					// When another sample cannot fit fully
					if (i + s + 1 == 128)
					{
						break;
					}

					Assert::AreEqual(MEANTONE_TEMPERAMENT_SAMPLE[s], midiMap[i + s + 1] / midiMap[i], 0.001);
				}
			}

			// TODO: should be fixed in main
			//system->~OneOctaveSample();
		}
		 
		// #7 One Octave Sample Genesis
		TEST_METHOD(System_OneOctaveSample_Genesis)
		{
			constexpr auto GENESIS_SIZE = 43;
			double GENESIS_SAMPLE[GENESIS_SIZE] =
			{
				81.0/80.0, 33.0/32.0, 21.0/20.0, 16.0/15.0, 12.0/11.0,
				11.0/10.0, 10.0/9.0, 9.0/8.0, 8.0/7.0, 7.0/6.0, 32.0/27.0,
				6.0/5.0, 11.0/9.0, 5.0/4.0, 14.0/11.0, 9.0/7.0, 21.0/16.0,
				4.0/3.0, 27.0/20.0, 11.0/8.0, 7.0/5.0, 10.0/7.0, 16.0/11.0,
				40.0/27.0, 3.0/2.0, 32.0/21.0, 14.0/9.0, 11.0/7.0, 8.0/5.0,
				18.0/11.0, 5.0/3.0, 27.0/16.0, 12.0/7.0, 7.0/4.0, 16.0/9.0,
				9.0/5.0, 20.0/11.0, 11.0/6.0, 15.0/8.0, 40.0/21.0, 64.0/33.0,
				160.0/81.0, 2.0
			};
			OneOctaveSample* system = new OneOctaveSample(GENESIS_SAMPLE, GENESIS_SIZE, 8.176, 0, 128);
			double* midiMap = system->getMidiMap();

			int s = 0;
			// At 122, something weird happens
			for (int i = 0; i < 128; i += GENESIS_SIZE)
			{
				//Logger::WriteMessage
				for (int s = 0; s < GENESIS_SIZE; s++)
				{
					// When another sample cannot fit fully
					if (i + s + 1 == 128)
					{
						break;
					}

					Logger::WriteMessage(std::to_string(midiMap[i + s + 1]).append("\n").c_str());

					Assert::AreEqual(GENESIS_SAMPLE[s], midiMap[i + s + 1] / midiMap[i], 0.001);
				}
			}

			// TODO: should be fixed in main
			//system->~OneOctaveSample();
		}

		// #8 Equal Temperament Maquam
		TEST_METHOD(System_EqualTemperament_Maquam)
		{
			EqualTemperament* eqt = new EqualTemperament(2, 24, 27.5, 0, 128);
			double SPACING = std::pow(2.0, 1.0 / 24.0);
			double* midiMap = eqt->getMidiMap();

			for (int i = 0; i < 127; i++)
			{
				Assert::AreEqual(SPACING, midiMap[i + 1] / midiMap[i], 0.001);
			}

			eqt->~EqualTemperament();
		}
	
		// #9 Gamelan Selendro
		TEST_METHOD(System_Gamelan)
		{
			Slendro* system = new Slendro();
			double SPACING = std::pow(2.0, 1.0 / 5.0);
			double* midiMap = system->getMidiMap();

			// Selendro has a custom layout, but is still 5 tone equal temperament
			double count = 0;
			double referencePoint = 6.875;

			for (int i = 30; i < 127; i++)
			{
				if (count >= 5)
				{
					count = 0;
					referencePoint *= 2;

					// These tones are disabled, so they should be 0
					Assert::AreEqual(0, midiMap[i], 0.001);
				}
				else
				{
					count++;

					// Make sure we only test intervals where the tones exist
					if (count < 5)
					{
						Assert::AreEqual(SPACING, midiMap[i + 1] / midiMap[i], 0.001);
					}
				}
			}

			// TODO: add destructor after merge
			//system->~System();
		}
	};
}
