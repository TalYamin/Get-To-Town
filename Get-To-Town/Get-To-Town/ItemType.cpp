#include "ItemType.h"

ItemType::ItemType()
{
}

ItemType::ItemType(Item* _nodeData, ItemType* _next)
{
	nodeData = _nodeData;
	next = _next;
}

ItemType::~ItemType()
{
}

Item* ItemType::getData()
{
	return nodeData;
}

ItemType* ItemType::getNext()
{
	return next;
}

void ItemType::setNext(ItemType* _next)
{
	next = _next;
}


