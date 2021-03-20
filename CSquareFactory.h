#pragma once
#include "CSquare.h"
class CSquareFactory
{
public:
	unique_ptr<CSquare> NewSquare(ifstream& file);
};

