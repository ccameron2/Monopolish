#include "CGameMode.h"

int main()
{
	{
		unique_ptr<CGameMode> monopoly = make_unique<CGameMode>();
		monopoly->ReadInSquares();
		monopoly->PlayGame();
		//delete monopoly;
	}		
	_CrtDumpMemoryLeaks();
	system("pause");
}