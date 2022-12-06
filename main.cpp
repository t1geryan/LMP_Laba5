#include <iostream>
#include <list>
#include <crtdbg.h>
#include <memory>

#include "Truck.h"
#include "PassengerCar.h"

void session() {
	std::list<std::unique_ptr<Car>> list;
	list.push_back(std::make_unique<Truck>(Truck("Toyota", "EX123U136", "Ivan", "Ivanov", TANKER, 30)));
	list.push_back(std::make_unique<PassengerCar>(PassengerCar("Toyota", "Camry", "AA111A36", "Petr", "Petrov", SEDAN, 0xFFFFFF)));
	for (auto i = list.begin(); i != list.end(); ++i)
		std::cout << (*i)->toString() << '\n';

}
int main() { 
	session();

	_CrtDumpMemoryLeaks();
	std::cin.get();
}