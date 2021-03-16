#include "CProperty.h"
void CProperty::LandedOn(CPlayer* player, vector<CSquare*>& squareList)
{    
    cout << player->GetName() << " lands on " << GetName() << endl;
    if (GetOwner() == nullptr)
    {        
        if (player->GetMoney() > 0)
        {
            SetOwner(player);
            cout << player->GetName() << " buys " << GetName() << " for " << POUND << GetCost() << endl;
            player->ChangeMoney(-GetCost());
        }
    }
    else if(GetOwner() != player)
    {                   
        player->ChangeMoney(-GetRent());
        GetOwner()->ChangeMoney(GetRent());
        cout << player->GetName() << " pays " << POUND << GetRent() << endl;
    }
}