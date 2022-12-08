#include "CarPark.h"

CarPark::CarPark(std::string name) : name(name) {}

std::string CarPark::get_park_name() const
{
	return name;
}

void CarPark::set_park_name(std::string value)
{
	name = value;
}

// полиморфизм не реализуется из-за make_unique<Car!!!!> - как и где определять тип?
void CarPark::add_car_by_order(info_t uptrCar)
{
	auto i = carList.begin();
	while (i != carList.end() && (*i)->compare(*uptrCar) == -1)
		++i;
	carList.insert(i, std::move(uptrCar));
}

void CarPark::add_car_to_begin(info_t uptrCar)
{
	carList.push_front(std::move(uptrCar));
}

void CarPark::add_car_to_back(info_t uptrCar)
{
	carList.push_back(std::move(uptrCar));
}

void CarPark::remove_car(const Car& car)
{
	for (auto i = carList.begin(); i != carList.end();)
		if ((*i)->compare(car) == 0)
			i = carList.erase(i);
		else ++i;
}

void CarPark::sort()
{ 
	carList.sort([](const info_t& pCar1, const info_t& pCar2) {return pCar1->compare(*pCar2) == -1; });
}

std::ostream& operator<<(std::ostream& out, const CarPark& object)
{
	for (const info_t& pCar : object.carList)
		out << pCar->toString() << '\n';
	return out;
}
