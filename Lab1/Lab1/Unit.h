#pragma once
class Unit
{
public:
	int hp, mp, speed;
	Unit() : hp(0), mp(0), speed(0), x_(0), y_(0) { };
	~Unit();
private:
	double x_, y_;
};

