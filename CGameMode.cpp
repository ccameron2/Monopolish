#include "CGameMode.h"
#include "CSquareFactory.h"

void CGameMode::ReadInSquares()
{
    //Create Square Factory.
    unique_ptr<CSquareFactory> sqrFact = make_unique<CSquareFactory>();
    
    //Create file stream.
    ifstream fin("monopoly.txt");

    //Read data from file stream and then close the file.
    if (fin.is_open())
    {
        while (fin)
        {   
            //Move the pointer returned by Square Factory into Square List.   
            squareList.push_back(move(sqrFact->NewSquare(fin)));            
        }
    }
    squareList.pop_back();
    fin.close();
}
void CGameMode::PlayGame()
{
    //Read provided seed from file.
    srand(ReadInSeed());

    //Initialize variables for player creation.
    int startMoney = 1500;
    int startPosition = 0;
    string nameOne = "Dog";
    string nameTwo = "Car";
    string nameThree = "Shoe";
    string nameFour = "Hat";

    //Create player pointers.
    unique_ptr<CPlayer> Dog = make_unique<CPlayer>(nameOne, startMoney, startPosition);
    unique_ptr<CPlayer> Car = make_unique<CPlayer>(nameTwo, startMoney, startPosition);
    unique_ptr<CPlayer> Shoe = make_unique<CPlayer>(nameThree, startMoney, startPosition);
    unique_ptr<CPlayer> Hat = make_unique<CPlayer>(nameFour, startMoney, startPosition);

    //Move players into Player List.
    playerList.push_back(move(Dog));
    playerList.push_back(move(Car));
    playerList.push_back(move(Shoe));
    playerList.push_back(move(Hat));

    //Output title
    cout << "Welcome to Monopol-ish" << endl << endl;

    bool gameOver = false;

    //Game Loop
    
    //Until all players are bankrupt
    //while(!gameOver)

    //(Game never ends so swapped back to 20 round limit)

    //For 20 rounds.
    for(int i = 0; i < 20; i++) 
    {   
        //For each player in list.
        for (auto it = playerList.begin(); it != playerList.end(); it++) 
        {
            //If player is not bankrupt.
            if (!(*it)->GetIsBankrupt()) 
            {
                //Get a new random value for player and output to console.
                int roll = (*it)->Random();
                cout << (*it)->GetName() << " rolls " << roll << endl;

                //Add roll value to position and reset position if player goes too far.
                if (unsigned((*it)->GetPosition()) + roll > squareList.size() - 1)
                {
                    //Position is reset, player gains £200
                    (*it)->SetPosition((*it)->GetPosition() + roll - 26);                    
                    cout << (*it)->GetName() << " passes GO and collects " << POUND << "200 " << endl;
                    (*it)->ChangeMoney(200);
                }
                else
                {
                    (*it)->SetPosition((*it)->GetPosition() + roll);
                }

                //Output player position to console.
                cout << (*it)->GetName() << " lands on " << squareList[(*it)->GetPosition()]->GetName() << endl;

                //Apply square's effects to player.
                squareList[(*it)->GetPosition()]->LandedOn(it->get());

                //Check player's properties for mortgages.
                CheckMortgage(it->get());

                //Output player's money to console.
                cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl; 

                //Display when a player is bankrupt.
                if ((*it)->GetIsBankrupt())
                {
                    cout << (*it)->GetName() << " has gone bankrupt and lost the game." << endl;
                }

                //Check player's double rent status
                CheckRent();
            }

            //Check how many players are bankrupt.
            int bankruptcyRate = 0;
            for (auto it = playerList.begin(); it != playerList.end(); it++)
            {
                if ((*it)->GetIsBankrupt())
                {
                    bankruptcyRate++;
                }
            }
            //End the game if only 1 remains.
            if (bankruptcyRate == playerList.size() - 1)
            {
                gameOver = true;
            }            
            cout << endl;
        }            
                
    }

    //Display Game Over message.
    cout << "Game Over" << endl;

    //Output each player's money and save the winning amount.
    int winningAmount = 0;
    for (auto it = playerList.begin(); it != playerList.end(); it++)
    {
        cout << (*it)->GetName() << " has " << POUND << (*it)->GetMoney() << endl;
        if ((*it)->GetMoney() > winningAmount)
        {
            winningAmount = (*it)->GetMoney(); 
        }
    }

    //Declare the player with the winning amount of money the winner.
    for (auto it = playerList.begin(); it != playerList.end(); it++)
    {
        if ((*it)->GetMoney() == winningAmount)
        {
            cout << (*it)->GetName() << " wins." << endl;
        }
    }
}
int CGameMode::ReadInSeed()
{
    //Create file stream.
    ifstream fin("seed.txt");
    int seed = 0;

    //Read seed and close file.
    if (fin.is_open())
    {
        fin >> seed;
    }
    fin.close();

    return seed;
}

void CGameMode::CheckRent()
{
    //Create temporary vector to hold properties by group.
    tempSquareVector groupedProperties;

    //For each group of properties.
	for(int i = 0; i < 8; i++)
    {
        //Collect properties of the same group        
        for (auto it = squareList.begin(); it != squareList.end(); it++)
        {
            if ((*it)->GetGroup() == i)
            {
                groupedProperties.push_back(it->get());
            }            
        }
        //Get the owner of the first property.
        bool allOwned = false;
        CPlayer* groupOwner = groupedProperties.front()->GetOwner();
        
        //Compare the owner of each property to the owner of the first property.
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
                        break;
                    }
                }
                else
                {
                    allOwned = false;
                }
            }
        }

        //If all properties are owned by the same player.
        if (allOwned)
        {
            for (auto it = groupedProperties.begin(); it != groupedProperties.end(); it++)
            {
                if (!(*it)->GetIsDoubleRent())
                {
                    //Set flag to track properties affected by rent doubling.
                    (*it)->SetIsDoubleRent(true);

                    //Double properties rent.
                    (*it)->SetRent((*it)->GetRent() * 2);
                }                                
            }
        }

        //Clear the temporary vector.
        groupedProperties.clear();
    } 
}

void CGameMode::CheckMortgage(CPlayer* player)
{
    //Create temporary vectors to hold properties.
    tempSquareVector ownedProperties;
    tempSquareVector mortgagedProperties;

    //Sort properties into owned and mortgaged.
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
        //Calculate cost of all owned properties.
        int combPropValue = 0;
        for (auto it = ownedProperties.begin(); it != ownedProperties.end(); it++)
        {
            combPropValue += (*it)->GetCost();
        }

        //If the player cant afford to stay in the game.
        if (player->GetMoney() + combPropValue < 0)
        {
            //Flag player as bankrupt.
            player->SetIsBankrupt(true);

            //Reset all the properties owned and mortgaged by the player.
            for (auto it = ownedProperties.begin(); it != ownedProperties.end(); it++)
            {
                (*it)->SetOwner(nullptr);
                (*it)->SetIsDoubleRent(false);
            }
            for (auto it = mortgagedProperties.begin(); it != mortgagedProperties.end(); it++)
            {
                (*it)->SetOwner(nullptr);
                (*it)->SetIsMortgaged(false);
                (*it)->SetIsDoubleRent(false);
            }
        }
        else
        {
            //Mortgage properties until player's money is above 0.
            for (auto it = ownedProperties.begin(); it != ownedProperties.end(); it++)
            {
                if (player->GetMoney() < 0)
                {
                    //Output mortgage message to console.
                    cout << player->GetName() << " mortgages " << (*it)->GetName() << " for " << POUND << (*it)->GetCost() << endl;

                    //Pay player for the property and flag it as mortgaged.
                    player->ChangeMoney((*it)->GetCost());                    
                    (*it)->SetIsMortgaged(true);
                }                                               
            }
           
        }
                                           
    }
    else
    {
        //If the player has mortgaged properties. 
        if (mortgagedProperties.size() > 0)
        {
            //If they can afford to buy the cheapest one back.
            if (player->GetMoney() - mortgagedProperties.front()->GetCost() > 0)
            {
                //Output re-purchase message from screen.
                cout << player->GetName() << " buys " << mortgagedProperties.front()->GetName() << " back again for " << POUND << mortgagedProperties.front()->GetCost() << endl;
                
                //Un-Flag the property as mortgaged.
                mortgagedProperties.front()->SetIsMortgaged(false);

                //Take payment from the player for the property.
                player->ChangeMoney(-mortgagedProperties.front()->GetCost());
            }
        }
    }
}