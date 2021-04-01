/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Filter.h"
#include "Envelope.h"
#include "Info.h"
#include "Test_CustomMidiKeyboard.h"
#include "EqualTemperamentEditor.h"

constexpr auto DEFAULT_WINDOW_WIDTH = 300;
constexpr auto DEFAULT_WINDOW_HEIGHT = 400;
constexpr auto EDGE_SPACING = 8;
constexpr auto DEFAULT_KEYBOARD_HEIGHT = 60;

//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void infoBtnClick();

    void presetMenuChanged();

    //void showInfoWindow();

private:
    NewProjectAudioProcessor& audioProcessor;

    //std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> comboTree;

    juce::ComboBox presetMenu;
    juce::Slider mastergainSlider;

    juce::ScopedPointer<juce::AudioProcessorValueTreeState::SliderAttachment> mastergainVal;
    juce::Label gainLabel;

    juce::Font textFont{ 12.0f };


    juce::ComboBox waveMenu;
    juce::ScopedPointer<juce::AudioProcessorValueTreeState::ComboBoxAttachment> waveVal;


    juce::ScopedPointer<juce::AudioProcessorValueTreeState::ComboBoxAttachment> presetNumber;


    // TODO: synth is not attached to keyboard

    juce::MidiKeyboardComponent keyboard{ audioProcessor.keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard };

    // UI Testing only
    //juce::ComboBox keyboardTestBox;
    Tuning::Structures::KeyboardLayout layout{ &keyboard };
    //testing::Test_CustomMidiKeyboard testCustomMidiKeyboard{ &layout, &keyboardTestBox };

    Filter filterGui;
    Envelope envGui;
    Info infoGui;

    EqualTemperamentEditor editor;

    juce::TextButton infoButton{"I"};

    //juce::Image infoImage = juce::ImageFileFormat::loadFrom(juce::File::getCurrentWorkingDirectory().getChildFile("info.png"));


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};
