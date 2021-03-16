#include "CPlayer.h"

CPlayer::CPlayer(string name, int money, int position)
{
    mName = name;
    mMoney = money;
    mPosition = position;
}
CPlayer::~CPlayer()
{

}
string CPlayer::GetName()
{
    return mName;
}
void CPlayer::SetName(string name)
{
    mName = name;
}
int CPlayer::GetMoney()
{
    return mMoney;
}
void CPlayer::SetMoney(int money)
{
    mMoney = money;
}
void CPlayer::ChangeMoney(int changeInMoney)
{
    mMoney += changeInMoney;
}
int CPlayer::GetPosition()
{
    return mPosition;
}
void CPlayer::SetPosition(int position)
{
    mPosition = position;
}
int CPlayer::Random()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

