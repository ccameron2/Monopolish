#include "CSquareFactory.h"
#include <fstream>
#include "CPlayer.h"
#include "CProperty.h"
#include "CGo.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"

CSquare* CSquareFactory::NewSquare(ifstream& file)
{
    int type = 0;
    file >> type;
    switch (type)
    {

    case 1:
    {
        return new CProperty(file);
        break;
    }
    case 2:
    {
        return new CGo(file);
        break;
    }
    case 3:
    {
        return new CStation(file);
        break;
    }
    case 4:
    {
        return new CBonus(file);
        break;
    }
    case 5:
    {
        return new CPenalty(file);
        break;
    }
    case 6:
    {
        return new CJail(file);
        break;
    }
    case 7:
    {
        return new CGoToJail(file);
        break;
    }
    case 8:
    {
        return new CFreeParking(file);
        break;
    }
    default:
        return nullptr;
        break;
    }

}
