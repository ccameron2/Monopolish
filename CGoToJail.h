#pragma once
#include "CSquare.h"
class CGoToJail : 
    public CSquare
{
public:
    CGoToJail(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group) {}
    void LandedOn(CPlayer* player);
};
