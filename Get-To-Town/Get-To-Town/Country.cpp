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
		cities[i]->getCityList()->makeEmptyCityList();
	}
}

void Country::addCities(vector<Road*> allRoads) {

	for (int i = 0; i < allRoads.size(); i++){
		City* currCity = new City(allRoads[i]->getDest());
		cities[allRoads[i]->getSrc() - 1]->getCityList()->insertCityDataToEndList(currCity);
	}

}