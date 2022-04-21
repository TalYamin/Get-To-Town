#pragma once
#include "ItemType.h"
#include <iostream>
#include <vector>

using namespace std;


class Stack {
	int top;

public:
	vector<ItemType> items; // Maximum size of Stack

	Stack();
	void push(ItemType item);
	ItemType pop();
	bool isEmpty();
	void makeEmpty();
};
