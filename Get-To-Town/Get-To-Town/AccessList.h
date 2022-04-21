#pragma once

#include "AccessNode.h"
#include "StaticList.h"
#include "vector"

using namespace std;

class AccessList
{
	vector<bool> isWhite;
	StaticList* accessList;

public:
	AccessList(int citiesAmount);
	~AccessList();
	void insertAfter(AccessNode* node);
private:

};
