#include "Unit.h"

void Unit::move(int x, int y)
{
	coordX += x;
	coordY += y;
}

Unit::~Unit()
{
}
