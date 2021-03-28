#include "CProperty.h"
CProperty::CProperty(istream& file): CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
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
        //If property is not owned and player can afford the property.
        if (player->GetMoney() - GetCost() > 0)
        {
            //Deduct cost of property from player money and set owner to player.
            SetOwner(player);
            cout << player->GetName() << " buys " << GetName() << " for " << POUND << GetCost() << endl;
            player->ChangeMoney(-GetCost());
        }
    }
    else 
    {   
        //If property is not owned by player or mortgaged.
        if (GetOwner() != player)
        {
            if (!GetIsMortgaged())
            {
                //Deduct rent from the player, pay the owner and output message to console.
                player->ChangeMoney(-GetRent());
                GetOwner()->ChangeMoney(GetRent());
                cout << player->GetName() << " pays " << POUND << GetRent() << endl;
            }
        }                                                
    }
}




