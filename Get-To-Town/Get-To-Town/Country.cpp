#include "Country.h"

/*empty ctor of coutry*/
Country::Country()
{
}

/*dtor of country*/
Country::~Country()
{

	freeAllCities();
}

/*getter of cities data member*/
vector<CityList*> Country::getCities()
{
	return cities;
}

/*
Function is used to init country with cities, according to amount received.
*/
void Country::initAllCountriesStructure(int citiesAmount) {

	for (size_t i = 0; i < citiesAmount; i++) {
		cities.push_back(new CityList());
		cities[i]->insertCityDataToEndList(new City(i + 1));
	}
}

/*
Function is used to add cities relation in country, according to roads.
To any soruce city, make a relation with destination city.
*/
void Country::addCities(vector<Road*> allRoads) {

	for (int i = 0; i < allRoads.size(); i++) {
		City* currCity = new City(allRoads[i]->getDest());
		cities[allRoads[i]->getSrc() - 1]->insertCityDataToEndList(currCity);
	}

}

/*
This function is used to find city by id.
*/
City* Country::findCityById(int id)
{
	for (size_t i = 0; i < cities.size(); i++)
	{
		if (cities[i]->getHead()->getCity()->getId() == id)
			return cities[i]->getHead()->getCity();
	};
	return nullptr;
}

/*
This function is used to free all memory allocation of cities.
*/
void Country::freeAllCities()
{

	for (int i = 0; i < cities.size(); i++) {
		delete cities[i];
	}
}

