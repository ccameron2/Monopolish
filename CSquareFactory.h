#pragma once
#include "CSquare.h"
class CSquareFactory
{
public:
	shared_ptr<CSquare> NewSquare(ifstream& file);
};

