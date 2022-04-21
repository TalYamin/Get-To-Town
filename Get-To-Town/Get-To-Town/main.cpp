#include <iostream>
#include "Country.h"
#include "Road.h"
#include "vector"
#include "AccessNode.h"
#include "AccessList.h"
#include <string>
#include "utils.h"
#define DELIIMITER ' '

using namespace std;
int getRoadDirectionFromInput(string& inputAllRoads, size_t pos, int cityAmout);
Road* createNewRoad(string& inputAllRoads, size_t pos, int cityAmout);
bool isValid(int roadAmounts, int roadAmountFound);
void getUserInput(int& cityAmounts, Country& country, int& roadAmounts, std::string& inputAllRoads, int& moked);
void getToTown(Country* country, City* moked, AccessList* accessList);

int main() {
	Country country;
	vector<Road*> allRoads;
	string inputAllRoads;
	Road* road;
	int cityAmounts;
	int roadAmounts;
	int moked;
	size_t pos = 0;
	getUserInput(cityAmounts, country, roadAmounts, inputAllRoads, moked);
	while ((pos = inputAllRoads.find(DELIIMITER)) != string::npos) {
		road = createNewRoad(inputAllRoads, pos, cityAmounts);
		allRoads.push_back(road);
	}
	if (!isValid(roadAmounts, allRoads.size()))
	{
		handleError();
	}
	country.initAllCountries();
	country.addCities(allRoads);
	AccessList accessList(cityAmounts);
	getToTown(&country, country.findCityById(moked), &accessList);
}

void getUserInput(int& cityAmounts, Country& country, int& roadAmounts, std::string& inputAllRoads, int& moked)
{
	cin >> cityAmounts;
	country.setCitiesAmount(cityAmounts);
	cin >> roadAmounts;
	cin.ignore();
	getline(cin, inputAllRoads);
	cin >> moked;
}

bool isValid(int roadAmounts, int roadAmountFound)
{
	if (roadAmounts != roadAmountFound)
		return false;
	return true;
}

Road* createNewRoad(string& inputAllRoads, size_t pos, int cityAmout)
{
	int src = getRoadDirectionFromInput(inputAllRoads, pos, cityAmout);
	pos = inputAllRoads.find(DELIIMITER);
	if (pos == string::npos && inputAllRoads.length() != 1)
	{
		handleError();
	}
	int dest = getRoadDirectionFromInput(inputAllRoads, pos, cityAmout);
	return new Road(src, dest);
}

int getRoadDirectionFromInput(string& inputAllRoads, size_t pos, int cityAmout)
{
	string token = inputAllRoads.substr(0, pos);
	while (token.length() == 0) {
		token = inputAllRoads.erase(0, pos + 1);//size of ' '
	}
	pos = inputAllRoads.find(DELIIMITER);
	inputAllRoads.erase(0, pos + 1);//size of ' '
	int num = stoi(token);
	if (num > cityAmout + 1)
	{
		handleError();
	}


	return num;
}


void getToTown(Country* country, City* moked, AccessList* accessList) {

	moked->setIsWhite(false);
	AccessNode* currAccessNode = new AccessNode(moked, -1);
	accessList->insertAfter(currAccessNode);
	for (int i = 0; i < country->getCities().size(); i++)
	{
		CityList* cityList = country->getCities()[i];
		if (cityList->getHead()->getCity()->getId()==moked->getId()){
			CityNode* curr = cityList->getHead();
			while (curr != nullptr) {
				if (curr->getCity()->getIsWhite()) {
					getToTown(country, curr->getCity(), accessList);
				}
				curr = curr->getNext();
			}
		}
	}
}