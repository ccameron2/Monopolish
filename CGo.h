#pragma once
#include "CSquare.h"
class CGo : 
    public CSquare
{
public:
    CGo(istream& file); //Constructor that takes file parameter.
    friend istream& operator >> (istream& inputStream, CGo& sqr); //Operator to read data from file.
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player
};
