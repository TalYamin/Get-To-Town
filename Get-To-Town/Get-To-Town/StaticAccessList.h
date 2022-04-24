#pragma once

#include "AccessNode.h"
#include "vector"

using namespace std;

class StaticAccessList
{
	vector<AccessNode*> list;
	int headList = 0;
	int headFree = 0;

public:
	//ctors + dtors
	StaticAccessList(int cityAmount);
	StaticAccessList();
	StaticAccessList(vector<AccessNode*> _list, int _headList, int _headFree);
	~StaticAccessList();

	//public methods
	void insertAfter(AccessNode* node, int foundIndex);
	void insertToEnd(AccessNode* node, int foundIndex);
	int foundLastIndex();
	bool isEmptyCityList();
	void printStaticList(int moked);

private:

};
