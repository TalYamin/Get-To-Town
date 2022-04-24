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

	//ctors + dtors
	CityList();
	~CityList();

	//getters + setters
	CityNode* getHead();
	CityNode* getTail();

	//public methods
	bool isEmptyCityList();
	void insertCityDataToEndList(City* city);

private:
	//private methods
	CityNode* createNewCityNode(City* city, CityNode* next);
	void insertCityNodeToEndList(CityNode* newTail);
	void freeAllCityNodes();
};
