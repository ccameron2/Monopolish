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

public:
    CPlayer(string name, int money, int position);
    ~CPlayer();
    string GetName();
    void SetName(string name);
    int GetMoney();
    void SetMoney(int money);
    void ChangeMoney(int changeInMoney);;
    void SetPosition(int position);
    int GetPosition();
    int Random();
};

