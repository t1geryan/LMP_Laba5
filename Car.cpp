#include "Car.h"

Car::Car(std::string brand, std::string number, std::string dName, std::string dSurname)
	: brand(brand), number(number), driverName(dName), driverSurname(dSurname)
{}

std::string Car::get_brand() const
{
	return brand;
}

std::string Car::get_car_number() const
{
	return number;
}

void Car::set_car_number(std::string value)
{
	number = value;
}

std::string Car::get_driver_name() const
{
	return driverName;
}

void Car::set_driver_name(std::string value)
{
	driverName = value;
}

std::string Car::get_driver_surname() const
{
	return driverSurname;
}

void Car::set_driver_surname(std::string value)
{
	driverSurname = value;
}

int Car::compare(const Car& other) const
{ 
	int result = 1;
	if (driverSurname < other.driverSurname ||
		driverSurname == other.driverSurname && driverName < other.driverName)
		result = -1;
	else if (number == other.number)
		result = 0;
	return result;
}

std::string Car::toString() const
{
	return driverSurname + ' ' + driverName + ' ' + number + ' ' + brand;
}
