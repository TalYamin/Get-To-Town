#pragma once

#include "vector"
#include "City.h"
#include "Road.h"
#include "AccessList.h"

using namespace std;


class Country
{
	vector<CityList*> cities;

public:
	//ctors + dtor
	Country();
	~Country();

	//getters + setters
	vector<CityList*> getCities();

	//public methods
	void initAllCountriesStructure(int citiesAmount);
	void addCities(vector<Road*> allRoads);
	City* findCityById(int id);

private:

	//private methods
	void addCity(City* city);
	void freeAllCities();
};

