#include "CStation.h"
CStation::CStation(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}

istream& operator >> (istream& inputStream, CStation& sqr)
{
    //Read in two names.
    string nameOne;
    string nameTwo;
    string nameFinal;
    inputStream >> nameOne;
    inputStream >> nameTwo;

    //Set default rent and cost values.
    int ticketPrice = 10;
    int stationPrice = 200;

    //Combine into final name and set values of square.
    nameFinal = nameOne + " " + nameTwo;
    sqr.SetName(nameFinal);
    sqr.SetCost(stationPrice);
    sqr.SetRent(ticketPrice);
    return inputStream;
}

void CStation::LandedOn(CPlayer* player)
{
    //If station is not owned and player can afford the station.
    if (GetOwner() == nullptr)
    {
        if (player->GetMoney() - GetCost() > 0)
        {
            //Deduct cost of station from player money and set owner to player.
            SetOwner(player);
            cout << player->GetName() << " buys " << GetName() << " for " << POUND << GetCost() << endl;
            player->ChangeMoney(-GetCost());
        }
    }
    else
    {
        //If property is not owned by player or mortgaged.
        if (!GetIsMortgaged())
        {
            if (GetOwner() != player)
            {
                //Deduct rent from the player, pay the owner and output message to console.
                player->ChangeMoney(-GetRent());
                GetOwner()->ChangeMoney(GetRent());
                cout << player->GetName() << " pays " << POUND << GetRent() << " for a ticket" << endl;
            }
        }
    }
}