#pragma once
#include "CSquare.h"
class CJail : 
    public CSquare
{
public:
    CJail(istream& file); //Constructor that takes file parameter.
    friend istream& operator >> (istream& inputStream, CJail& sqr); //Operator to read data from file.
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player
};

