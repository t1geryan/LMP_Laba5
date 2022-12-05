#pragma once
#include "Car.h"

enum CarBodyType {
	SEDAN, // Седан
	HATCHBACK, // Хэтчбэк
	ESTATE // Универсал
};

class PassengerCar : public Car
{
private:
	CarBodyType bodyType;
	std::string model;
	int color;
public:
	PassengerCar(std::string brand = "", std::string model = "", std::string number = "", std::string dName = "", std::string dSurname = "", CarBodyType bodyType = SEDAN, int color = 0);

	CarBodyType get_body_type();
	std::string get_body_type_string();
	std::string get_model();

	int get_color();
	void set_color(int value);
	std::string toString() override;
};

