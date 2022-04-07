#include "AccessList.h"

AccessList::AccessList()
{
}

AccessList::AccessList(AccessNode* _list, int _headList, int _headFree)
{
}

AccessList::~AccessList()
{
}

void AccessList::insertAfter(AccessNode* node, int foundIndex)
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
	list.push_back(node);

}

int AccessList::foundLastIndex()
{
	int prev = 0;
	if (!isEmptyCityList())
	{
		AccessNode* node = list[headList];
		while (node->getNextIndex() != -1)
		{
			prev = node->getNextIndex();
			node = list[node->getNextIndex()];
		}
		return node->getNextIndex();
	}
	return prev;
}

bool AccessList::isEmptyCityList()
{
	bool isEmpty = false;

	if (headList == 0 && headFree == 0) {
		isEmpty = true;
	}

	return isEmpty;
}