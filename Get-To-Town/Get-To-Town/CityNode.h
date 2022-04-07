#pragma once
#include "City.h"


class City;

class CityNode
{

	City* city;
	CityNode* next;
public:
	CityNode();
	CityNode(City* _city, CityNode* _next);
	~CityNode();
	void setNext(CityNode* _next);
	City* getCity();
	CityNode* getNext();

private:


};
