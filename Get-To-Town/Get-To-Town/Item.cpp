#include "Item.h"

/*ctor of Item*/
Item::Item(CityNode* _data, RecLineResult _rlr, Country* _country)
{
	nodeData = _data;
	rlr = _rlr;
	country = _country;
}

/*dtor of Item*/
Item::~Item()
{
}

/*getter of rlr data member*/
RecLineResult Item::getRecLineResult()
{
	return rlr;
}

/*setter of rlr data member*/
void Item::setRecLineResult(RecLineResult _rlr)
{
	rlr = _rlr;
}

/*getter of nodeData data member*/
CityNode* Item::getData()
{
	return nodeData;
}

/*setter of nodeData data member*/
void Item::setNodeData(CityNode* _nodeData)
{
	nodeData = _nodeData;
}
