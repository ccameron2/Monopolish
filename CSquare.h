#pragma once
#include <string>
#include <iostream>
#include "CPlayer.h"
#include <vector>

const char POUND = char(156);
using namespace std;

class CSquare
{
private:
    string mName = " ";
    int mRent = 0;
    int mGroup = 8;
    CPlayer* mpOwner = nullptr;
    bool mIsDoubleRent = false;
    int mCost = 0;
    bool mIsMortgaged = false;

public:
    CSquare(istream &file); //Constructor that takes file parameter.
    virtual ~CSquare(); //Virtual destructor.
    friend istream& operator >> (istream& inputStream, CSquare& sqr); //Operator to read data from file.
    virtual void LandedOn(CPlayer* player){ } //Virtual function for functionality of square when landed on by a player.
    string GetName(); //Get name of square.
    void SetName(string name); //Set name of square.
    int GetRent(); //Get rent cost of square.
    void SetRent(int rent); //Set rent cost of square.
    int GetGroup(); //Get group of square.
    void SetGroup(int cost); //Set group of square.
    int GetCost(); //Get cost of square.
    void SetCost(int cost); //Set cost of square.
    bool GetIsMortgaged(); //Get mortgage status of square.
    void SetIsMortgaged(bool isMortgaged); //Set mortgage status of square.
    CPlayer* GetOwner(); //Get owner of square.
    void SetOwner(CPlayer* player); //Set owner of square.
    bool GetIsDoubleRent(); //Get double rent status of square.
    void SetIsDoubleRent(bool isDoubleRent); //Set double rent status of square.
};