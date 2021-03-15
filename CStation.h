#pragma once
#include "CSquare.h"
class CStation : 
    public CSquare
{
public:
    CStation(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group){}
    void LandedOn(CPlayer* player);
};

