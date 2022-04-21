#include "AccessList.h"
#include "StaticList.h"

AccessList:: AccessList(int citiesAmount) {
	accessList = new StaticList(citiesAmount);
	isWhite.insert(isWhite.end(), citiesAmount, true);
}

AccessList::~AccessList()
{
	delete[] accessList;
}

void AccessList::insertAfter(AccessNode* node)
{
	accessList->insertAfter(node, accessList->foundLastIndex());
}
