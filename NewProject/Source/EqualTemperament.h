/*
  ==============================================================================

    EqualTemperament.h
    Created: 10 Nov 2020 10:02:40am
    Author:  MT

  ==============================================================================
*/

#pragma once
#include "System.h"

class EqualTemperament : public System
{
public:
    EqualTemperament(double base, double octaveSize, double startFrequency, int startLocation, int size);
    ~EqualTemperament();
    void initialize();

    void setBuilderSettings(double b, double os, double sf);


private:
    double base;
    double octaveSize;
    double startFrequency;
};