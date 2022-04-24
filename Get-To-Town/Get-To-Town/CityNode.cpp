#include "CityNode.h"

/*empty ctor of CityNode*/
CityNode::CityNode()
{
}

/*ctor of CityNode*/
CityNode::CityNode(City* _city, CityNode* _next)
{
	city = _city;
	next = _next;
}

/*dtor of CityNode*/
CityNode::~CityNode()
{
}

/*setter of next data member*/
void CityNode::setNext(CityNode* _next)
{
	next = _next;
}

/*getter of city data member*/
City* CityNode::getCity()
{
	return city;
}

/*getter of next data member*/
CityNode* CityNode::getNext()
{
	return next;
}
