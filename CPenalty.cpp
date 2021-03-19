#include "CPenalty.h"

CPenalty::CPenalty(istream& file) : CSquare(file)
{
    file >> *this;
}
void CPenalty::LandedOn(shared_ptr<CPlayer> player)
{
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
    string name;
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
