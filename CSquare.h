#pragma once

#include <string>
#include <iostream>
#include "CPlayer.h"
#include <vector>

const char POUND = 156;
using namespace std;

class CSquare
{
private:
    int mType = 0;
    string mName = " ";
    int mCost = 0;
    int mRent = 0;
    int mGroup = 0;
    CPlayer* mOwner = nullptr;
    bool mIsDoubleRent = false;

public:
    CSquare(int type, string name, int cost, int rent, int group);
    virtual ~CSquare();
    virtual void LandedOn(CPlayer* player, vector<CSquare*>& squareList);
    int GetType();
    string GetName();
    int GetCost();
    int GetRent();
    void SetRent(int rent);
    int GetGroup();
    CPlayer* GetOwner();
    void SetOwner(CPlayer* player);
    bool GetIsDoubleRent();
    void SetIsDoubleRent(bool isDoubleRent);
};