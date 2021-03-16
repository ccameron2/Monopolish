#include "CFreeParking.h"
void CFreeParking::LandedOn(CPlayer* player, vector<CSquare*>& squareList)
{
    cout << player->GetName() << " lands on Free Parking" << endl;
    cout << player->GetName() << " is resting" << endl;
}