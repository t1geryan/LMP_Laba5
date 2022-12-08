#include "Truck.h"

Truck::Truck(std::string brand, TruckType type, size_t tonnage, std::string number, std::string dName, std::string dSurname)
: Car(brand, number, dName, dSurname), type(type), tonnage(tonnage) {}

size_t Truck::get_tonnage() const
{
    return tonnage;
}

TruckType Truck::get_type() const
{
    return type;
}

std::string Truck::get_type_string() const
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
    case TRACTOR:
        result = "Tractor";
        break;
    }
    return result;
}

TruckType Truck::string_to_truck_type(std::string str)
{
    TruckType result;
    if (str == "TANKER")
        result = TANKER;
    else if (str == "VAN")
        result = VAN;
    else if (str == "DUMP")
        result = DUMP;
    else
        result = TRACTOR;
    return result;
}

std::string Truck::toString() const
{
    return "Truck: " + Car::toString() + ' ' + get_type_string() + ' ' + std::to_string(tonnage) + "ton";
}
