#include "CGo.h"
void CGo::LandedOn(CPlayer* player)
{
    cout << player->GetName() << " passes GO and collects " << POUND << "200 " << endl;
    player->ChangeMoney(200);
}