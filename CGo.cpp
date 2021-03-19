#include "CGo.h"
CGo::CGo(istream& file) : CSquare(file)
{
    file >> *this;
}
void CGo::LandedOn(shared_ptr<CPlayer> player)
{   
    cout << player->GetName() << " lands on Go " << endl;
}

istream& operator>>(istream& inputStream, CGo& sqr)
{
    string name = "";
    inputStream >> name;
    sqr.SetName(name);
    return inputStream;
}
