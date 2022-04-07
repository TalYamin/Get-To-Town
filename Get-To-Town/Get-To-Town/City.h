#pragma once

#include "CityList.h"

class CityList;
class CityNode;

class City
{
	int id;
	bool isWhite = true;
public:

	//ctors + dtors
	City();
	City(int _id);
	City(int _id, CityList* _cityList);
	~City();

	//getters + setters
	int getId();
	bool getIsWhite();
	void setIsWhite(bool _isWhite);

private:

};


