/*
  ==============================================================================

    Filter.h
    Created: 15 Nov 2020 12:32:22pm
    Author:  Lewis Cook

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
class Filter : public juce::Component
{
public:
    Filter(NewProjectAudioProcessor&);
    ~Filter();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    NewProjectAudioProcessor& processor;

    // Sub Componets
    juce::Slider filterCutoff;
    juce::Slider filterRes;
    juce::Label filterLabel;
    juce::Label resLabel;
    juce::Font textFont{ 12.0f };

    // Sub Componet Pointers
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> filterVal;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> resVal;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Filter)
};