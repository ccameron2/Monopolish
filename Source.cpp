#include "CGameMode.h"

int main()
{
	CGameMode* monopoly = new CGameMode();
	monopoly->ReadInSquares();
	monopoly->PlayGame();
	system("pause");
}