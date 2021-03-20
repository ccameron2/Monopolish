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

    unique_ptr<CPlayer> Dog = make_unique<CPlayer>(nameOne, startMoney, startPosition);
    unique_ptr<CPlayer> Car = make_unique<CPlayer>(nameTwo, startMoney, startPosition);
    unique_ptr<CPlayer> Shoe = make_unique<CPlayer>(nameThree, startMoney, startPosition);
    unique_ptr<CPlayer> Hat = make_unique<CPlayer>(nameFour, startMoney, startPosition);

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
                if (unsigned((*it)->GetPosition()) + roll > squareList.size() - 1)
                {
                    (*it)->SetPosition((*it)->GetPosition() + roll - 26);
                    cout << (*it)->GetName() << " passes GO and collects " << POUND << "200 " << endl;
                    (*it)->ChangeMoney(200);
                }
                else
                {
                    (*it)->SetPosition((*it)->GetPosition() + roll);
                }
                cout << (*it)->GetName() << " lands on " << squareList[(*it)->GetPosition()]->GetName() << endl;
                squareList[(*it)->GetPosition()]->LandedOn(it->get());
                CheckMortgage(it->get());
                cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;               
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
    squareObserverVector groupedProperties;
	for(int i = 0; i < 8; i++)
    {
        CPlayer* groupOwner = nullptr;
        bool allOwned = false;
        for (auto it = squareList.begin(); it != squareList.end(); it++)
        {
            if ((*it)->GetGroup() == i)
            {
                groupedProperties.push_back(it->get());
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

void CGameMode::CheckMortgage(CPlayer* player)
{
    squareObserverVector ownedProperties;
    squareObserverVector mortgagedProperties;
    int combPropValue = 0;
    for (auto it = squareList.begin(); it != squareList.end(); it++)
    {
        if ((*it)->GetOwner() == player && !(*it)->GetIsMortgaged())
        {
            ownedProperties.push_back(it->get());
        }
        else if ((*it)->GetOwner() == player && (*it)->GetIsMortgaged())
        {
            mortgagedProperties.push_back(it->get());
        }
    }

    if (player->GetMoney() < 0)
    {   
              
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
            for (auto it = ownedProperties.begin(); it != ownedProperties.end(); it++)
            {
                if (player->GetMoney() < 0)
                {
                    cout << player->GetName() << " mortgages " << (*it)->GetName() << " for " << POUND << (*it)->GetCost() << endl;
                    player->ChangeMoney((*it)->GetCost());
                    (*it)->SetIsMortgaged(true);
                }                                               
            }
           
        }
                                           
    }
    else
    {
        if (mortgagedProperties.size() > 0)
        {
            if (player->GetMoney() - mortgagedProperties.front()->GetCost() > 0)
            {
                cout << player->GetName() << " buys " << mortgagedProperties.front()->GetName() << " back again for " << POUND << mortgagedProperties.front()->GetCost() << endl;
                mortgagedProperties.front()->SetIsMortgaged(false);
                player->ChangeMoney(-mortgagedProperties.front()->GetCost());
            }
        }
    }
}