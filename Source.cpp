#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <deque>

using namespace std;


class CSquare
{
private:
    int mType;
    string mName;

public:
    CSquare(int type, string name)
    {
        mType = type;
        mName = name;
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
};

class CProperty : public CSquare
{
private:
    int mCost;
    int mRent;
    int mGroup;
public:
    CProperty(int type, string name, int cost, int rent, int group) : CSquare(type, name), mCost{cost},mRent{rent},mGroup{group}
    {
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

class CGo : public CSquare
{
public:
    CGo(int type, string name) : CSquare(type, name)
    {

    }
};
class CStation : public CSquare
{
public:
    CStation(int type, string name) : CSquare(type, name)
    {

    }
};
class CBonus : public CSquare
{
public:
    CBonus(int type, string name) : CSquare(type, name)
    {

    }
};
class CPenalty : public CSquare
{
public:
    CPenalty(int type, string name) : CSquare(type, name)
    {

    }
};
class CJail : public CSquare
{
public:
    CJail(int type, string name) : CSquare(type, name)
    {

    }
};
class CGoToJail : public CSquare
{
public:
    CGoToJail(int type, string name) : CSquare(type, name)
    {

    }
};
class CFreeParking : public CSquare
{
public:
    CFreeParking(int type, string name) : CSquare(type, name)
    {

    }
};

int main()
{
    vector<CSquare*> sqrList;
    string line = "";
    string word = "";
    int sqrType = 0;
    int sqrCost = 0;
    int sqrRent = 0;
    int sqrGroup = 0;
    string nameOne = "";
    string nameTwo = "";
    string nameThree = "";
    string nameFinal = "";
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
                            CGo* sqr = new CGo(sqrType, nameFinal);
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
                            CStation* sqr = new CStation(sqrType, nameFinal);
                            sqrList.push_back(sqr);
                            break;
                        }
                        case 4:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CBonus* sqr = new CBonus(sqrType, nameFinal);
                            sqrList.push_back(sqr);
                            break;
                        }
                        case 5:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CPenalty* sqr = new CPenalty(sqrType, nameFinal);
                            sqrList.push_back(sqr);
                            break;
                        }                           
                        case 6:
                        {
                            sqrType = stoi(word);
                            getline(iss, word, ' ');
                            nameFinal = word;
                            CJail* sqr = new CJail(sqrType, nameFinal);
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
                            CGoToJail* sqr = new CGoToJail(sqrType, nameFinal);
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
                            CFreeParking* sqr = new CFreeParking(sqrType, nameFinal);
                            sqrList.push_back(sqr);
                            break;
                        }                        
                    }
                }
                getline(iss, word, ' ');
            }
        }
    }

    for (vector<CSquare*>::iterator it = sqrList.begin(); it != sqrList.end(); it++)
    {

        cout << (*it)->GetName() << endl;
    }

    system("pause");
    return 0;
}