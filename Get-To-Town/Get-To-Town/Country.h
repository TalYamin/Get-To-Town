#pragma once

#include "City.h"

class Country
{
	City** cities = {};
	int citiesAmount;

public:
	//ctors + dtor
	Country();
	~Country();

	//getters + setters
	City** getCities();
	void addCity(City* city);
	int getCitiesAmount();
	void setCitiesAmount(int _citiesAmount);

private:

};

