/*
  ==============================================================================

    Envelope.h
    Created: 15 Nov 2020 3:11:03pm
    Author:  Lewis Cook

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
class Envelope : public juce::Component
{
public:
    Envelope(NewProjectAudioProcessor&);
    ~Envelope();

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    NewProjectAudioProcessor& processor;

    // Sub Componets
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    // Sub Componet Pointers
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> attackVal;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> decayVal;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> sustainVal;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> releaseVal;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Envelope)
};