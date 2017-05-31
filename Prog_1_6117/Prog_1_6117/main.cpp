#include <iostream>
#include "Car.h"
#include "Bus.h"
using namespace std;
int main() {
	bool availability;
	int price, fuel, roominess;
	double size;
	availability = false; // availability = true;
	price = 80;
	fuel = 23;
	/*Car car; 
	car = Car(availability, price, fuel);
	car.showCar();
	size = 4.9;
	roominess = 7.8;
	Bus car2;
	car2 = Bus(availability, price, fuel, size, roominess);
	car2.showBus();*/
	size = 45.7;
	roominess = 21;
	Bus car2;
	car2 = Bus(availability, price, fuel, size, roominess);
	car2.showBus();
	system("pause");
	return 0;
}