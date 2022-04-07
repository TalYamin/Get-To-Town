#pragma once

#include "City.h"
#include "CityNode.h"

class City;
class CityNode;
class CityList
{
	CityNode* head;
	CityNode* tail;

public:
	CityList();
	~CityList();
	void makeEmptyCityList();
	bool isEmptyCityList();
	void insertCityDataToEndList(City* city);

private:
	CityNode* createNewCityNode(City* city, CityNode* next);
	void insertCityNodeToEndList(CityNode* tail);


};
