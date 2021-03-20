#pragma once
#include "CSquare.h"
class CPenalty : 
    public CSquare
{
public:
    CPenalty(istream& file);
    friend istream& operator >> (istream& inputStream, CPenalty& sqr);
    void LandedOn(CPlayer* player);
    
};