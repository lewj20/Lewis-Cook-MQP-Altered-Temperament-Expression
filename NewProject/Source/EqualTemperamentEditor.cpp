/*
  ==============================================================================

    EqualTemperamentTK.cpp
    Created: 19 Nov 2020 2:32:07pm
    Author:  MT

  ==============================================================================
*/

#include "EqualTemperamentEditor.h"

//==============================================================================
EqualTemperamentEditor::EqualTemperamentEditor(NewProjectAudioProcessor& p)
    : processor(p)
{
    setSize(200, 200);

    baseSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    baseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    baseSlider.setRange(2.0f, 9.0f, 1.0f);
    baseSlider.setNumDecimalPlacesToDisplay(0); // this does not work!
    addAndMakeVisible(&baseSlider);

    octaveSizeSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    octaveSizeSlider.setRange(2.0f, 70.0f);
    octaveSizeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(&octaveSizeSlider);

    centerFrequencySlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    centerFrequencySlider.setRange(200.0f, 600.0f);
    centerFrequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    addAndMakeVisible(&centerFrequencySlider);

    buildButton.setButtonText("Build");
    addAndMakeVisible(&buildButton);
    
    buildButton.onClick = [processor = &p]()
    {
        processor->presetChanged();

    };

    baseValue = new juce::AudioProcessorValueTreeState::SliderAttachment(processor.params, "base", baseSlider);
    octaveSizeValue = new juce::AudioProcessorValueTreeState::SliderAttachment(processor.params, "octaveSize", octaveSizeSlider);
    centerFrequencyValue = new juce::AudioProcessorValueTreeState::SliderAttachment(processor.params, "startFrequency", centerFrequencySlider);
}

EqualTemperamentEditor::~EqualTemperamentEditor()
{
}

//==============================================================================
void EqualTemperamentEditor::paint(juce::Graphics& g)
{

    juce::Rectangle <float> area(8, 8, 150, 150);

    g.setColour(juce::Colours::white);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void EqualTemperamentEditor::resized()
{
    // Draws the sliders...we use a rectangle object to dynamically size the UI (if we want to resize for IPad etc without needing to change ALL settings
    juce::Rectangle<int> area = getLocalBounds().reduced(50);

    int sliderWidth = 50;
    int sliderHeight = 130;

    // Draws the sliders by reducing area from rectangle above
    baseSlider.setBounds(8, 0, sliderWidth, sliderHeight);
    octaveSizeSlider.setBounds(sliderWidth+8, 0, sliderWidth, sliderHeight);
    centerFrequencySlider.setBounds(sliderWidth*2 + 8, 0, sliderWidth, sliderHeight);

    buildButton.setBounds(58, 135, 50, 20);
}

void EqualTemperamentEditor::hideControls() {

    baseSlider.setVisible(false);
    octaveSizeSlider.setVisible(false);
    centerFrequencySlider.setVisible(false);

    buildButton.setVisible(false);
}

void EqualTemperamentEditor::showControls() {

    baseSlider.setVisible(true);
    octaveSizeSlider.setVisible(true);
    centerFrequencySlider.setVisible(true);

    buildButton.setVisible(true);
}

void EqualTemperamentEditor::initiateDefaultEqualTemperament()
{
    octaveSizeSlider.setValue(12.0f);
    baseSlider.setValue(2.0f);
    centerFrequencySlider.setValue(6.875f);
}
