#include "CFreeParking.h"
CFreeParking::CFreeParking(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}
void CFreeParking::LandedOn(CPlayer* player)
{
    //Output resting message to console.
    cout << player->GetName() << " is resting" << endl;
}

istream& operator>>(istream& inputStream, CFreeParking& sqr)
{
    //Read in two names.
    string nameOne;
    string nameTwo;
    string nameFinal;
    inputStream >> nameOne;
    inputStream >> nameTwo;

    //Combine the two names and set final name.
    nameFinal = nameOne + " " + nameTwo;
    sqr.SetName(nameFinal);
    return inputStream;
}
