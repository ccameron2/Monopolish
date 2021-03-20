#pragma once
#include "CSquare.h"
class CProperty :
    public CSquare
{
public:
    CProperty(istream& file);
    void LandedOn(CPlayer* player);
    friend istream& operator >> (istream& inputStream, CProperty& sqr);
};

