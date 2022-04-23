#include "Stack.h"

Stack::Stack()
{
}

Stack::~Stack()
{
	makeEmpty();
}

void Stack::push(Item* item)
{
	ItemType* newItem = new ItemType(item, nullptr);
	if (!isEmpty()) {
		newItem->setNext(top);
	}
	top = newItem;
}

ItemType* Stack::pop()
{
	ItemType* result = top;
	if (this->isEmpty()) {
		cout << "ERROR";
	}
	else
	{
		top = top->getNext();
	}
	return result;
}

void Stack::makeEmpty()
{
	while (top != nullptr)
	{
		ItemType* saver = top->getNext();
		delete(top);
		top = saver;
	}
}

bool Stack::isEmpty()
{
	return top == nullptr;
}