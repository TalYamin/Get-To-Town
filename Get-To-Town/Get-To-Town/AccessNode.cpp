#include "AccessNode.h"

/*Empty ctor of AccessNode*/
AccessNode::AccessNode()
{
}

/*ctor of AccessNode*/
AccessNode::AccessNode(City* _city, int _next)
{
	city = _city;
	next = _next;
}

/*dtor of AccessNode*/
AccessNode::~AccessNode()
{
}

/*getter of next data member*/
int AccessNode::getNextIndex()
{
	return next;
}

/*getter of city data member*/
City* AccessNode::getCity()
{
	return city;
}

/*setter of city data member*/
void AccessNode::setCity(City* _city)
{
	city = _city;
}

/*setter of next data member*/
void AccessNode::setNextIndex(int _next)
{
	next = _next;
}
