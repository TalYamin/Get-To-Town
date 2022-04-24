#include "Stack.h"

/*empty ctor of stack*/
Stack::Stack()
{
}

/*dtor of stack*/
Stack::~Stack()
{
	makeEmpty();
}

/*
This function implements push function to stack.
Adding new itemType to stack.
*/
void Stack::push(Item* item)
{
	ItemType* newItem = new ItemType(item, nullptr);
	if (!isEmpty()) {
		newItem->setNext(top);
	}
	top = newItem;
}

/*
This function implements pop function to stack.
Removing top itemType from stack.
*/
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

/*
This function is responsible to make the stack empty.
*/
void Stack::makeEmpty()
{
	while (top != nullptr)
	{
		ItemType* saver = top->getNext();
		delete top->getData();
		delete(top);
		top = saver;
	}
}

/*Fuction check if stack is empty. return true if it is empty.*/
bool Stack::isEmpty()
{
	return top == nullptr;
}