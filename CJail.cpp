#include "CJail.h"
CJail::CJail(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}

void CJail::LandedOn(CPlayer* player)
{
    //Output 'just visiting' message.
    cout << player->GetName() << " is just visiting" << endl;
}

istream& operator>>(istream& inputStream, CJail& sqr)
{
    //Read in name and set value in square.
    string name;
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
