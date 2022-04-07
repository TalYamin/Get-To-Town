#pragma once

#include "AccessList.h"

class AccessList;
class City
{
	int id;
	AccessList* accessList;
public:
	City();
	City(int _id, AccessList* _accessList);
	~City();


private:

};


