#pragma once
#include "CSquare.h"
class CPenalty : 
    public CSquare
{
public:
    CPenalty(istream& file); //Constructor that takes file parameter.
    friend istream& operator >> (istream& inputStream, CPenalty& sqr); //Operator to read data from file.
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player
    
};