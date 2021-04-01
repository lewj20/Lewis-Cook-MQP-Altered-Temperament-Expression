/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "SystemPreset.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p), filterGui(p), envGui(p), infoGui(p), editor(p)
{
    setSize (450, 400);

    // Preset 
    presetMenu.addItem("Equal Temperament", 1);
    presetMenu.addItem("Well Temperament", 2);
    presetMenu.addItem("Meantone", 3);
    presetMenu.addItem("Just Intonation", 4);
    presetMenu.addItem("Maqam", 5);
    presetMenu.addItem("Gamelan", 6);
    presetMenu.addItem("Harry Partch", 7);

    presetMenu.onChange = [this] { presetMenuChanged(); };
    addAndMakeVisible(presetMenu);

    gainLabel.setText("Gain", juce::dontSendNotification);
    
    gainLabel.setFont(textFont);
    addAndMakeVisible(gainLabel);



    presetNumber = new juce::AudioProcessorValueTreeState::ComboBoxAttachment(audioProcessor.params, "presetNumber", presetMenu);

    // Synthesizer
    waveMenu.addItem("Saw", 1);
    waveMenu.addItem("Sine", 2);
    waveMenu.addItem("Square", 3);
    waveMenu.addItem("Triangle", 4);
    addAndMakeVisible(&waveMenu);

    addAndMakeVisible(&filterGui);

    addAndMakeVisible(&envGui);

    addAndMakeVisible(&editor);
    
    // Sets the editor values to default equal temperament
    // not sure if I should do this
    editor.initiateDefaultEqualTemperament();

    waveVal = new juce::AudioProcessorValueTreeState::ComboBoxAttachment(audioProcessor.params, "wavetype", waveMenu);

    // Keyboard
    getLookAndFeel().setColour(juce::MidiKeyboardComponent::ColourIds::disabledWhiteNoteColourId,
        juce::Colour::fromRGB(0x80, 0x80, 0x80));
    getLookAndFeel().setColour(juce::MidiKeyboardComponent::ColourIds::disabledBlackNoteColourId,
        juce::Colour::fromRGB(0x80, 0x80, 0x80));

    //addAndMakeVisible(keyboardTestBox);
    addAndMakeVisible(keyboard);

    addAndMakeVisible(infoGui);
    infoGui.setVisible(false);
    
   

    // System Information
    addAndMakeVisible(infoButton);

    // ???
    presetMenuChanged();

    mastergainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    mastergainSlider.setRange(0.0f, 1.0f);
    mastergainSlider.setValue(1.0f);
    mastergainSlider.setTextBoxStyle(juce::Slider::NoTextBox, true, 0, 0);
    addAndMakeVisible(&mastergainSlider);

    infoButton.onClick = [infogui = &infoGui, env = &envGui, fil = &filterGui]()
    { if (infogui->isVisible()) {
        infogui->setVisible(false);
        env->setVisible(true);
        fil->setVisible(true);

    }
    else {
        infogui->setVisible(true);
        env->setVisible(false);
        fil->setVisible(false);

    }
    };

    mastergainVal = new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.params, "mastergain", mastergainSlider);

}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

void NewProjectAudioProcessorEditor::presetMenuChanged()
{
    // in most cases the editor is not used

    switch (presetMenu.getSelectedId())
    {
    case SystemPreset::EQUAL_TEMPERAMENT:
        infoGui.initEqualTemp();
        // set editor to visible
        editor.showControls();
        break;
    case SystemPreset::WELL_TEMPERAMENT:
        infoGui.initWell();
        editor.hideControls();
        break;
    case SystemPreset::MEANTONE_TEMPERAMENT:
        infoGui.initMeantone();
        editor.hideControls();
        break;
    case SystemPreset::JUST_INTONATION: 
        infoGui.initJustIntonation();
        editor.hideControls();
        break;
    case SystemPreset::MAQUAM: 
        infoGui.initMaqam();
        editor.hideControls();
        break;
    case SystemPreset::GAMELAN_SLENDRO: 
        infoGui.initGamelan(); 
        editor.hideControls();
        break;
    case SystemPreset::GENESIS:
        infoGui.initGenesis();
        editor.hideControls();
        break;
    default: 
        break;
    }
}

void NewProjectAudioProcessorEditor::infoBtnClick() {
    if (infoGui.isVisible()) {
        infoGui.setVisible(false);
        envGui.setVisible(true);
        filterGui.setVisible(true);
        mastergainSlider.setVisible(true);
    }
    else {
        infoGui.setVisible(true);
        envGui.setVisible(false);
        filterGui.setVisible(false);
        mastergainSlider.setVisible(false);

    }
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void NewProjectAudioProcessorEditor::resized()
{
    // Preset
    presetMenu.setBounds(0, 30, 160, 30);

    // Synthesizer
    waveMenu.setBounds(0, 70, 160, 30);
    filterGui.setBounds(180, 0, 200, 200);
    envGui.setBounds(180, 125, 200, 200);

    // Keyboard
    keyboard.setBounds (8, (getHeight() - DEFAULT_KEYBOARD_HEIGHT), getWidth() - (2*8), DEFAULT_KEYBOARD_HEIGHT);
    //keyboardTestBox.setBounds(0, 0, 160, 30);
    
    // System Information
    infoButton.setBounds(390, 20, 30, 30);

    // Editor
    editor.setBounds(0, 142, 200, 200);

    infoGui.setBounds(180, 0, 250, 400);
    mastergainSlider.setBounds(167, 50, 30, 200);
    gainLabel.setBounds(167, 20, 40, 40);

}
