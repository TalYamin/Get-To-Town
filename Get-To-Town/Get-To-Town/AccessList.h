#pragma once

#include "AccessNode.h"
#include "vector"
#include "StaticAccessList.h"


using namespace std;

class StaticAcessList;
class AccessList
{
	vector<bool> isWhite;
	StaticAccessList* staticAccessList;

public:
	//ctors + dtors
	AccessList(int citiesAmount);
	~AccessList();

	//getters + setters
	void insertToEnd(AccessNode* node);
	vector<bool> getIsWhite();
	void setIsWhite(int cityIndex, bool changeTo);
	StaticAccessList* getStaticAcessList();
private:

};
