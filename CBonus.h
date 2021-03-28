#pragma once
#include "CSquare.h"
class CBonus : 
    public CSquare
{
public:
    CBonus(istream& file); //Constructor that takes file parameter
    friend istream& operator >> (istream& inputStream, CBonus& sqr); //Operator to read data from file
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player
};