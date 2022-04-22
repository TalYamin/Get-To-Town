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
	StaticAccessList(int cityAmount);
	StaticAccessList();
	StaticAccessList(vector<AccessNode*> _list, int _headList, int _headFree);
	~StaticAccessList();
	void insertAfter(AccessNode* node, int foundIndex);
	void insertToEnd(AccessNode* node, int foundIndex);
	int foundLastIndex();
	bool isEmptyCityList();
	void print(int moked);
private:

};
