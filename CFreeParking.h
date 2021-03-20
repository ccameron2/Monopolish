#pragma once
#include "CSquare.h"
class CFreeParking : 
    public CSquare
{
public:
    CFreeParking(istream& file);
    friend istream& operator >> (istream& inputStream, CFreeParking& sqr);
    void LandedOn(CPlayer* player);
};

