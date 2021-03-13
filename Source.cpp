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

class CPlayer
{
private:
    string mName;
    int mMoney;
    int mPosition;
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
};

class CProperty : public CSquare
{
public:
    CProperty(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};

class CGo : public CSquare
{
public:
    CGo(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};
class CStation : public CSquare
{
public:
    CStation(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};
class CBonus : public CSquare
{
public:
    CBonus(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};
class CPenalty : public CSquare
{
public:
    CPenalty(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};
class CJail : public CSquare
{
public:
    CJail(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};
class CGoToJail : public CSquare
{
public:
    CGoToJail(int type, string name, int cost, int rent, int group) : CSquare(type, name, cost, rent, group)
    {
    }
};
class CFreeParking : public CSquare
{
public:
    CFreeParking(int type, string name, int cost, int rent, int group) : CSquare(type, name,cost,rent,group)
    {
    }
};

int Random();
int ReadInSeed();

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
        for (int j = 0; j < playerList.size(); j++)
        {
            int roll = Random();
            cout << playerList[j]->GetName() << " rolls " << roll << endl;
            if (playerList[j]->GetPosition() + roll > sqrList.size() - 1)
            {
                playerList[j]->SetPosition(playerList[j]->GetPosition() + roll - 26);
            }
            else
            {
                playerList[j]->SetPosition(playerList[j]->GetPosition() + roll);
            }
            
            switch (sqrList[playerList[j]->GetPosition()]->GetType())
            {
                case 1:
                    cout << playerList[j]->GetName() << " lands on " << sqrList[playerList[j]->GetPosition()]->GetName() << endl;
                    break;
                case 2:
                    cout << playerList[j]->GetName() << " passes GO and collects "<< POUND << "200 " << endl;
                    playerList[j]->ChangeMoney(200);
                    break;
                default:
                    cout << playerList[j]->GetName() << " lands on " << sqrList[playerList[j]->GetPosition()]->GetName() << endl;
                    break;
            }           

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

    /*for (vector<CSquare*>::iterator it = sqrList.begin(); it != sqrList.end(); it++)
    {       
            cout << (*it)->GetName(); 
            cout << " " << (*it)->GetCost();
            cout << " " << (*it)->GetRent();
            cout << " " << (*it)->GetGroup() << endl;
    }*/
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