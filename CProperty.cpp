#include "CProperty.h"
CProperty::CProperty(istream& file): CSquare(file)
{
    file >> *this;
}

istream& operator >> (istream& inputStream, CProperty& sqr)
{   
    string nameOne;
    string nameTwo;
    string nameFinal;
    inputStream >> nameOne;
    inputStream >> nameTwo;
    nameFinal = nameOne + " " + nameTwo;    
    int sqrCost = 0;
    int sqrRent = 0;
    int sqrGroup = 0;
    inputStream >> sqrCost;
    inputStream >> sqrRent;
    inputStream >> sqrGroup;
    sqr.SetName(nameFinal);
    sqr.SetRent(sqrRent);
    sqr.SetCost(sqrCost);
    sqr.SetGroup(sqrGroup);
    return inputStream;
}
void CProperty::LandedOn(CPlayer* player)
{
    if (GetOwner() == nullptr)
    {        
        if (player->GetMoney() - GetCost() > 0)
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
            if (!GetIsMortgaged())
            {
                player->ChangeMoney(-GetRent());
                GetOwner()->ChangeMoney(GetRent());
                cout << player->GetName() << " pays " << POUND << GetRent() << endl;
            }
        }                                                
    }
}




