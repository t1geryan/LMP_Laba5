#pragma once
#include "Car.h" 
#include <list> // std::list
#include <string> // std::string
#include <memory> // std::unique_ptr,std::make_unique()
#include <iostream> // std::ostream
#include <functional> // std::function
#include <algorithm> // std::remove_if

using info_t = std::unique_ptr<Car>;
using car_ptr = std::list<info_t>;
class CarPark
{
	car_ptr carList;
	std::string name;
public:
	CarPark(std::string name = "");

	std::string get_park_name() const;
	void set_park_name(std::string value);

	void add_car_by_order(info_t uptrCar);
	void add_car_to_begin(info_t uptrCar);
	void add_car_to_back(info_t uptrCar);

	void remove_car(const Car& car);
	void erase_car_if(std::function<bool(const info_t&)> lambda);

	void sort();

	

	friend std::ostream& operator<<(std::ostream& out, const CarPark& object);
};

