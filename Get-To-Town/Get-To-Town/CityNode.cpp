#include "CityNode.h"

CityNode::CityNode()
{
}

CityNode::CityNode(City* _city, CityNode* _next)
{
	city = _city;
	next = _next;
}

CityNode::~CityNode()
{
}

void CityNode::setNext(CityNode* _next)
{
	next = _next;
}

City* CityNode::getCity()
{
	return city;
}

CityNode* CityNode::getNext()
{
	return next;
}
