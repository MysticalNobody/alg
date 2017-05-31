#pragma once
#include "Unit.h"
#include "Skeleton.h"
class Halberdier : public Unit
{
public:
//	void attack(Skeleton*);
	Halberdier(bool mIsAlive = true, int mHp = 5, int mDamage = 2, int mStamina = 2, int mCoordX = 0, int mCoordY = 0) :
		Unit(mIsAlive, mHp, mDamage, mStamina, mCoordX, mCoordY) { };
};

