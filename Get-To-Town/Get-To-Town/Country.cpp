#include "Country.h"

Country::Country()
{
}

Country::~Country()
{
}


vector<CityList*> Country::getCities()
{
	return cities;
}


void Country::initAllCountriesStructure(int citiesAmount) {

	for (size_t i = 0; i < citiesAmount; i++) {
		cities.push_back(new CityList());
		cities[i]->insertCityDataToEndList(new City(i + 1));
	}
}

void Country::addCities(vector<Road*> allRoads) {

	for (int i = 0; i < allRoads.size(); i++) {
		City* currCity = new City(allRoads[i]->getDest());
		cities[allRoads[i]->getSrc() - 1]->insertCityDataToEndList(currCity);
	}

}

City* Country::findCityById(int id)
{
	for (size_t i = 0; i < cities.size(); i++)
	{
		if (cities[i]->getHead()->getCity()->getId() == id)
			return cities[i]->getHead()->getCity();
	};
	return nullptr;
}

