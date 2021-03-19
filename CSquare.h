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
    string mName = " ";
    int mRent = 0;
    int mGroup = 8;
    shared_ptr<CPlayer> mOwner = nullptr;
    bool mIsDoubleRent = false;
    int mCost = 0;
    bool mIsMortgaged = false;

public:
    CSquare(istream &file);
    virtual ~CSquare();
    friend istream& operator >> (istream& inputStream, CSquare& sqr);
    virtual void LandedOn(shared_ptr<CPlayer> player){ }
    string GetName();
    void SetName(string name);   
    int GetRent();
    void SetRent(int rent);
    int GetGroup();
    void SetGroup(int cost);
    int GetCost();
    void SetCost(int cost);
    bool GetIsMortgaged();
    void SetIsMortgaged(bool isMortgaged);
    shared_ptr<CPlayer> GetOwner();
    void SetOwner(shared_ptr<CPlayer> player);
    bool GetIsDoubleRent();
    void SetIsDoubleRent(bool isDoubleRent);
};