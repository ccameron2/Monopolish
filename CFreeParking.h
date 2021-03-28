#pragma once
#include "CSquare.h"
class CFreeParking : 
    public CSquare
{
public:
    CFreeParking(istream& file); //Constructor that takes file parameter.
    friend istream& operator >> (istream& inputStream, CFreeParking& sqr); //Operator to read data from file.
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player.
};

