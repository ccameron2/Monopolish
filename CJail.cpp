#include "CJail.h"
CJail::CJail(istream& file) : CSquare(file)
{
    file >> *this;
}

void CJail::LandedOn(CPlayer* player)
{
    cout << player->GetName() << " is just visiting" << endl;
}

istream& operator>>(istream& inputStream, CJail& sqr)
{
    string name;
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
