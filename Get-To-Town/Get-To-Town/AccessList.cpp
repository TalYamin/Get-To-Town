#include "AccessList.h"
#include "StaticAccessList.h"

AccessList::AccessList(int citiesAmount) {
	staticAccessList = new StaticAccessList(citiesAmount);
	isWhite.insert(isWhite.end(), citiesAmount, true);
}

vector<bool> AccessList::getIsWhite()
{
	return isWhite;
}

void AccessList::setIsWhite(int cityIndex, bool changeTo)
{
	isWhite[cityIndex] = changeTo;
}

AccessList::~AccessList()
{
}

StaticAccessList* AccessList::getStaticAcessList()
{
	return staticAccessList;
}

void AccessList::insertToEnd(AccessNode* node)
{
	staticAccessList->insertToEnd(node, staticAccessList->foundLastIndex());
}
