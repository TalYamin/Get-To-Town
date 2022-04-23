#include "StaticAccessList.h"
#include <iostream>


StaticAccessList::StaticAccessList(int cityAmount)
{
	list.resize(cityAmount);
}

StaticAccessList::StaticAccessList()
{
}

StaticAccessList::StaticAccessList(vector<AccessNode*> _list, int _headList, int _headFree)
{
	list = _list;
	headFree = _headFree;
	headList = _headList;
}

StaticAccessList::~StaticAccessList()
{
}

void StaticAccessList::insertAfter(AccessNode* node, int foundIndex)
{
	int locNew = headFree;
	if (!isEmptyCityList())
	{
		headFree = list[headFree]->getNextIndex();
		list[locNew]->setData(node->getData());
		list[foundIndex]->setNextIndex(locNew);
	}
	else {
		headFree = 1;
	}
	list[locNew] = node;

}

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

bool StaticAccessList::isEmptyCityList()
{
	bool isEmpty = false;

	if (headList == 0 && headFree == 0) {
		isEmpty = true;
	}

	return isEmpty;
}

void StaticAccessList::print(int moked)
{
	cout << "Cities accessible from source city " << moked << " (recursive algorithm): ";
	int currIndex = headList;
	while (currIndex != -1) {
		cout << list[currIndex]->getData()->getId() << ' ';
		currIndex = list[currIndex]->getNextIndex();
	}
	cout << endl;
}
