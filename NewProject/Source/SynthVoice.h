/*
  ==============================================================================

    SynthVoice.h
    Created: 29 Oct 2020 1:01:04pm
    Author:  Lewis Cook

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include "Maximilian/src/maximilian.h"
#include "SystemBuilder.h"
#include "System.h"

class SynthVoice : public juce::SynthesiserVoice 
{
    public:
        // Synth controls
        // @see juce_Synthesizer

        ~SynthVoice();
        bool canPlaySound(juce::SynthesiserSound* sound);
        void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition);
        void stopNote(float velocity, bool allowTailOff);
        
        //=================================================

        // changes the preset midi map
        void changePreset(int sys);
       
        // pitch bend
        void pitchWheelMoved(int newPitchWheelValue);
        void setPitchBend(int pitchWheelPos);
        float pitchBendCents();
       
        // @see juce_Synthesizer
        void controllerMoved(int controllerNumber, int newControllerValue);
        void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples);
        
        //===================================================
        
        double noteHz(int midiNoteNumber, double centsOffset);

        //===================================================

        // synth settings
        void setFilter(float cut, float res);
        void setEnvelope(float a, float d, float s, float r);
        void setWaveType(int waveType);
        void setGain(float gain);

        void setBuilderAttributes(float b, float os, float sf);

    private:
        double level;
        double frequency;
        float gain = 1;

        System* currsys;
        SystemBuilder sb;
        

        double midiMap[128];

        
        int noteNumber;
        int waveType = 1;
        
        enum WAVE_TYPES
        {
            SAW         = 1,
            SINEWAVE    = 2,
            SQUARE      = 3,
            TRIANGLE    = 4
        };
        
        float pitchBend = 0.0f;
        float pitchBendUpSemitones = 2.0f;
        float pitchBendDownSemitones = 2.0f;

        float cutoff;
        float resonance;

        float attack;
        float decay;
        float sustain;
        float release;

        float base;
        float octaveSize;
        float startingFrequency;

        System* et = sb.makeEqualTemperament();
       
        System* mt = sb.makeMeanToneTemperament();
        
        System* wt = sb.makeWellTemperament();
        
        System* ji = sb.makeJustIntonation();
        
        System* ma = sb.makeMaqam();
        
        System* ga = sb.makeGamelanSlendro();
        
        System* ge = sb.makeHarryPartch();

        maxiOsc osc1;
        maxiEnv env1; 
        maxiFilter filter1;
};



