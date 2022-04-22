#pragma once

#include "AccessNode.h"
#include "vector"
#include "StaticAccessList.h"

using namespace std;

class AccessList
{
	vector<bool> isWhite;
	StaticAccessList* staticAccessList;

public:
	AccessList(int citiesAmount);
	~AccessList();
	void insertToEnd(AccessNode* node);
	vector<bool> getIsWhite();
	void setIsWhite(int cityIndex, bool changeTo);
	StaticAccessList* getStaticAcessList();
private:

};
