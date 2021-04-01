/*
  ==============================================================================

    EqualTemperamentTK.h
    Created: 19 Nov 2020 2:32:07pm
    Author:  MT

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class EqualTemperamentEditor : public juce::Component
{
public:
    EqualTemperamentEditor(NewProjectAudioProcessor& p);
    ~EqualTemperamentEditor();

    void paint(juce::Graphics& g) override;
    void resized() override;

    void initiateDefaultEqualTemperament();

    void hideControls();

    void showControls();

private:
    NewProjectAudioProcessor& processor;

    juce::Slider baseSlider;
    juce::Slider octaveSizeSlider;
    juce::Slider centerFrequencySlider;

    juce::TextButton buildButton;

    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> baseValue;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> octaveSizeValue;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> centerFrequencyValue;

    // Processor
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EqualTemperamentEditor)
};