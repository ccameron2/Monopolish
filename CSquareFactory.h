#pragma once
#include "CSquare.h"
class CSquareFactory
{
public:
	CSquare* NewSquare(ifstream& file);
};

