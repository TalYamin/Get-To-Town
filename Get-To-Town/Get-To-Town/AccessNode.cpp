#include "AccessNode.h"

AccessNode::AccessNode()
{
}

AccessNode::AccessNode(City* _city, int _next)
{
	city = _city;
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
	return city;
}

void AccessNode::setData(City* _city)
{
	city = _city;
}

void AccessNode::setNextIndex(int _next)
{
	next = _next;
}
