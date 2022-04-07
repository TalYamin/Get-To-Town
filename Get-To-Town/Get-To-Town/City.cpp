#include "City.h"

City::City()
{
}

City::City(int _id)
{
	id = _id;
}


City::~City()
{
}

int City::getId()
{
	return id;
}

bool City::getIsWhite()
{
	return isWhite;
}

void City::setIsWhite(bool _isWhite){

	isWhite = _isWhite;
}

 


