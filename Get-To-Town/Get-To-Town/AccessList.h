#pragma once

#include "AccessNode.h"

class AccessNode;
class AccessList
{

	AccessNode* list;
	int headList;
	int headFree;

public:
	AccessList();
	AccessList(AccessNode* _list, int _headList, int _headFree);
	~AccessList();

private:

};
