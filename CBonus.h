#pragma once
#include "CSquare.h"
class CBonus : 
    public CSquare
{
public:
    CBonus(istream& file);
    friend istream& operator >> (istream& inputStream, CBonus& sqr);
    void LandedOn(shared_ptr<CPlayer> player);
};