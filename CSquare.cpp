#include "CSquare.h"
CSquare::CSquare(int type, string name, int cost, int rent, int group)
{
    mType = type;
    mName = name;
    mCost = cost;
    mRent = rent;
    mGroup = group;
}
CSquare::~CSquare()
{

}

void CSquare::LandedOn(CPlayer* player)
{

}

int CSquare::GetType()
{
    return mType;
}
string CSquare::GetName()
{
    return mName;
}
int CSquare::GetCost()
{
    return mCost;
}
int CSquare::GetRent()
{
    return mRent;
}
void CSquare::SetRent(int rent)
{
    mRent = rent;
}
int CSquare::GetGroup()
{
    return mGroup;
}
CPlayer* CSquare::GetOwner()
{
    return mOwner;
}
void CSquare::SetOwner(CPlayer* owner)
{
    mOwner = owner;
}

bool CSquare::GetIsDoubleRent()
{
    return mIsDoubleRent;
}

void CSquare::SetIsDoubleRent(bool isDoubleRent)
{
    mIsDoubleRent = isDoubleRent;
}
