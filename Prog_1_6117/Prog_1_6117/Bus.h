#pragma once
#include "Car.h"
class Bus : public Car
{
public:
	Bus();
	int roominess;
	double size;
	Bus(bool, int, int, double, int); 
	double getSize();
	int getRoominess();
	void showBus();
	void setBus(double, int);
	Bus(const Bus&);
};

