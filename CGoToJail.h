#pragma once
#include "CSquare.h"
class CGoToJail : 
    public CSquare
{
public:
    CGoToJail(istream& file);
    friend istream& operator >> (istream& inputStream, CGoToJail& sqr);
    void LandedOn(shared_ptr<CPlayer> player);
};
