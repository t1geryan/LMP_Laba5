#pragma once
#include "Car.h"
#include <string> // std::string

enum TruckType {
	TANKER, // цистерна
	VAN, // фургон
	DUMP, // самосвал
	TRACTOR // т€гач
};

class Truck : public Car
{
private:
	size_t tonnage;
	TruckType type;
public:
	Truck(std::string brand = "", TruckType type = TANKER, size_t tonnage = 0, std::string number = "", std::string dName = "", std::string dSurname = "");
	size_t get_tonnage() const;
	TruckType get_type() const;
	std::string get_type_string() const;

	std::string toString() const override;
};

