#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "CSquare.h"

using namespace std;

typedef vector<unique_ptr<CSquare>> squareVector;
typedef vector<unique_ptr<CPlayer>> playerVector;
typedef vector<CSquare*> tempSquareVector;

class CGameMode
{
private:
    squareVector squareList;
    playerVector playerList;
    const char POUND = char(156);
public:
    void ReadInSquares(); //Create Squares from file.
    void PlayGame(); //Start the game.
    int ReadInSeed(); //Read seed from file.
    void CheckRent(); //Check and set the double rent status of each property.
    void CheckMortgage(CPlayer* player); //Check and set the mortgage status of each property.
};

