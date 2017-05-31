#pragma once
#include "Unit.h"
#include "Halberdier.h"

class Skeleton : public Unit
{
public:
	int deathPower;
//	void attack(Halberdier*);
	Skeleton(bool mIsAlive = true, int mHp = 4, int mDamage = 1, int mStamina = 2, int mDeathPower = 0, int mCoordX = 0, int mCoordY = 0) :
		Unit(mIsAlive, mHp, mDamage, mStamina, mCoordX, mCoordY), deathPower(mDeathPower) { };
};

