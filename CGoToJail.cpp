#include "CGoToJail.h"

void CGoToJail::LandedOn(CPlayer* player)
{
    player->SetPosition(6);
    cout << player->GetName() << " lands on Go to Jail" << endl;
    cout << player->GetName() << " goes to Jail" << endl;
    cout << player->GetName() << " pays " << POUND << "50" << endl;
}