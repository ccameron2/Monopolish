#pragma once
#include "CSquare.h"
class CStation :
    public CSquare
{
public:
    CStation(istream& file); //Constructor that takes file parameter.
    friend istream& operator >> (istream& inputStream, CStation& sqr); //Operator to read data from file.
    void LandedOn(CPlayer* player); //Functionality of square when landed on by a player
};

