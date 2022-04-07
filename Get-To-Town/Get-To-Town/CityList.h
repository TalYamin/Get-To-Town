#pragma once

#include "City.h"
#include "CityNode.h"

class City;
class CityNode;
class CityList
{
	CityNode* head = nullptr;
	CityNode* tail = nullptr;

public:
	CityList();
	~CityList();
	CityNode* getHead();
	CityNode* getTail();
	bool isEmptyCityList();
	void insertCityDataToEndList(City* city);

private:
	CityNode* createNewCityNode(City* city, CityNode* next);
	void insertCityNodeToEndList(CityNode* newTail);


};
