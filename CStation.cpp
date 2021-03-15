#include "CStation.h"
void CStation::LandedOn(CPlayer* player)
{
    cout << player->GetName() << " lands on " << GetName() << endl;
    if (GetOwner() == nullptr)
    {
        //if (playerList[j]->GetMoney() - sqrList[playerPosition]->GetCost() > 0)
        if (player->GetMoney() > 0)
        {
            SetOwner(player);
            cout << player->GetName() << " buys " << GetName() << " for " << POUND << GetCost() << endl;
            player->ChangeMoney(-GetCost());
        }
    }
    else
    {
        if (GetOwner() != player)
        {
            player->ChangeMoney(-GetRent());
            GetOwner()->ChangeMoney(GetRent());
            cout << player->GetName() << " pays " << POUND << GetRent() << " for a ticket" << endl;
        }
    }
}