/*
  ==============================================================================

    SynthVoice.h
    Created: 29 Oct 2020 3:10:01pm
    Author:  Benjamin M'Sadoques

  ==============================================================================
*/

#include "SynthVoice.h"



SynthVoice::~SynthVoice() {
    free(currsys);
}

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    return dynamic_cast<SynthSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    noteNumber = midiNoteNumber;
    env1.trigger = 1;
    level = velocity;
    frequency = noteHz(midiNoteNumber, pitchBendCents());
    
    
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    env1.trigger = 0;
    allowTailOff = true;

    if (velocity == 0)
    {
        clearCurrentNote();
    }
}

void SynthVoice::changePreset(int sys)
{
    
    switch (sys) {
    case 1:
        currsys = et;
        break;
    case 2:
        currsys = wt;
        break;
    case 3:
        currsys = mt;
        break;
    case 4:
        currsys = ji;
        break;
    case 5:
        currsys = ma;
        break;
    case 6:
        currsys = ga;
        break;
    case 7:
        currsys = ge;
        break;
    }
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
    setPitchBend(newPitchWheelValue);
    frequency = noteHz(noteNumber, pitchBendCents());
}

void SynthVoice::setPitchBend(int pitchWheelPos)
{
    if (pitchWheelPos > 8192)
    {
        // shifting up
        pitchBend = float(pitchWheelPos - 8192) / (16383 - 8192);
    }
    else
    {
        // shifting down
        pitchBend = float(8192 - pitchWheelPos) / -8192;    // negative number
    }
}

float SynthVoice::pitchBendCents()
{
    float pitchBendCents = pitchBend * 100;

    // shifting up
    if (pitchBend >= 0.0f)
    {
        pitchBendCents *= pitchBendUpSemitones;
    }
    // shifting down
    else
    { 
        pitchBendCents *= pitchBendDownSemitones;
    }
    return pitchBendCents;
}

double SynthVoice::noteHz(int midiNoteNumber, double centsOffset)
{
    double hertz = currsys->getMidiMap()[midiNoteNumber];
    hertz *= std::pow(2.0, centsOffset / 1200);
    return hertz;
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
    // not used but has to be implemented
}



void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    

    if (frequency > 0) {
        env1.setAttack(this->attack);
        env1.setDecay(this->decay);
        env1.setSustain(this->sustain);
        env1.setRelease(this->release);


        for (int sample = 0; sample < numSamples; sample++) {




            double theWave;

            // Select the wave type
            switch (waveType)
            {
            case SAW:
                theWave = osc1.saw(frequency);
                break;
            case SINEWAVE:
                theWave = osc1.sinewave(frequency);
                break;
            case SQUARE:
                theWave = osc1.square(frequency);
                break;
            case TRIANGLE:
                theWave = osc1.triangle(frequency);
                break;
            default:
                break;
            }
            double theSound = env1.adsr(theWave, env1.trigger) * level;
            double fitleredSound = filter1.lores(theSound, cutoff, resonance);

            for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++) {


                outputBuffer.addSample(channel, startSample, fitleredSound * gain);
            }

            startSample++;

        }
    }
}

void SynthVoice::setGain(float gain) {
    this->gain = gain;
}

void SynthVoice::setFilter(float cut, float res)
{
    this->cutoff = cut;
    this->resonance = res;
}

void SynthVoice::setEnvelope(float a, float d, float s, float r)
{
    this->attack = a;
    this->decay = d;
    this->release = r;
    this->sustain = s;
}

void SynthVoice::setWaveType(int waveType)
{
    this->waveType = waveType;
}


void SynthVoice::setBuilderAttributes(float b, float os, float sf) {
    this->base = b;
    this->octaveSize = os;
    this->startingFrequency = sf;
    dynamic_cast<EqualTemperament*>(et)->setBuilderSettings(b, os, sf);
}
