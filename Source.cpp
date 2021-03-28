#include "CGameMode.h"

int main()
{
	{
		//Create gamemode, read in squares and play game.
		unique_ptr<CGameMode> monopoly = make_unique<CGameMode>();
		monopoly->ReadInSquares();
		monopoly->PlayGame();
	}		
	_CrtDumpMemoryLeaks();
}