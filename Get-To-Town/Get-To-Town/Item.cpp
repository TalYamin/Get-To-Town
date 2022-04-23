#include "Item.h"

Item::Item(CityNode* _data, RecLineResult _rlr, Country _country)
{
	nodeData = _data;
	rlr = _rlr;
	country = _country;
}

Item::~Item()
{
}

RecLineResult Item::getRecLineResult()
{
	return rlr;
}

void Item::setRecLineResult(RecLineResult _rlr)
{
	rlr = _rlr;
}


CityNode* Item::getData()
{
	return nodeData;
}

void Item::setNodeData(CityNode* _nodeData)
{
	nodeData = _nodeData;
}
