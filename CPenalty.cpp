#include "CPenalty.h"

CPenalty::CPenalty(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}
void CPenalty::LandedOn(CPlayer* player)
{
    /*Roll random value for player, output appropriate message to console
    and decrease player's money by correct amount*/
    switch (player->Random())
    {
    case 1:
        cout << "Buy a coffee in Starbucks. Lose " << POUND << "20" << endl;
        player->ChangeMoney(-20);
        break;
    case 2:
        cout << "Pay your broadband bill. Lose " << POUND << "50" << endl;
        player->ChangeMoney(-50);
        break;
    case 3:
        cout << "Visit the SU shop for food. Lose " << POUND << "100" << endl;
        player->ChangeMoney(-100);
        break;
    case 4:
        cout << "Buy an assignment solution. Lose " << POUND << "150" << endl;
        player->ChangeMoney(-150);
        break;
    case 5:
        cout << "Go for a romantic meal. Lose " << POUND << "200" << endl;
        player->ChangeMoney(-200);
        break;
    case 6:
        cout << "Pay some university fees. Lose " << POUND << "300" << endl;
        player->ChangeMoney(-300);
        break;
    }
}

istream& operator>>(istream& inputStream, CPenalty& sqr)
{
    //Read in name and set value in square.
    string name;
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
