#include "Road.h"

Road::Road()
{
}
int Road::getSrc()
{
	return src;
}
int Road::getDest()
{
	return dest;
}
Road::Road(int _src, int _dest)
{
	src = _src;
	dest = _dest;
}

Road::~Road()
{
}
