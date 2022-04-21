#pragma once

#include "StaticList.h"
#include "AccessNode.h"
#include "vector"

using namespace std;

class StaticList
{
	vector<AccessNode*> list;
	int headList = 0;
	int headFree = 0;

public:
	StaticList(int cityAmount);
	StaticList();
	StaticList(vector<AccessNode*> _list, int _headList, int _headFree);
	~StaticList();
	void insertAfter(AccessNode* node, int foundIndex);
	int foundLastIndex();
	bool isEmptyCityList();
private:

};
