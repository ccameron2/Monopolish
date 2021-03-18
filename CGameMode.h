#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <deque>
#include <ctime>
#include "CSquare.h"
#include "CPlayer.h"
#include "CProperty.h"
#include "CGo.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"

using namespace std;
typedef vector<CSquare*> squareVector;
typedef vector<CPlayer*> playerVector;


class CGameMode
{
private:
    squareVector squareList;
    playerVector playerList;
    const char POUND = 156;
public:
    void ReadInSquares();
    void PlayGame();
    int ReadInSeed();
    void CheckRent();
    void CheckMortgage(CPlayer* player);
};

