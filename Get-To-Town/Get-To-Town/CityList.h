#pragma once

#include "CityNode.h"


class CityList
{
	CityNode* head;
	CityNode* tail;

public:
	CityList();
	~CityList();
	void makeEmptyCityList(CityList* cityList);
	bool isEmptyCityList(CityList* cityList);
	CityNode* createNewCityNode(City* city, CityNode* next);
	void insertCityNodeToEndList(CityList* cityList, CityNode* tail);
	void insertCityDataToEndList(CityList* cityList, City* city);
private:


};
