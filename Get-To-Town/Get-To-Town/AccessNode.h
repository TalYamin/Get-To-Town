#pragma once

#include "City.h"

class AccessNode
{
	City* data;
	int next ; //index
public:
	AccessNode();
	AccessNode(City* _city, int _next);
	~AccessNode();
	int getNextIndex();
	void setNextIndex(int _next);
	City* getData();
	void setData(City* node);

private:

};