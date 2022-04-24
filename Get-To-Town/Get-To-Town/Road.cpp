#include "Road.h"

/*empty ctor of road*/
Road::Road()
{
}
/*getter of source data member*/
int Road::getSrc()
{
	return src;
}

/*getter of destination data member*/
int Road::getDest()
{
	return dest;
}

/*ctor of road*/
Road::Road(int _src, int _dest)
{
	src = _src;
	dest = _dest;
}

/*dtor of road*/
Road::~Road()
{
}
