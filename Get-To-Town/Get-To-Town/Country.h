#pragma once

#include "vector"
#include "City.h"
#include "Road.h"

using namespace std;


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
	int getCitiesAmount();
	void setCitiesAmount(int _citiesAmount);
	void initCountry();
	void addCities(vector<Road*> allRoads);

private:
	void addCity(City* city);
};

