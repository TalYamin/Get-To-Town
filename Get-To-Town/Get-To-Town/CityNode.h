#pragma once
#include "City.h"


class City;

class CityNode
{

	City* city;
	CityNode* next;
public:

	//ctors + dtors
	CityNode();
	CityNode(City* _city, CityNode* _next);
	~CityNode();

	//getters + setters
	void setNext(CityNode* _next);
	City* getCity();
	CityNode* getNext();

private:


};
