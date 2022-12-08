#include <iostream> //std::cout
#include <fstream> // std::ifstream
#include <crtdbg.h> // _CrtDumpMemoryLeaks
#include <Windows.h> // SetConsoleCP(), SetConsoleOutputCP

#include "CarPark.h"
#include "PassengerCar.h"
#include "Truck.h"



void session() {
	
	CarPark park("Lorem");
	Truck man = Truck("Man", TRACTOR, 80, "B452XO23", "Petr", "Petrov");
	PassengerCar toyota("Toyota", "Camry", SEDAN, 0, "A123AA136", "Ivan", "Ivanov"), lada("Lada", "Largus", ESTATE, 0, "A231BX36", "Anton", "Antonov");
	
	park.add_car_to_back(std::move(std::make_unique<Truck>(man)));
	park.add_car_by_order(std::move(std::make_unique<PassengerCar>(toyota)));
	park.add_car_to_back(std::move(std::make_unique<PassengerCar>(lada)));
	//park.remove_car(man);

	std::cout << park << '\n';
	park.sort();
	std::cout << park << '\n';
}
int main() { 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	session();
	_CrtDumpMemoryLeaks();
	std::cin.get();
}