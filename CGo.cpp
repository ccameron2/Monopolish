#include "CGo.h"
CGo::CGo(istream& file) : CSquare(file)
{
    //Pass this square to overloaded operator for data to be read.
    file >> *this;
}
void CGo::LandedOn(CPlayer* player)
{
}

istream& operator>>(istream& inputStream, CGo& sqr)
{
    //Read in name and set value in square.
    string name = "";
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
