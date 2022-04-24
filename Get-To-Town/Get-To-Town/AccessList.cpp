#include "AccessList.h"

/*Ctor of AccessList*/
AccessList::AccessList(int citiesAmount) {
	staticAccessList = new StaticAccessList(citiesAmount);
	isWhite.insert(isWhite.end(), citiesAmount, true);
}

/*getter for isWhite data member*/
vector<bool> AccessList::getIsWhite()
{
	return isWhite;
}

/*setter for isWhite data member*/
void AccessList::setIsWhite(int cityIndex, bool changeTo)
{
	isWhite[cityIndex] = changeTo;
}

/*dtor of AccessList*/
AccessList::~AccessList()
{
	delete(staticAccessList);
}

/*getter of staticAccessList data member*/
StaticAccessList* AccessList::getStaticAcessList()
{
	return staticAccessList;
}

/*Function is used to insert acesss node to end of static access list*/
void AccessList::insertToEnd(AccessNode* node)
{
	staticAccessList->insertToEnd(node, staticAccessList->foundLastIndex());
}
