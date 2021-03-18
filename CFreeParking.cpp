#include "CFreeParking.h"
CFreeParking::CFreeParking(istream& file) : CSquare(file)
{
    file >> *this;
}
void CFreeParking::LandedOn(CPlayer* player)
{
    cout << player->GetName() << " lands on Free Parking" << endl;
    cout << player->GetName() << " is resting" << endl;
}

istream& operator>>(istream& inputStream, CFreeParking& sqr)
{
    string nameOne;
    string nameTwo;
    string nameFinal;
    inputStream >> nameOne;
    inputStream >> nameTwo;
    nameFinal = nameOne + " " + nameTwo;
    sqr.SetName(nameFinal);
    return inputStream;
}
