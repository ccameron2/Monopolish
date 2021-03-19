#include "CGameMode.h"
#include "CSquareFactory.h"


void CGameMode::ReadInSquares()
{
    unique_ptr<CSquareFactory> sqrFact = make_unique<CSquareFactory>();
    string line = "";
    string word = "";
    ifstream fin("monopoly.txt");
    if (fin.is_open())
    {
        while (fin)
        {          
            squareList.push_back(move(sqrFact->NewSquare(fin)));            
        }
    }
    squareList.pop_back();
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
    string nameThree = "Shoe";
    string nameFour = "Hat";

    shared_ptr<CPlayer> Dog = make_shared<CPlayer>(nameOne, startMoney, startPosition);
    shared_ptr<CPlayer> Car = make_shared<CPlayer>(nameTwo, startMoney, startPosition);
    shared_ptr<CPlayer> Shoe =make_shared<CPlayer>(nameThree, startMoney, startPosition);
    shared_ptr<CPlayer> Hat = make_shared<CPlayer>(nameFour, startMoney, startPosition);

    playerList.push_back(move(Dog));
    playerList.push_back(move(Car));
    playerList.push_back(move(Shoe));
    playerList.push_back(move(Hat));

    cout << "Welcome to Monopol-ish" << endl;

    bool gameOver = false;
    //Game Loop
    //while(!gameOver)
    for(int i = 0; i < 20; i++)
    {                                        
        for (auto it = playerList.begin(); it != playerList.end(); it++)
        {
            if (!(*it)->GetIsBankrupt())
            {
                int roll = (*it)->Random();
                cout << (*it)->GetName() << " rolls " << roll << endl;
                if ((*it)->GetPosition() + roll > squareList.size() - 1)
                {
                    (*it)->SetPosition((*it)->GetPosition() + roll - 26);
                    cout << (*it)->GetName() << " passes GO and collects " << POUND << "200 " << endl;
                    (*it)->ChangeMoney(200);
                }
                else
                {
                    (*it)->SetPosition((*it)->GetPosition() + roll);
                }
                squareList[(*it)->GetPosition()]->LandedOn((*it));
                cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;
                CheckMortgage((*it));
                if ((*it)->GetIsBankrupt())
                {
                    cout << (*it)->GetName() << " has gone bankrupt and lost the game." << endl;
                }
                CheckRent();

            }
            int bankruptcyRate = 0;
            for (auto it = playerList.begin(); it != playerList.end(); it++)
            {
                if ((*it)->GetIsBankrupt())
                {
                    bankruptcyRate++;
                }
            }
            if (bankruptcyRate == playerList.size() - 1)
            {
                gameOver = true;
            }
            cout << endl;
        }            
                
    }
    //End game
    cout << "Game Over" << endl;
  
    int winningAmount = 0;
    for (auto it = playerList.begin(); it != playerList.end(); it++)
    {
        cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;
        if ((*it)->GetMoney() > winningAmount){winningAmount = (*it)->GetMoney(); }
    }
    for (auto it = playerList.begin(); it != playerList.end(); it++)
    {
        if ((*it)->GetMoney() == winningAmount)
        {
            cout << (*it)->GetName() << " wins." << endl;
        }
    }
    /*for (auto it = squareList.begin(); it != squareList.end(); it++)
    {
        delete* it;
    }*/
    //for (auto it = playerList.begin(); it != playerList.end(); it++)
    //{
    //    delete* it;
    //}
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
    squareVector groupedProperties;
	for(int i = 0; i < 8; i++)
    {
        shared_ptr<CPlayer> groupOwner = nullptr;
        bool allOwned = false;
        for (auto it = squareList.begin(); it != squareList.end(); it++)
        {
            if ((*it)->GetGroup() == i)
            {
                groupedProperties.push_back(*it);
            }            
        }
        groupOwner = groupedProperties.front()->GetOwner();
        if (groupOwner != nullptr)
        {
            for (auto it = groupedProperties.begin(); it != groupedProperties.end(); it++)
            {
                if ((*it)->GetOwner() != nullptr)
                {
                    if ((*it)->GetOwner() == groupOwner)
                    {
                        allOwned = true;
                    }
                    else
                    {
                        allOwned = false;
                    }
                }
                else
                {
                    allOwned = false;
                }
            }
        }        
        if (allOwned)
        {
            for (auto it = groupedProperties.begin(); it != groupedProperties.end(); it++)
            {
                if (!(*it)->GetIsDoubleRent())
                {
                    (*it)->SetIsDoubleRent(true);
                    (*it)->SetRent((*it)->GetRent() * 2);
                }                                
            }
        }
        groupedProperties.clear();
    } 
}

void CGameMode::CheckMortgage(shared_ptr<CPlayer> player)
{
    squareVector ownedProperties;
    squareVector mortgagedProperties;
    int combPropValue = 0;
    if (player->GetMoney() < 0)
    {   
        for (auto it = squareList.begin(); it != squareList.end(); it++)
        {
            if ((*it)->GetOwner() == player && !(*it)->GetIsMortgaged())
            {
                ownedProperties.push_back((*it));
            }
            else if ((*it)->GetOwner() == player && (*it)->GetIsMortgaged())
            {
                mortgagedProperties.push_back((*it));
            }
        }        
        for (auto it = ownedProperties.begin(); it != ownedProperties.end(); it++)
        {
            combPropValue += (*it)->GetCost();
        }
        if (player->GetMoney() + combPropValue < 0)
        {
            player->SetIsBankrupt(true);
            for (auto it = ownedProperties.begin(); it != ownedProperties.end(); it++)
            {
                (*it)->SetOwner(nullptr);
                (*it)->SetIsMortgaged(false);
                (*it)->SetIsDoubleRent(false);
            }
        }
        else
        {
            cout << player->GetName() << " mortgages " << ownedProperties.front()->GetName() << " for " << ownedProperties.front()->GetCost() << endl;
            player->ChangeMoney(ownedProperties.front()->GetCost());
            ownedProperties.front()->SetIsMortgaged(true);
        }
        if (mortgagedProperties.size() != 0)
        {
            if (player->GetMoney() - mortgagedProperties.front()->GetCost() > 0)
            {
                cout << player->GetName() << " buys " << ownedProperties.front()->GetName() << " back again for " << ownedProperties.front()->GetCost() << endl;
                mortgagedProperties.front()->SetIsMortgaged(false);
                player->ChangeMoney(-mortgagedProperties.front()->GetCost());
            }
        }                                        
    }

}