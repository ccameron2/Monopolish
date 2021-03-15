#pragma once
#include "CSquare.h"
class CBonus : 
    public CSquare
{
public:
    CBonus(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player);
};