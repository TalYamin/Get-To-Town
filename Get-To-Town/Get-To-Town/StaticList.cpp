#include "StaticList.h"

StaticList::StaticList()
{
}

StaticList::StaticList(int cityAmount)
{
	list.reserve(cityAmount);
}

StaticList::StaticList(vector<AccessNode*> _list, int _headList, int _headFree)
{
	list = _list;
	headFree = _headFree;
	headList = _headList;
}

StaticList::~StaticList()
{
}

void StaticList::insertAfter(AccessNode* node, int foundIndex)
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

int StaticList::foundLastIndex()
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

bool StaticList::isEmptyCityList()
{
	bool isEmpty = false;

	if (headList == 0 && headFree == 0) {
		isEmpty = true;
	}

	return isEmpty;
}