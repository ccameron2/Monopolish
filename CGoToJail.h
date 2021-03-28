#pragma once
#include "CSquare.h"
class CGoToJail : 
    public CSquare
{
public:
    CGoToJail(istream& file); //Constructor that takes file parameter.
    friend istream& operator >> (istream& inputStream, CGoToJail& sqr); //Operator to read data from file.
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player
};
