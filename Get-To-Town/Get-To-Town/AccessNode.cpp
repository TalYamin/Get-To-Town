#include "AccessNode.h"

AccessNode::AccessNode()
{
}

AccessNode::AccessNode(City* _city, int _next)
{
	data = _city;
	next = _next;
}

AccessNode::~AccessNode()
{
}

int AccessNode::getNextIndex()
{
	return next;
}

City* AccessNode::getData()
{
	return data;
}

void AccessNode::setData(City* _city)
{
	data = _city;
}

void AccessNode::setNextIndex(int _next)
{
	next = _next;
}
