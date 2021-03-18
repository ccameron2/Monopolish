#include "CSquare.h"
CSquare::CSquare(istream& file)
{
    file >> *this;
}
CSquare::~CSquare()
{

}
istream& operator >> (istream& inputStream, CSquare& sqr)
{
    return inputStream;
}

string CSquare::GetName()
{
    return mName;
}

void CSquare::SetName(string name)
{
    mName = name;
}


void CSquare::SetIsMortgaged(bool isMortgaged)
{
    mIsMortgaged = isMortgaged;
}

CPlayer* CSquare::GetOwner()
{
    return mOwner;
}

void CSquare::SetOwner(CPlayer* owner)
{
    mOwner = owner;
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
void CSquare::SetGroup(int group)
{
    mGroup = group;
}

bool CSquare::GetIsDoubleRent()
{
    return mIsDoubleRent;
}

void CSquare::SetIsDoubleRent(bool isDoubleRent)
{
    mIsDoubleRent = isDoubleRent;
}

int CSquare::GetCost()
{
    return mCost;
}
void CSquare::SetCost(int cost)
{
    mCost = cost;
}

bool CSquare::GetIsMortgaged()
{
    return mIsMortgaged;
}
