#include <iostream>
#include "Country.h"
#include "Road.h"
#include "vector"
#include "AccessNode.h"
#include <string>
#include "utils.h"
#include "Stack.h"
#include "StaticAccessList.h"
#include "AccessList.h"
#define DELIIMITER ' '

using namespace std;
int getRoadDirectionFromInput(string& inputAllRoads, size_t pos, int cityAmout);
Road* extractNewRoad(string& inputAllRoads, size_t pos, int cityAmout);
bool isValid(int roadAmounts, int roadAmountFound, int moked, int cityAmount);
void getUserInput(int& cityAmounts, int& roadAmounts, std::string& inputAllRoads, int& moked);
void initAllRoads(size_t& pos, std::string& inputAllRoads, Road*& road, int cityAmounts, std::vector<Road*>& allRoads);
void recGetToTown(Country& country, City* moked, AccessList& accessList);
void iterateGetToTown(Country country, City* moked, AccessList& accessList);

void getToTownRec(Country country, City* moked, int citiesAmounts);
void getToTownIter(Country country, City* moked, int citiesAmounts);
void printRecResult(int moked);
void printIterResult(int moked);


int main() {
	Country country;
	vector<Road*> allRoads;
	string inputAllRoads;
	Road* road;
	int citiesAmounts, roadAmounts, moked;
	size_t pos = 0;
	getUserInput(citiesAmounts, roadAmounts, inputAllRoads, moked);
	initAllRoads(pos, inputAllRoads, road, citiesAmounts, allRoads);
	if (!isValid(roadAmounts, allRoads.size(), moked, citiesAmounts))
	{
		handleError();
	}
	country.initAllCountriesStructure(citiesAmounts);
	country.addCities(allRoads);
	getToTownRec(country, country.findCityById(moked), citiesAmounts);
	getToTownIter(country, country.findCityById(moked), citiesAmounts);
	return 0;
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

bool isValid(int roadAmounts, int roadAmountFound, int moked, int cityAmount)
{
	if (roadAmounts != roadAmountFound)
		return false;
	if (moked > cityAmount)
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

void getToTownRec(Country country, City* moked, int citiesAmounts)
{
	AccessList accessList(citiesAmounts);
	recGetToTown(country, moked, accessList);
	printRecResult(moked->getId());
	accessList.getStaticAcessList()->printStaticList(moked->getId());
}

void getToTownIter(Country country, City* moked, int citiesAmounts)
{
	AccessList accessList(citiesAmounts);
	iterateGetToTown(country, moked, accessList);
	printIterResult(moked->getId());
	accessList.getStaticAcessList()->printStaticList(moked->getId());
}

void printRecResult(int moked)
{
	cout << "Cities accessible from source city " << moked << " (recursive algorithm): ";
}

void printIterResult(int moked)
{
	cout << "Cities accessible from city source city " << moked << " (iterative algorithm): ";

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

void iterateGetToTown(Country country, City* moked, AccessList& accessList)
{
	Stack stack = Stack();
	CityNode* cityNode = country.getCities()[moked->getId() - 1]->getHead();
	Item* item = new Item(cityNode, RecLineResult::START, country);
	stack.push(item);

	while (!stack.isEmpty()) {
		Item* curItem = stack.pop()->getData();
		if (curItem->getData() != nullptr) {
			cityNode = country.getCities()[curItem->getData()->getCity()->getId() - 1]->getHead();
			if (curItem->getRecLineResult() == RecLineResult::START) {
				if (accessList.getIsWhite()[curItem->getData()->getCity()->getId() - 1] == true) {
					accessList.setIsWhite(curItem->getData()->getCity()->getId() - 1, false);
					AccessNode* node = new AccessNode(curItem->getData()->getCity(), -1);
					accessList.insertToEnd(node);
					if (!country.getCities()[moked->getId() - 1]->isEmptyCityList()) {
						Item* tmp = new Item(cityNode, RecLineResult::FIRST_AFTER, country);
						curItem->setRecLineResult(RecLineResult::START);
						stack.push(new Item(curItem->getData()->getNext(), RecLineResult::START, country));
						stack.push(tmp);
					}
				}
			}
			else if (curItem->getRecLineResult() == RecLineResult::FIRST_AFTER) {
				if (country.getCities()[cityNode->getCity()->getId() - 1]->getHead()->getNext() != nullptr) {
					Item* tmp = new Item(country.getCities()[cityNode->getCity()->getId() - 1]->getHead()->getNext(),
						RecLineResult::START, country);
					curItem->setNodeData(cityNode->getNext());
					curItem->setRecLineResult(RecLineResult::START);
					stack.push(curItem);
				}
			}
		}
	}
}
