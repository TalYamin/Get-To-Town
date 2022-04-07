#pragma once

#include "CityList.h"

class CityList;
class CityNode;

class City
{
	int id;
	CityList* cityList;
public:

	//ctors + dtors
	City();
	City(int _id);
	City(int _id, CityList* _cityList);
	~City();

	//getters + setters
	int getId();
	CityList* getCityList();

private:

};


