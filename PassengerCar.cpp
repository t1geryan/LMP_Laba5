#include "PassengerCar.h"

PassengerCar::PassengerCar(std::string brand, std::string model, std::string number, std::string dName, std::string dSurname, CarBodyType bodyType, int color)
    : Car(brand, number, dName, dSurname), model(model), bodyType(bodyType), color(color) {}

CarBodyType PassengerCar::get_body_type()
{
    return bodyType;
}

std::string PassengerCar::get_body_type_string()
{
    std::string result = "";
    switch (bodyType)
    {
    case SEDAN:
        result = "Sedan";
        break;
    case HATCHBACK:
        result = "Hatchback";
        break;
    case ESTATE:
        result = "Estate";
        break;
    }
    return result;
}

std::string PassengerCar::get_model()
{
    return model;
}

int PassengerCar::get_color()
{
    return color;
}

void PassengerCar::set_color(int value)
{
    color = value;
}

std::string PassengerCar::toString()
{
    return "Passenger: " + Car::toString() + ' ' + model + ' ' + get_body_type_string();
}

