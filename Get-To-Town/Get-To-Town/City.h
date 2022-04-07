#pragma once

#include "AccessList.h"

class AccessList;
class City
{
	int id;
	AccessList* accessList;
public:

	//ctors + dtors
	City();
	City(int _id);
	City(int _id, AccessList* _accessList);
	~City();

	//getters + setters
	int getId();
	AccessList* getAccessList();
	void makeEmptyAccessList();

private:

};


