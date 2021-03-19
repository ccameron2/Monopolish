#pragma once
#include "CSquare.h"
class CProperty :
    public CSquare
{
public:
    CProperty(istream& file);
    void LandedOn(shared_ptr<CPlayer> player);
    friend istream& operator >> (istream& inputStream, CProperty& sqr);


};

