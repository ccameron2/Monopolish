#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file) : CSquare(file)
{
    file >> *this;
}

void CGoToJail::LandedOn(CPlayer* player)
{
    player->SetPosition(6);
    cout << player->GetName() << " goes to Jail" << endl;
    cout << player->GetName() << " pays " << POUND << "50" << endl;
    player->ChangeMoney(-50);
}

istream& operator >> (istream& inputStream, CGoToJail& sqr)
{
    string nameOne;
    string nameTwo;
    string nameThree;
    string nameFinal;
    inputStream >> nameOne;
    inputStream >> nameTwo;
    inputStream >> nameThree;
    nameFinal = nameOne + " " + nameTwo + " " + nameThree;
    sqr.SetName(nameFinal);
    return inputStream;
}
