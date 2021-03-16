#pragma once
#include "CSquare.h"
class CProperty :
    public CSquare
{
public:
    CProperty(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group){ }
    void LandedOn(CPlayer* player, vector<CSquare*>& squareList);
};

