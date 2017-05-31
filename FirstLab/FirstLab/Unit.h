#pragma once
class Unit
{
public:
	int hp, damage, stamina, coordX, coordY;;
	bool isAlive;
	void move(int, int);
	Unit() : hp(5), damage(2), stamina(1), coordX(0), coordY(0) {};
	Unit(bool mIsAlive, int mHp, int mDamage, int mStamina, int mCoordX, int mCoordY) :
		isAlive(mIsAlive), hp(mHp), damage(mDamage), stamina(mStamina), coordX(mCoordX), coordY(mCoordY){ };
	Unit::Unit(const Unit &a) {
		hp = a.hp;
		damage = a.damage;
		stamina = a.stamina;
	}
	~Unit();
private:
	//int coordX, coordY;
};

