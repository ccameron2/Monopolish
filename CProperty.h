#pragma once
#include "CSquare.h"
class CProperty :
    public CSquare
{
public:
    CProperty(istream& file); //Constructor that takes file parameter.
    void LandedOn(CPlayer* player); //Operator to read data from file.
    friend istream& operator >> (istream& inputStream, CProperty& sqr); //Functionality of square when landed on by a player
};

