/*
  ==============================================================================

    Info.cpp
    Created: 21 Nov 2020 12:58:08pm
    Author:  Lewis Cook

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Info.h"

//==============================================================================
Info::Info(NewProjectAudioProcessor& p)
    : processor(p)
{
    setSize(200, 200);
    initEqualTemp();


    Name.setFont(juce::Font(14.0f, juce::Font::bold));
    Origin.setFont(juce::Font(14.0f, juce::Font::plain));
    Math.setFont(juce::Font(14.0f, juce::Font::plain));
    MusicTheory.setFont(juce::Font(14.0f, juce::Font::plain));

    addAndMakeVisible(Name);
    addAndMakeVisible(Origin);
    addAndMakeVisible(Math);
    addAndMakeVisible(MusicTheory);


    
}

Info::~Info()
{
}

/**
 * Sets the information for equal temperament
 */
void Info::initEqualTemp()
{
    Name.setText("Equal Temperament", juce::dontSendNotification);
    Origin.setText("Equal Temperament was invented by Zhu Zaiyu, a Chinese Mathematician in 1596", juce::dontSendNotification);
    Math.setText("Notes in Equal Temperament are calculated by a formula. 2^(x/y) * (hz) x = position of note in the octave, y = number of notes in the octave, hz is the frequency of the first note in the octave.", juce::dontSendNotification);
    MusicTheory.setText("Standard modern music theory applies to 12 note equal temperament", juce::dontSendNotification);
}

void Info::initMeantone()
{
    Name.setText("Meantone Temperament", juce::dontSendNotification);
    Origin.setText("Meantone was invented around the 1700s, it was an early attempt to temper and smooth out Just Intonation wolf intervals so more intervals were usable.", juce::dontSendNotification);
    Math.setText("Meantone Temperament reduced wolf intervals by tuning specific tones to be mean between other tones. For example, C-sharp is mean between G-sharp and F-sharp.", juce::dontSendNotification);
    MusicTheory.setText("This version of meantone temperament resembles the 17th century equal beating meantone temperament.", juce::dontSendNotification);
}

void Info::initWell()
{
    Name.setText("Well Temperament", juce::dontSendNotification);
    Origin.setText("Well Temperament was another attempt to temper and smooth out Just Intonation. The system allows one to play in a all keys and avoid wolf tones.", juce::dontSendNotification);
    Math.setText("Well Temperament contains key color contrasts that gives each key a unique sound.", juce::dontSendNotification);
    MusicTheory.setText("This version of well temperament resembes Francesco Antonio Vallotti Early Eighteenth-Century Well Temperament.", juce::dontSendNotification);
}

void Info::initJustIntonation()
{
    Name.setText("Just Intonation", juce::dontSendNotification);
    Origin.setText("Just Intonation is a group of many systems built on whole number ratios, rather than tempered intervals.", juce::dontSendNotification);
    Math.setText("The ratios work based on complexity, different denominators produce different sounds. For example 3/2 will sound different from 8/5.", juce::dontSendNotification);
    MusicTheory.setText("This version of Just Intonation approximates equal temperament with ratios.", juce::dontSendNotification);
}

void Info::initMaqam()
{
    Name.setText("Maqam", juce::dontSendNotification);
    Origin.setText("Maqam is the name for temperament systems from Turkish, Arabic, and Persian music.", juce::dontSendNotification);
    Math.setText("Maqam has thousands of variations, but it is commonly accepted nowadays to be 24-note equal temperament.", juce::dontSendNotification);
    MusicTheory.setText("This system is very similar to 12-note equal temperament but with added microtones between the notes.", juce::dontSendNotification);
}

void Info::initGamelan()
{
    Name.setText("Gamelan", juce::dontSendNotification);
    Origin.setText("Gamelan is the name for classical Indonesian ensambles, the instruments they use have a very unique temperament system.", juce::dontSendNotification);
    Math.setText("Gamelan is best apporiximated by 5 note equal temperament", juce::dontSendNotification);
    MusicTheory.setText("All 5 Gamelan notes are meant to harmonize with one another.", juce::dontSendNotification);
}

void Info::initGenesis()
{
    Name.setText("Harry Partch", juce::dontSendNotification);
    Origin.setText("The Harry Partch system is a 43-note Just Intonation system that was invented by Harry Partch in 1947", juce::dontSendNotification);
    Math.setText("The Harry Partch scale using pure intervals with intermitten notes in between. There are 43 notes in an octave. It is based on an eleven limit tonality diamond.", juce::dontSendNotification);
    MusicTheory.setText("", juce::dontSendNotification);
}

void Info::paint(juce::Graphics& g)
{
    //fancy stuff for the UI background etc
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

    g.setColour(juce::Colours::white);
    g.drawText("System Information", titleArea, juce::Justification::centredTop);

    juce::Rectangle <float> area(25, 25, 200, 300);

    g.setColour(juce::Colours::white);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void Info::resized()
{
    //draws the sliders...we use a rectangle object to dynamically size the UI (if we want to resize for IPad etc without needing to change ALL settings
    juce::Rectangle<int> area = getLocalBounds().reduced(50);

    Name.setBounds(30, 30, 190, 50);
    Origin.setBounds(30, 50, 190, 100);
    Math.setBounds(30, 150, 190, 100);
    MusicTheory.setBounds(30, 260, 190, 50);
}
