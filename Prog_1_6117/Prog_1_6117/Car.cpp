#include "Car.h"
#include <iostream>

Car::Car() : availability_(false), price(0), fuel(0) { };

Car::Car(bool mAvailability, int mPrice, int mFuel) : availability_(mAvailability), price(mPrice), fuel(mFuel) {};

Car::Car(const Car &a)
{
	fuel = a.fuel;
	price = a.price;
}
bool Car::getAvailability() 
{
	return availability_;
}
int Car::getFuel() 
{
	return fuel;
}
int Car:: getPrice() 
{
	return price;
}
void Car::setCar(bool mAvailability, int mFuel, int mPrice)
{
	availability_ = mAvailability;
	fuel = mFuel;
	price = mPrice;
}

void Car::showCar()
{
	if (availability_)
		std::cout << "Availability, " << "fuel:" << fuel << ", " << "price:" << price << std::endl;
	else
		std::cout << "Not availability, " << "fuel:" << fuel << ", " << "price:" << price << std::endl;
}
