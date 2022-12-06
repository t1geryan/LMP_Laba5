#include "Truck.h"

Truck::Truck(std::string brand, std::string number, std::string dName, std::string dSurname, TruckType type, size_t tonnage)
: Car(brand, number, dName, dSurname), type(type), tonnage(tonnage) {}

size_t Truck::get_tonnage()
{
    return tonnage;
}

TruckType Truck::get_type()
{
    return type;
}

std::string Truck::get_type_string()
{
    std::string result = "";
    switch (type)
    {
    case TANKER:
        result = "Tanker";
        break;
    case VAN:
        result = "Van";
        break;
    case DUMP:
        result = "Dump Truck";
        break;
    default:
        break;
    }
    return result;
}

std::string Truck::toString()
{
    return "Truck: " + Car::toString() + ' ' + get_type_string() + ' ' + std::to_string(tonnage) + "ton";
}
