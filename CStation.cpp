#include "CStation.h"
CStation::CStation(istream& file) : CSquare(file)
{
    file >> *this;
}

istream& operator >> (istream& inputStream, CStation& sqr)
{
    string nameOne;
    string nameTwo;
    string nameFinal;
    int ticketPrice = 10;
    int stationPrice = 200;
    inputStream >> nameOne;
    inputStream >> nameTwo;
    nameFinal = nameOne + " " + nameTwo;
    sqr.SetName(nameFinal);
    sqr.SetCost(stationPrice);
    sqr.SetRent(ticketPrice);
    return inputStream;
}

void CStation::LandedOn(CPlayer* player)
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
        if (!GetIsMortgaged())
        {
            if (GetOwner() != player)
            {
                player->ChangeMoney(-GetRent());
                GetOwner()->ChangeMoney(GetRent());
                cout << player->GetName() << " pays " << POUND << GetRent() << " for a ticket" << endl;
            }
        }                
    }
}