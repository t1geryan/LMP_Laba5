#pragma once
#include <string> // std::string

class Car
{
private:
	std::string brand, number, driverName, driverSurname;
public:
	Car(std::string brand = "", std::string number = "", std::string dName = "", std::string dSurname = "");
	virtual ~Car() {};
	std::string get_brand() const;

	std::string get_car_number() const;
	void set_car_number(std::string value);

	std::string get_driver_name() const;
	void set_driver_name(std::string value);

	std::string get_driver_surname() const;
	void set_driver_surname(std::string value);

	int compare(const Car& other) const;

	virtual std::string toString() const;
};

