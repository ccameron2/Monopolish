#pragma once
#include "CSquare.h"
class CGo : 
    public CSquare
{
public:
    CGo(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group) {};
    void LandedOn(CPlayer* player, vector<CSquare*>& squareList);
};
