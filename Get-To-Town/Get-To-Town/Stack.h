#pragma once
#include "Stack.h"
#include "ItemType.h"
#include <iostream>
#include <vector>

using namespace std;


class Stack {
	ItemType* top = nullptr;

public:
	Stack();
	~Stack();
	void push(Item* item);
	ItemType* pop();
	bool isEmpty();
	void makeEmpty();
};
