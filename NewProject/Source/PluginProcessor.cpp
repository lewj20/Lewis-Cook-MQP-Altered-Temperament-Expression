/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SystemPreset.h"

//==============================================================================
NewProjectAudioProcessor::NewProjectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
    params(*this, nullptr, "Parameters", { std::make_unique<juce::AudioParameterFloat>("attack", "Attack", juce::NormalisableRange<float>(0.1f, 5000.0f), 0.1f),
                                           std::make_unique<juce::AudioParameterFloat>("release", "Release", juce::NormalisableRange<float>(0.0f, 50.0f), 0.1f),
                                           std::make_unique<juce::AudioParameterFloat>("decay", "Decay", juce::NormalisableRange<float>(1.0f, 2000.0f), 1.0f),
                                           std::make_unique<juce::AudioParameterFloat>("sustain", "Sustain", juce::NormalisableRange<float>(0.01f, 1.0f), 0.8f),
                                           std::make_unique<juce::AudioParameterFloat>("wavetype", "WaveType", juce::NormalisableRange<float>(1, 4), 1),
                                           std::make_unique<juce::AudioParameterFloat>("filterCutoff", "FilterCutoff", juce::NormalisableRange<float>(20.0f, 5000.0f), 400.0f),
                                           std::make_unique<juce::AudioParameterFloat>("filterRes", "FilterRes", juce::NormalisableRange<float>(1.0f, 5.0f), 1.0f), 
                                           std::make_unique<juce::AudioParameterFloat>("presetNumber", "PresetNumber", juce::NormalisableRange<float>(1.0f, 7.0f), 1.0f),
                                           std::make_unique<juce::AudioParameterFloat>("mastergain", "MasterGain", juce::NormalisableRange<float>(0.0f, 1.0f), 0.7f),

                                           // equal temperament builder
                                           std::make_unique<juce::AudioParameterFloat>("base", "Base", juce::NormalisableRange<float>(2.0f, 10.0f), 2.0f),
                                           std::make_unique<juce::AudioParameterFloat>("octaveSize", "OctaveSize", juce::NormalisableRange<float>(2.0f, 60.0f), 12.0f),
                                           std::make_unique<juce::AudioParameterFloat>("startFrequency", "StartFrequency", juce::NormalisableRange<float>(6.875f, 20000.0f), 6.875f)}),
                                           
    presetNumber(1)
#endif
{


    mySynth.clearVoices();

    for (int i = 0; i < 5; i++) {
        mySynth.addVoice(new SynthVoice());
    }

    mySynth.clearSounds();

    mySynth.addSound(new SynthSound());

    // Load preset
    this->presetChanged();

   
    


}

NewProjectAudioProcessor::~NewProjectAudioProcessor()
{
    //keyboardState.~MidiKeyboardState();
}

//==============================================================================




const juce::String NewProjectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool NewProjectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool NewProjectAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double NewProjectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int NewProjectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int NewProjectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void NewProjectAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String NewProjectAudioProcessor::getProgramName (int index)
{
    return {};
}

void NewProjectAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void NewProjectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    juce::ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);


}


void NewProjectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool NewProjectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif




void NewProjectAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{

    

    for (int i = 0; i < mySynth.getNumVoices(); i++)
    {
        //if myVoice sucessfully casts as a SynthVoice*, get the voice and set the params
        if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
        {


            float freq = *params.getRawParameterValue("filterCutoff");
            float res = *params.getRawParameterValue("filterRes");

            float a = *params.getRawParameterValue("attack");
            float d = *params.getRawParameterValue("decay");
            float s = *params.getRawParameterValue("sustain");
            float r = *params.getRawParameterValue("release");

            int wt = *params.getRawParameterValue("wavetype");
            float g = *params.getRawParameterValue("mastergain");

            float b = *params.getRawParameterValue("base");
            float os = *params.getRawParameterValue("octaveSize");
            float sf = *params.getRawParameterValue("startFrequency");



            myVoice->setFilter(freq, res);
            myVoice->setEnvelope(a, d, s, r);
            myVoice->setWaveType(wt);
            myVoice->setGain(g);
            myVoice->setBuilderAttributes(b, os, sf);

            int newPresetNumber = *params.getRawParameterValue("presetNumber");


            if (presetNumber != newPresetNumber) {
 
                this->presetNumber = newPresetNumber;
                 //Switches preset settings
                this->presetChanged();
            }




            // Load preset to synth
            
            myVoice->changePreset(presetNumber);
                
        }
    }
    buffer.clear();

    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());

    keyboardState.processNextMidiBuffer(midiMessages, 0, midiMessages.getNumEvents(), false);

}

void NewProjectAudioProcessor::presetChanged()
{ 
    switch (this->presetNumber)
    {
    case SystemPreset::EQUAL_TEMPERAMENT:
        
        // TODO: need to notify this , but cannot use the XML tree state
        presetNumber = 1;

        this->system = this->systemBuilder.makeEqualTemperament(*params.getRawParameterValue("base"),
            *params.getRawParameterValue("octaveSize"),
            *params.getRawParameterValue("startFrequency"));
        break;
    case SystemPreset::WELL_TEMPERAMENT:
        presetNumber = 2;
        this->system = this->systemBuilder.makeWellTemperament();
        break;
    case SystemPreset::MEANTONE_TEMPERAMENT:
        presetNumber = 3;
        this->system = this->systemBuilder.makeMeanToneTemperament();
        break;
    case SystemPreset::JUST_INTONATION:
        presetNumber = 4;
        this->system = this->systemBuilder.makeJustIntonation();
        break;
    case SystemPreset::MAQUAM:
        presetNumber = 5;
        this->system = this->systemBuilder.makeMaqam();
        break;
    case SystemPreset::GAMELAN_SLENDRO:
        presetNumber = 6;
        this->system = this->systemBuilder.makeGamelanSlendro();
        break;
    case SystemPreset::GENESIS:
        presetNumber = 7;
        this->system = this->systemBuilder.makeHarryPartch();
        break;
    default: 
        break;
    }

   
}

//==============================================================================
bool NewProjectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* NewProjectAudioProcessor::createEditor()
{
    return new NewProjectAudioProcessorEditor (*this);
}

//==============================================================================
void NewProjectAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    auto state = params.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);

}

void NewProjectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(params.state.getType()))
            params.replaceState(juce::ValueTree::fromXml(*xmlState));


}



//juce::MidiKeyboardState NewProjectAudioProcessor::getKeyboardState()
//{
 //   return keyboardState;
//}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new NewProjectAudioProcessor();
}
