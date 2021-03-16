#include "CGameMode.h"

int main()
{
	CGameMode* monopoly = new CGameMode();
	monopoly->ReadInSquares();
	monopoly->PlayGame();
	delete monopoly;
	_CrtDumpMemoryLeaks();
	system("pause");
}