#include "StaticAccessList.h"
#include <iostream>

/*ctor of StaticAccessList with 1 parameter*/
StaticAccessList::StaticAccessList(int cityAmount)
{
	list.resize(cityAmount);
}

/*empty ctor of StaticAccessList*/
StaticAccessList::StaticAccessList()
{
}

/*ctor of StaticAccessList*/
StaticAccessList::StaticAccessList(vector<AccessNode*> _list, int _headList, int _headFree)
{
	list = _list;
	headFree = _headFree;
	headList = _headList;
}

/*dtor of StaticAccessList*/
StaticAccessList::~StaticAccessList()
{
	for (int i = 0;i < list.size();i++)
	{
		delete(list[i]);
	}
}

/*
Function is responsible to insert accessNode after a spsecific index which received.
*/
void StaticAccessList::insertAfter(AccessNode* node, int foundIndex)
{
	int locNew = headFree;
	if (!isEmptyCityList())
	{
		headFree = list[headFree]->getNextIndex();
		list[locNew]->setCity(node->getCity());
		list[foundIndex]->setNextIndex(locNew);
	}
	else {
		headFree = 1;
	}
	list[locNew] = node;

}

/*
Function is responsible to insert accessNode in the end of list.
*/
void StaticAccessList::insertToEnd(AccessNode* node, int foundIndex)
{
	if (!isEmptyCityList()) {
		list[foundIndex]->setNextIndex(headFree);
		list[headFree] = node;
		headFree++;
	}
	else {
		list[foundIndex] = node;
		headFree++;
	}
}

/*
Function is responibsle to found the current last index in list.
*/
int StaticAccessList::foundLastIndex()
{
	int index = 0;
	if (!isEmptyCityList())
	{
		AccessNode* node = list[headList];
		while (node->getNextIndex() != -1)
		{
			index++;
			node = list[node->getNextIndex()];
		}
	}
	return index;
}

/*
Function checks if cityList is empty. return true if it is empty.
*/
bool StaticAccessList::isEmptyCityList()
{
	bool isEmpty = false;

	if (headList == 0 && headFree == 0) {
		isEmpty = true;
	}

	return isEmpty;
}

/*
Function is used to print the static list.
*/
void StaticAccessList::printStaticList(int moked)
{
	int currIndex = headList;
	while (currIndex != -1) {
		cout << list[currIndex]->getCity()->getId() << ' ';
		currIndex = list[currIndex]->getNextIndex();
	}
	cout << endl;
}
