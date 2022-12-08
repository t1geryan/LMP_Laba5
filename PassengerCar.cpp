#include "PassengerCar.h"

PassengerCar::PassengerCar(std::string brand, std::string model, CarBodyType bodyType, int color, std::string number, std::string dName, std::string dSurname)
    : Car(brand, number, dName, dSurname), model(model), bodyType(bodyType), color(color) {}

CarBodyType PassengerCar::get_body_type() const
{
    return bodyType;
}

std::string PassengerCar::get_body_type_string() const
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
    case SUV:
        result = "Suv";
        break;
    }
    return result;
}

CarBodyType PassengerCar::string_to_body_type(std::string str)
{
    CarBodyType result;
    if (str == "SEDAN")
        result = SEDAN;
    else if (str == "HATCHBACK")
        result = HATCHBACK;
    else if (str == "ESTATE")
        result = ESTATE;
    else
        result = SUV;
    return result;
}

std::string PassengerCar::get_model() const
{
    return model;
}

int PassengerCar::get_color() const
{ 
    return color;
}

void PassengerCar::set_color(int value)
{
    color = value;
}

std::string PassengerCar::toString() const
{
    return "Passenger: " + Car::toString() + ' ' + model + ' ' + get_body_type_string() + ' ' + std::to_string(color) + "rgb";
}

