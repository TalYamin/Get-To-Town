#pragma once

#include "AccessNode.h"
#include "vector"

using namespace std;

class AccessNode;
class AccessList
{

	vector<AccessNode*> list;
	int headList = 0;
	int headFree = 0;

public:
	AccessList();
	AccessList(AccessNode* _list, int _headList, int _headFree);
	~AccessList();
	void insertAfter(AccessNode* node, int foundIndex);
	int foundLastIndex();
	bool isEmptyCityList();
private:

};
