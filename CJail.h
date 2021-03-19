#pragma once
#include "CSquare.h"
class CJail : 
    public CSquare
{
public:
    CJail(istream& file);
    friend istream& operator >> (istream& inputStream, CJail& sqr);
    void LandedOn(shared_ptr<CPlayer> player);
};

