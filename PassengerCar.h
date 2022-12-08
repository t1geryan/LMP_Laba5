#pragma once
#include "Car.h"
#include <string> // std::string

enum CarBodyType {
	SEDAN, // Седан
	HATCHBACK, // Хэтчбэк
	ESTATE, // Универсал
	SUV // внедорожник
};

class PassengerCar : public Car
{
private:
	CarBodyType bodyType;
	std::string model;
	int color;
public:
	PassengerCar(std::string brand = "", std::string model = "", CarBodyType bodyType = SEDAN, int color = 0, std::string number = "", std::string dName = "", std::string dSurname = "");

	CarBodyType get_body_type() const;
	std::string get_body_type_string() const;
	std::string get_model() const;

	int get_color() const;
	void set_color(int value);
	std::string toString() const override;
};

