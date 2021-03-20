#pragma once
#include "CSquare.h"
class CStation : 
    public CSquare
{
public:
    CStation(istream& file);
    friend istream& operator >> (istream& inputStream, CStation& sqr);
    void LandedOn(CPlayer* player);
};

