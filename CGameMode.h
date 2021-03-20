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
typedef vector<unique_ptr<CSquare>> squareVector;
typedef vector<unique_ptr<CPlayer>> playerVector;
typedef vector<CSquare*> squareObserverVector;


class CGameMode
{
private:
    squareVector squareList;
    playerVector playerList;
    const char POUND = char(156);
public:
    void ReadInSquares();
    void PlayGame();
    int ReadInSeed();
    void CheckRent();
    void CheckMortgage(CPlayer* player);
};

