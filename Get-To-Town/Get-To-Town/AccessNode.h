#pragma once

#include "City.h"

class AccessNode
{
	City* city;
	int next ; //index
public:

	//ctors + dtors
	AccessNode();
	AccessNode(City* _city, int _next);
	~AccessNode();

	//getters + setters
	int getNextIndex();
	void setNextIndex(int _next);
	City* getCity();
	void setCity(City* node);

private:

};