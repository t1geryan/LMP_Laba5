#include <iostream> //std::cout
#include <fstream> // std::ifstream
#include <crtdbg.h> // _CrtDumpMemoryLeaks
#include <Windows.h> // SetConsoleCP(), SetConsoleOutputCP

#include "CarPark.h"
#include "PassengerCar.h"
#include "Truck.h"

// инициализировать автомобильный парк из файла
void init_car_park(CarPark& park, std::ifstream& file);
// решение задачи с удалением всех грузовиков типа фургон
void do_task(CarPark& park)
{
	auto is_van = [](const info_t& uptrCar)->bool {
		Truck* t = dynamic_cast<Truck*>(uptrCar.get());
		bool result = false;
		if (t && t->get_type() == VAN)
			result = true;
		return result;
	};
	park.erase_car_if(is_van);
}
int main() { 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	{
		std::ifstream file("data.txt");
		CarPark park("My Car Park");
		init_car_park(park, file);
		std::cout << park << "\n----------------------\n";
		do_task(park);
		std::cout << park;
		
	}
	_CrtDumpMemoryLeaks();
	std::cout << "\nНажмите любую клавишу для завершения работы программы\n";
	std::cin.get();
}

void init_car_park(CarPark& park, std::ifstream& file)
{
	char type;
	std::string brand, number, driverName, driverSurname;
	std::string model, bodyType, truckType;
	int tonnage, color;
	while (file >> type)
	{
		file >> brand >> number >> driverName >> driverSurname;
		if (type == 'P') {
			file >> model >> bodyType >> color;
			PassengerCar pCar = PassengerCar(brand, model, PassengerCar::string_to_body_type(bodyType), color, number, driverName, driverSurname);
			park.add_car_by_order(std::move(std::make_unique<PassengerCar>(pCar)));
		}
		else {
			file >> truckType >> tonnage;
			Truck truck = Truck(brand, Truck::string_to_truck_type(truckType), tonnage, number, driverName, driverSurname);
			park.add_car_by_order(std::move(std::make_unique<Truck>(truck)));
		}
	}
	file.close();
}