#pragma once
#include <string>

class Car
{
private:
	std::string brand, number, driverName, driverSurname;
public:
	Car(std::string brand = "", std::string number = "", std::string dName = "", std::string dSurname = "");

	std::string get_brand();

	std::string get_car_number();
	void set_car_number(std::string value);

	std::string get_driver_name();
	void set_driver_name(std::string value);

	std::string get_driver_surname();
	void set_driver_surname(std::string value);

	int compare(const Car& other);

	virtual std::string toString();
};

