/*
  ==============================================================================

    Filter.cpp
    Created: 15 Nov 2020 12:32:26pm
    Author:  Lewis Cook

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Filter.h"

//==============================================================================
Filter::Filter(NewProjectAudioProcessor& p) :
    processor(p)
{
    setSize(200, 200);

    filterLabel.setText("Cutoff", juce::dontSendNotification);
    resLabel.setText("Resonance", juce::dontSendNotification);

    filterLabel.setFont(textFont);
    resLabel.setFont(textFont);

    addAndMakeVisible(filterLabel);
    addAndMakeVisible(resLabel);

    filterCutoff.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterCutoff.setRange(20.0, 5000.0);
    filterCutoff.setValue(400.0);
    filterCutoff.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterCutoff);
    filterVal = new juce::AudioProcessorValueTreeState::SliderAttachment(processor.params, "filterCutoff", filterCutoff);
    //filterCutoff.setSkewFactorFromMidPoint(1000.0);

    filterRes.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    filterRes.setRange(1, 5);
    filterRes.setValue(1);
    filterRes.setTextBoxStyle(juce::Slider::NoTextBox, false, 0, 0);
    addAndMakeVisible(&filterRes);
    resVal = new juce::AudioProcessorValueTreeState::SliderAttachment(processor.params, "filterRes", filterRes);
}

Filter::~Filter()
{
}

// @see juce_Componet::paint()
void Filter::paint(juce::Graphics& g)
{
    //background ui stuff
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

    g.setColour(juce::Colours::white);
    g.drawText("Filter", titleArea, juce::Justification::centredTop);
    
    juce::Rectangle <float> area(25, 25, 150, 90);

    g.setColour(juce::Colours::white);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

// @see juce_Componet::resized()
void Filter::resized()
{
    //need to come back and dynamically set these...ok for now
    juce::Rectangle<int> area = getLocalBounds().reduced(40);

    filterCutoff.setBounds(30, 30, 70, 70);
    filterRes.setBounds(100, 30, 70, 70);
    filterLabel.setBounds(45, 70, 70, 70);
    resLabel.setBounds(103, 70, 70, 70);
}
