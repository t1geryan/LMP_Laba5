#pragma once
#include "Car.h"

enum TruckType {
	TANKER, // цистерна
	VAN, // фургон
	DUMP // самосвал

};

class Truck : public Car
{
private:
	size_t tonnage;
	TruckType type;
public:
	Truck(std::string brand = "", std::string number = "", std::string dName = "", std::string dSurname = "", TruckType type = TANKER, size_t tonnage = 0);
	size_t get_tonnage();
	TruckType get_type();
	std::string get_type_string();

	std::string toString() override;
};

