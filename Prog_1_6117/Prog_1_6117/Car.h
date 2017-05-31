#pragma once
class Car
{
private:
	bool availability_; 
public:
	Car();
	Car(bool, int, int);
	int price, fuel;
	bool getAvailability();
	int getFuel();
	int getPrice();
	void setCar(bool, int, int);
	void showCar();
	Car(const Car&);
};
