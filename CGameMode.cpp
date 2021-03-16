#include "CGameMode.h"

void CGameMode::ReadInSquares()
{
    string line = "";
    string word = "";
    ifstream fin("monopoly.txt");
    if (fin.is_open())
    {
        while (getline(fin, line, '\n'))
        {
            istringstream iss(line);
            while (getline(iss, word, ' '))
            {
                if (!isdigit(stoi(word)))
                {
                    int sqrType = 0;
                    int sqrCost = 0;
                    int sqrRent = 0;
                    int sqrGroup = 8;
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
                        CSquare* sqr = new CProperty(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
                        break;
                    }
                    case 2:
                    {
                        sqrType = stoi(word);
                        getline(iss, word, ' ');
                        nameFinal = word;
                        CSquare* sqr = new CGo(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
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
                        CSquare* sqr = new CStation(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
                        break;
                    }
                    case 4:
                    {
                        sqrType = stoi(word);
                        getline(iss, word, ' ');
                        nameFinal = word;
                        CSquare* sqr = new CBonus(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
                        break;
                    }
                    case 5:
                    {
                        sqrType = stoi(word);
                        getline(iss, word, ' ');
                        nameFinal = word;
                        CSquare* sqr = new CPenalty(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
                        break;
                    }
                    case 6:
                    {
                        sqrType = stoi(word);
                        getline(iss, word, ' ');
                        nameFinal = word;
                        CSquare* sqr = new CJail(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
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
                        CSquare* sqr = new CGoToJail(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
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
                        CSquare* sqr = new CFreeParking(sqrType, nameFinal, sqrCost, sqrRent, sqrGroup);
                        squareList.push_back(sqr);
                        break;
                    }
                    }
                }
                getline(iss, word, ' ');
            }
        }
    }
    fin.close();
}
void CGameMode::PlayGame()
{
    srand(ReadInSeed());
    //Game loop setup
    int startMoney = 1500;
    int startPosition = 0;
    string nameOne = "Dog";
    string nameTwo = "Car";

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
            int roll = (*it)->Random();
            cout << (*it)->GetName() << " rolls " << roll << endl;
            if ((*it)->GetPosition() + roll > squareList.size() - 1)
            {
                (*it)->SetPosition((*it)->GetPosition() + roll - 26);
            }
            else
            {
                (*it)->SetPosition((*it)->GetPosition() + roll);
            }
            squareList[(*it)->GetPosition()]->LandedOn((*it), squareList);
            cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;
        }
        CheckRent();
    }
    //End game
    cout << "Game Over" << endl;
    for (vector<CPlayer*>::iterator it = playerList.begin(); it != playerList.end(); it++)
    {
        cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;
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

    for (vector<CSquare*>::iterator it = squareList.begin(); it != squareList.end(); it++)
    {
        delete* it;
    }
    for (vector<CPlayer*>::iterator it = playerList.begin(); it != playerList.end(); it++)
    {
        delete* it;
    }
}
int CGameMode::ReadInSeed()
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

void CGameMode::CheckRent()
{
    vector<CSquare*> ownedProperties;
    for (vector<CSquare*>::iterator it = squareList.begin(); it != squareList.end(); it++)
    {
        if ((*it)->GetOwner() != nullptr)
        {
            if (!(*it)->GetIsDoubleRent())
            {
                ownedProperties.push_back((*it));
            }            
        }
    }
    int size = ownedProperties.size();
    for (int i = 0; i < size - 2; i++)
    {
        switch (ownedProperties[i]->GetGroup())
        {
        case 3 || 6:
            if (i + 2 < ownedProperties.size())
            {
                if (ownedProperties[i]->GetGroup() == ownedProperties[i++]->GetGroup() && ownedProperties[i++]->GetGroup() == ownedProperties[i + 2]->GetGroup())
                {
                    if (ownedProperties[i]->GetOwner() == ownedProperties[i++]->GetOwner() && ownedProperties[i++]->GetOwner() == ownedProperties[i + 2]->GetOwner())
                    {
                        ownedProperties[i]->SetIsDoubleRent(true);
                        ownedProperties[i++]->SetIsDoubleRent(true);
                        ownedProperties[i + 2]->SetIsDoubleRent(true);
                        ownedProperties[i]->SetRent(ownedProperties[i]->GetRent() * 2);
                        ownedProperties[i++]->SetRent(ownedProperties[i++]->GetRent() * 2);
                        ownedProperties[i + 2]->SetRent(ownedProperties[i + 2]->GetRent() * 2);
                    }
                }
            }
            break;
        default:
            if (i++ < ownedProperties.size())
            {
                if (ownedProperties[i]->GetGroup() == ownedProperties[i++]->GetGroup())
                {
                    if (ownedProperties[i]->GetOwner() == ownedProperties[i++]->GetOwner())
                    {
                        ownedProperties[i]->SetIsDoubleRent(true);
                        ownedProperties[i++]->SetIsDoubleRent(true);
                        ownedProperties[i]->SetRent(ownedProperties[i]->GetRent() * 2);
                        ownedProperties[i++]->SetRent(ownedProperties[i++]->GetRent() * 2);
                    }
                }                                                                    
            }
            break;
        }
    }
}