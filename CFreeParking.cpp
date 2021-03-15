#include "CFreeParking.h"
void CFreeParking::LandedOn(CPlayer* player)
{
    cout << player->GetName() << " lands on Free Parking" << endl;
    cout << player->GetName() << " is resting" << endl;
}