#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <deque>
#include <ctime>

using namespace std;

const char POUND = 156;

int Random();
int ReadInSeed();

class CPlayer
{
private:
    string mName = " ";
    int mMoney = 0;
    int mPosition = 0;
public:
    CPlayer(string name, int money, int position)
    {
        mName = name;
        mMoney = money;
        mPosition = position;
    }
    string GetName()
    {
        return mName;
    }
    void SetName(string name)
    {
        mName = name;
    }
    int GetMoney()
    {
        return mMoney;
    }
    void SetMoney(int money)
    {
        mMoney = money;
    }
    void ChangeMoney(int changeInMoney)
    {
        mMoney += changeInMoney;
    }
    int GetPosition()
    {
        return mPosition;
    }
    void SetPosition(int position)
    {
        mPosition = position;
    }

};

class CSquare
{
private:
    int mType = 0;
    string mName = " ";
    int mCost = 0;
    int mRent= 0;
    int mGroup= 0;
    CPlayer* mOwner = nullptr;

public:
    CSquare(int type, string name, int cost, int rent, int group)
    { 
        mType = type;
        mName = name;
        mCost = cost;
        mRent = rent;
        mGroup = group;
    }
    ~CSquare()
    {
        cout << "Destructor" << endl;
    }
    virtual void LandedOn(CPlayer* player)
    {

    }
    int GetType()
    {
        return mType;
    }
    string GetName()
    {
        return mName;
    }
    int GetCost()
    {
        return mCost;
    }
    int GetRent()
    {
        return mRent;
    }
    int GetGroup()
    {
        return mGroup;
    }
    CPlayer* GetOwner()
    {
        return mOwner;
    }
    void SetOwner(CPlayer* owner)
    {
        mOwner = owner;
    }
};

class CProperty : public CSquare
{
public:
    CProperty(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        cout << player->GetName() << " lands on " << GetName() << endl;
        if (GetOwner() == nullptr)
        {
            //if (playerList[j]->GetMoney() - sqrList[playerPosition]->GetCost() > 0)
            if (player->GetMoney() > 0)
            {
                SetOwner(player);
                cout << player->GetName() << " buys " << GetName() << " for " << POUND << GetCost() << endl;
                player->ChangeMoney(-GetCost());
            }
        }
        else
        {
            if (GetOwner() != player)
            {
                player->ChangeMoney(-GetRent());
                GetOwner()->ChangeMoney(GetRent());
                cout << player->GetName() << " pays " << GetRent() << endl;
            }
        }
    }
};

class CGo : public CSquare
{
public:
    CGo(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        cout << player->GetName() << " passes GO and collects " << POUND << "200 " << endl;
        player->ChangeMoney(200);
    }
};
class CStation : public CSquare
{
public:
    CStation(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        cout << player->GetName() << " lands on " << GetName() << endl;
        if (GetOwner() == nullptr)
        {
            //if (playerList[j]->GetMoney() - sqrList[playerPosition]->GetCost() > 0)
            if (player->GetMoney() > 0)
            {
                SetOwner(player);
                cout << player->GetName() << " buys " << GetName() << " for " << POUND << GetCost() << endl;
                player->ChangeMoney(-GetCost());
            }
        }
        else
        {
            if (GetOwner() != player)
            {
                player->ChangeMoney(-GetRent());
                GetOwner()->ChangeMoney(GetRent());
                cout << player->GetName() << " pays " << POUND << GetRent() << " for a ticket" <<endl;
            }
        }
    }
};
class CBonus : public CSquare
{
public:
    CBonus(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        cout << player->GetName() << " lands on Bonus" << endl;
        switch (Random())
        {
        case 1:
            cout << "Find some money. Gain "<< POUND << "20" << endl;
            player->ChangeMoney(20);
            break;
        case 2:
            cout << "Win a coding competition. Gain " << POUND << "50" << endl;
            player->ChangeMoney(50);
            break;
        case 3:
            cout << "Receive a rent rebate. Gain " << POUND << "100" << endl;
            player->ChangeMoney(100);
            break;
        case 4:
            cout << "Win the lottery. Gain " << POUND << "150" << endl;
            player->ChangeMoney(150);
            break;
        case 5:
            cout << "Receive a bequest. Gain " << POUND << "200" << endl;
            player->ChangeMoney(200);
            break;
        case 6:
            cout << "It's your birthday. Gain " << POUND << "300" << endl;
            player->ChangeMoney(300);
            break;
        }
    }
};
class CPenalty : public CSquare
{
public:
    CPenalty(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        switch (Random())
        {
        case 1:
            cout << "Buy a coffee in Starbucks. Lose " << POUND << "20" << endl;
            player->ChangeMoney(-20);
            break;
        case 2:
            cout << "Pay your broadband bill. Lose " << POUND << "50" << endl;
            player->ChangeMoney(-50);
            break;
        case 3:
            cout << "Visit the SU shop for food. Lose " << POUND << "100" << endl;
            player->ChangeMoney(-100);
            break;
        case 4:
            cout << "Buy an assignment solution. Lose " << POUND << "150" << endl;
            player->ChangeMoney(-150);
            break;
        case 5:
            cout << "Go for a romantic meal. Lose " << POUND << "200" << endl;
            player->ChangeMoney(-200);
            break;
        case 6:
            cout << "Pay some university fees. Lose " << POUND << "300" << endl;
            player->ChangeMoney(-300);
            break;
        }
    }
};
class CJail : public CSquare
{
public:
    CJail(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {        
          cout << player->GetName() << " lands on Jail" << endl;
          cout << player->GetName() << " is just visiting" << endl;
        
    }
};
class CGoToJail : public CSquare
{
public:
    CGoToJail(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        player->SetPosition(6);
        cout << player->GetName() << " lands on Go to Jail" << endl;
        cout << player->GetName() << " goes to Jail" << endl;
        cout << player->GetName() << " pays " << POUND << "50" << endl;
    }
};
class CFreeParking : public CSquare
{
public:
    CFreeParking(int type, string name, int cost, int rent, int group) : CSquare(type, name,cost,rent,group)
    {
    }
    void LandedOn(CPlayer* player)
    {
        cout << player->GetName() << " lands on Free Parking" << endl;
        cout << player->GetName() << " is resting" << endl;
    }
};



int main()
{
    vector<CSquare*> sqrList;
    string line = "";
    string word = "";
    ifstream fin("monopoly.txt");
    if (fin.is_open())
    {
        while (getline(fin, line,'\n'))
        {
            istringstream iss(line);
            while (getline(iss, word, ' '))
            {
                if (!isdigit(stoi(word)))
                {
                    int sqrType = 0;
                    int sqrCost = 0;
                    int sqrRent = 0;
                    int sqrGroup = 0;
                    string nameOne = "";
                    string nameTwo = "";
                    string nameThree = "";
                    string nameFinal = "";
                    switch (stoi(word))
                    {

                        case 1:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameOne = word;
                            getline(iss, word, ' ');
                            nameTwo = word;
                            nameFinal = nameOne + " " + nameTwo;;
                            getline(iss, word, ' ');
                            sqrCost = stoi(word);
                            getline(iss, word, ' ');
                            sqrRent = stoi(word);
                            getline(iss, word, ' ');
                            sqrGroup = stoi(word);
                            CProperty* sqr = new CProperty(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }                   
                        case 2:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CGo* sqr = new CGo(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }
                        case 3:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameOne = word;
                            getline(iss, word, ' ');
                            nameTwo = word;
                            nameFinal = nameOne + " " + nameTwo;
                            sqrCost = 200;
                            sqrRent = 10;
                            CStation* sqr = new CStation(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }
                        case 4:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CBonus* sqr = new CBonus(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }
                        case 5:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CPenalty* sqr = new CPenalty(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }                           
                        case 6:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CJail* sqr = new CJail(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }
                        case 7:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameOne = word;
                            getline(iss, word, ' ');
                            nameTwo = word;
                            getline(iss, word, ' ');
                            nameThree = word;
                            nameFinal = nameOne + " " + nameTwo + " " + nameThree;;
                            CGoToJail* sqr = new CGoToJail(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }                       
                        case 8:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameOne = word;
                            getline(iss, word, ' ');
                            nameTwo = word;
                            nameFinal = nameOne + " " + nameTwo;
                            CFreeParking* sqr = new CFreeParking(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                            sqrList.push_back(sqr);
                            break;
                        }                        
                    }
                }
                getline(iss, word, ' ');
            }
        }
    }
    fin.close();

    srand(ReadInSeed());
    //Game loop setup
    int startMoney = 1500;
    int startPosition = 0;
    string nameOne = "Dog";
    string nameTwo = "Car";
    vector<CPlayer*> playerList;
    CPlayer* Dog = new CPlayer(nameOne, startMoney, startPosition);
    CPlayer* Car = new CPlayer(nameTwo, startMoney, startPosition);
    playerList.push_back(Dog);
    playerList.push_back(Car);

    cout << "Welcome to Monopol-ish" << endl;

    //Game Loop
    for (int i = 0; i < 20; i++)
    {
        for (vector<CPlayer*>::iterator it = playerList.begin(); it != playerList.end(); it++)
        {
            int roll = Random();
            cout << (*it)->GetName() << " rolls " << roll << endl;
            if ((*it)->GetPosition() + roll > sqrList.size() - 1)
            {
                (*it)->SetPosition((*it)->GetPosition() + roll - 26);
            }
            else
            {                
                (*it)->SetPosition((*it)->GetPosition() + roll);
            }
            sqrList[(*it)->GetPosition()]->LandedOn((*it));
            cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;
        }
    }
    //End game
    cout << "Game Over" << endl;
    for (int i = 0; i < playerList.size(); i++)
    {
        cout << playerList[i]->GetName() << " has " << POUND << playerList[i]->GetMoney() << endl;
    }
    //Compare final money values
    if (playerList[1]->GetMoney() > playerList[0]->GetMoney())
    { 
        cout << playerList[1]->GetName() << " wins." << endl; 
    }
    else
    { 
        cout << playerList[0]->GetName() << " wins." << endl; 
    }

    for (vector<CSquare*>::iterator it = sqrList.begin(); it != sqrList.end(); it++)
    {
        delete *it;
    }
    for (vector<CPlayer*>::iterator it = playerList.begin(); it != playerList.end(); it++)
    {
        delete *it;
    }
    system("pause");
    return 0;
}

int Random()//Nick's random number generator.
{    
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

int ReadInSeed()
{
    ifstream fin("seed.txt");
    int seed = 0;

    if (fin.is_open())
    {
        fin >> seed;
    }
    fin.close();
    return seed;
}