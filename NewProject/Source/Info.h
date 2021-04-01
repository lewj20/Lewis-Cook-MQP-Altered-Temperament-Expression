/*
  ==============================================================================

    Info.h
    Created: 21 Nov 2020 12:58:01pm
    Author:  Lewis Cook

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class Info : public juce::Component
{
public:
    Info(NewProjectAudioProcessor&);
    ~Info();

    void paint(juce::Graphics&) override;
    void resized() override;

    

    void initEqualTemp();
    void initMeantone();
    void initWell();
    void initJustIntonation();
    void initMaqam();
    void initGamelan();
    void initGenesis();




private:
    NewProjectAudioProcessor& processor;

    juce::Label Name;
    juce::Label Origin;
    juce::Label Math;
    juce::Label MusicTheory;


    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Info)
};