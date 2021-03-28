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

unique_ptr<CSquare> CSquareFactory::NewSquare(ifstream& file)
{
    //Read in the type of square
    int type = 0;
    file >> type;

    //Return the appropriate type of square
    switch (type)
    {
    case 1:
    {
        return make_unique<CProperty>(file);
        break;
    }
    case 2:
    {
        return make_unique<CGo>(file);
        break;
    }
    case 3:
    {
        return make_unique<CStation>(file);
        break;
    }
    case 4:
    {
        return make_unique<CBonus>(file);
        break;
    }
    case 5:
    {
        return make_unique<CPenalty>(file);
        break;
    }
    case 6:
    {
        return make_unique<CJail>(file);
        break;
    }
    case 7:
    {
        return make_unique<CGoToJail>(file);
        break;
    }
    case 8:
    {
        return make_unique<CFreeParking>(file);
        break;
    }
    default:
        return nullptr;
        break;
    }

}
