#pragma once
#include "ItemType.h"
#include "Item.h"

class ItemType
{
	Item* nodeData;
	ItemType* next;
public:
	ItemType();
	ItemType(Item* nodeData, ItemType* next);
	~ItemType();
	Item* getData();
	ItemType* getNext();
	void setNext(ItemType* _next);

private:

};
