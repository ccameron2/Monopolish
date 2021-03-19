#pragma once
#include "CSquare.h"
class CGo : 
    public CSquare
{
public:
    CGo(istream& file);
    friend istream& operator >> (istream& inputStream, CGo& sqr);
    void LandedOn(shared_ptr<CPlayer> player);
};
