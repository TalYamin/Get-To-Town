#pragma once
#include "ItemType.h"
#include "Item.h"

class ItemType
{
	Item* nodeData;
	ItemType* next;
public:

	//ctors + dtors
	ItemType();
	ItemType(Item* nodeData, ItemType* next);
	~ItemType();

	//getters + setters
	Item* getData();
	ItemType* getNext();
	void setNext(ItemType* _next);

private:

};
