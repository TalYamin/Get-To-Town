#include "ItemType.h"

/*empty ctor of ItemType*/
ItemType::ItemType()
{
}

/*ctor of ItemType*/
ItemType::ItemType(Item* _nodeData, ItemType* _next)
{
	nodeData = _nodeData;
	next = _next;
}

/*dtor of ItemType*/
ItemType::~ItemType()
{
}

/*getter of nodeData data member*/
Item* ItemType::getData()
{
	return nodeData;
}

/*getter of next data member*/
ItemType* ItemType::getNext()
{
	return next;
}

/*setter of next data member*/
void ItemType::setNext(ItemType* _next)
{
	next = _next;
}


