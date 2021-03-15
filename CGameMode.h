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

class CGameMode
{
private:
    vector<CSquare*> squareList;
    vector<CPlayer*> playerList;
    const char POUND = 156;
public:
    void ReadInSquares();
    void PlayGame();
    int ReadInSeed();

};

