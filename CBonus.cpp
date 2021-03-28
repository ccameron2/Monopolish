#include "CBonus.h"
CBonus::CBonus(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}
void CBonus::LandedOn(CPlayer* player)
{
    /*Roll random value for player, output appropriate message to console
    and increase player's money by correct amount*/
    switch (player->Random())
    {
    case 1:
        cout << "Find some money. Gain " << POUND << "20" << endl;
        player->ChangeMoney(20);
        break;
    case 2:
        cout << "Win a coding competition. Gain " << POUND << "50" << endl;
        player->ChangeMoney(50);
        break;
    case 3:
        cout << "Receive a rent rebate. Gain " << POUND << "100" << endl;
        player->ChangeMoney(100);
        break;
    case 4:
        cout << "Win the lottery. Gain " << POUND << "150" << endl;
        player->ChangeMoney(150);
        break;
    case 5:
        cout << "Receive a bequest. Gain " << POUND << "200" << endl;
        player->ChangeMoney(200);
        break;
    case 6:
        cout << "It's your birthday. Gain " << POUND << "300" << endl;
        player->ChangeMoney(300);
        break;
    }
}

istream& operator >> (istream& inputStream, CBonus& sqr)
{
    //Read in name from file and set value on square
    string name;
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
