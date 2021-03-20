#include "CGo.h"
CGo::CGo(istream& file) : CSquare(file)
{
    file >> *this;
}
void CGo::LandedOn(CPlayer* player)
{
}

istream& operator>>(istream& inputStream, CGo& sqr)
{
    string name = "";
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
