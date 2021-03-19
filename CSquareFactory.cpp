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

shared_ptr<CSquare> CSquareFactory::NewSquare(ifstream& file)
{
    int type = 0;
    file >> type;
    switch (type)
    {

    case 1:
    {
        return make_shared<CProperty>(file);
        break;
    }
    case 2:
    {
        return make_shared<CGo>(file);
        break;
    }
    case 3:
    {
        return make_shared<CStation>(file);
        break;
    }
    case 4:
    {
        return make_shared<CBonus>(file);
        break;
    }
    case 5:
    {
        return make_shared<CPenalty>(file);
        break;
    }
    case 6:
    {
        return make_shared<CJail>(file);
        break;
    }
    case 7:
    {
        return make_shared<CGoToJail>(file);
        break;
    }
    case 8:
    {
        return make_shared<CFreeParking>(file);
        break;
    }
    default:
        return nullptr;
        break;
    }

}
