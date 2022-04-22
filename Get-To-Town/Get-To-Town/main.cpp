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
Road* extractNewRoad(string& inputAllRoads, size_t pos, int cityAmout);
bool isValid(int roadAmounts, int roadAmountFound);
void getUserInput(int& cityAmounts, int& roadAmounts, std::string& inputAllRoads, int& moked);
void initAllRoads(size_t& pos, std::string& inputAllRoads, Road*& road, int cityAmounts, std::vector<Road*>& allRoads);
void getToTown(Country& country, City* moked, AccessList& accessList);
void recGetToTown(Country& country, City* moked, AccessList& accessList);
void iterateGetToTown(Country country, City* moked, AccessList accessList);

int main() {
	Country country;
	vector<Road*> allRoads;
	string inputAllRoads;
	Road* road;
	int citiesAmounts, roadAmounts, moked;
	size_t pos = 0;
	getUserInput(citiesAmounts, roadAmounts, inputAllRoads, moked);
	initAllRoads(pos, inputAllRoads, road, citiesAmounts, allRoads);
	if (!isValid(roadAmounts, allRoads.size()))
	{
		handleError();
	}
	country.initAllCountriesStructure(citiesAmounts);
	country.addCities(allRoads);
	AccessList accessList(citiesAmounts);
	getToTown(country, country.findCityById(moked), accessList);
}

void initAllRoads(size_t& pos, string& inputAllRoads, Road*& road, int cityAmounts, vector<Road*>& allRoads)
{
	while ((pos = inputAllRoads.find(DELIIMITER)) != string::npos) {
		road = extractNewRoad(inputAllRoads, pos, cityAmounts);
		allRoads.push_back(road);
	}
}

void getUserInput(int& citiesAmounts, int& roadAmounts, std::string& inputAllRoads, int& moked)
{
	cin >> citiesAmounts;
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

Road* extractNewRoad(string& inputAllRoads, size_t pos, int cityAmout)
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
		token = inputAllRoads.erase(0, pos + 1);//include size of ' '
	}
	pos = inputAllRoads.find(DELIIMITER);
	inputAllRoads.erase(0, pos + 1);//inclue size of ' '
	int num = stoi(token);
	if (num > cityAmout + 1)
	{
		handleError();
	}
	return num;
}


void getToTown(Country& country, City* moked, AccessList& accessList) {
	recGetToTown(country, moked, accessList);
	accessList.getStaticAcessList()->print(moked->getId());
	iterateGetToTown(country, moked, accessList);
}

void recGetToTown(Country& country, City* moked, AccessList& accessList)
{
	if (accessList.getIsWhite()[moked->getId() - 1] == false) {
		return;
	}
	accessList.setIsWhite(moked->getId() - 1, false);
	AccessNode* currAccessNode = new AccessNode(moked, -1);
	accessList.insertToEnd(currAccessNode);
	CityNode* curr = country.getCities()[moked->getId() - 1]->getHead();
	while (curr->getNext() != nullptr) {
		recGetToTown(country, curr->getNext()->getCity(), accessList);
		curr = curr->getNext();

	}
}

void iterateGetToTown(Country country, City* moked, AccessList accessList)
{
	return;
}
