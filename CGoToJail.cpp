#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}

void CGoToJail::LandedOn(CPlayer* player)
{
    //Send the player to jail and charge them £50.
    player->SetPosition(6);
    cout << player->GetName() << " goes to Jail" << endl;
    cout << player->GetName() << " pays " << POUND << "50" << endl;
    player->ChangeMoney(-50);
}

istream& operator >> (istream& inputStream, CGoToJail& sqr)
{
    //Read in three names.
    string nameOne;
    string nameTwo;
    string nameThree;
    string nameFinal;
    inputStream >> nameOne;
    inputStream >> nameTwo;
    inputStream >> nameThree;

    //Combine into final name and set value in square.
    nameFinal = nameOne + " " + nameTwo + " " + nameThree;
    sqr.SetName(nameFinal);
    return inputStream;
}
