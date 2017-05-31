#include <iostream>
#include "Bus.h"
Bus::Bus() : size(0), roominess(0) { };

Bus::Bus(bool mAvailability, int mPrice, int mFuel, double mSize, int mRoominess) : Car(mAvailability, mPrice, mFuel),
																						size(mSize), roominess(mRoominess) {};

Bus::Bus(const Bus &a) 
{
	size = a.size;
	roominess = a.roominess;
}
double Bus::getSize()
{
	return size;
}
int Bus::getRoominess()
{
	return roominess;
}
void Bus::showBus()
{
	showCar();
	std::cout << "Size:" << size << ", " << "Roominess:" << roominess << std::endl;
}
void Bus::setBus(double mSize, int mRoominess)
{
	size = mSize;
	roominess = mRoominess;
}