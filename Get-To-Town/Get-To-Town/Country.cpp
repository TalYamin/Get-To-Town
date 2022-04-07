#include "Country.h"

Country::Country()
{
}

Country::~Country()
{
}

City** Country::getCities()
{
	return nullptr;
}


int Country::getCitiesAmount()
{
	return 0;
}

void Country::setCitiesAmount(int _citiesAmount)
{
}

void Country::initCountry() {

	for (int i = 0; i < citiesAmount; i++){
		cities[i] = new City(i + 1);

	}
}

void Country::addCities(vector<Road*> allRoads) {

	//for (int i = 0; i < allRoads.size(); i++){
	//	cities[allRoads[i]->getSrc()-1]
	//}

}