#pragma once
#include "CSquare.h"
class CJail : 
    public CSquare
{
public:
    CJail(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group) {}
    void LandedOn(CPlayer* player);
};

