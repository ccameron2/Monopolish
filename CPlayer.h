#pragma once
#include <vector>
#include <string>

using namespace std;

class CPlayer
{
private:
    string mName = " ";
    int mMoney = 0;
    int mPosition = 0;
    bool mIsBankrupt = false;
public:
    CPlayer(string name, int money, int position); //Constructor to set up a new player.
    ~CPlayer(); //Destructor.
    string GetName(); //Get name of player.
    void SetName(string name);//Set name of player.
    int GetMoney();//Get player's money.
    void SetMoney(int money);//Set player's money.
    void ChangeMoney(int changeInMoney);;//Change player's money by given amount.
    void SetPosition(int position); //Set player position.
    int GetPosition(); //Get player position.
    int Random(); //Roll random value.
    bool GetIsBankrupt(); //Get player bankruptcy status.
    void SetIsBankrupt(bool isBankrupt); //Get player bankruptcy status.
};

