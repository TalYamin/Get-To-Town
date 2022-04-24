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
void iterateGetToTown(Country& country, City* moked, AccessList& accessList);
void getToTownRec(Country& country, City* moked, int citiesAmounts);
void getToTownIter(Country& country, City* moked, int citiesAmounts);
void printRecResult(int moked);
void printIterResult(int moked);
void freeAllRoads(vector<Road*> allRoads);


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
	freeAllRoads(allRoads);
	return 0;
}


/*
Function is responible to init all roads vector which contians all cities relations.
*/
void initAllRoads(size_t& pos, string& inputAllRoads, Road*& road, int cityAmounts, vector<Road*>& allRoads)
{
	while ((pos = inputAllRoads.find(DELIIMITER)) != string::npos) {
		road = extractNewRoad(inputAllRoads, pos, cityAmounts);
		allRoads.push_back(road);
	}
}

/*
Function is repsonsible to get all user input.
*/
void getUserInput(int& citiesAmounts, int& roadAmounts, std::string& inputAllRoads, int& moked)
{
	cin >> citiesAmounts;
	cin >> roadAmounts;
	cin.ignore();
	getline(cin, inputAllRoads);
	cin >> moked;
}

/*
Function is used if the data which received from user is valid.
*/
bool isValid(int roadAmounts, int roadAmountFound, int moked, int cityAmount)
{
	if (roadAmounts != roadAmountFound)
		return false;
	if (moked > cityAmount)
		return false;
	return true;
}

/*
Function creat a road according to string received from user as input by using 
string functions in order to receive all the needed data from string - source city and destination city.
*/
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

/*
Function reponsible to get the road direction, according to string received in input.
*/
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

/*
This function is wrapper function of recGetToTown.
AccessList will be printed.
*/
void getToTownRec(Country& country, City* moked, int citiesAmounts)
{
	AccessList accessList(citiesAmounts);
	recGetToTown(country, moked, accessList);
	printRecResult(moked->getId());
	accessList.getStaticAcessList()->printStaticList(moked->getId());
}

/*
This function is wrapper function of iterateGetToTown.
AccessList will be printed.
*/
void getToTownIter(Country& country, City* moked, int citiesAmounts)
{
	AccessList accessList(citiesAmounts);
	iterateGetToTown(country, moked, accessList);
	printIterResult(moked->getId());
	accessList.getStaticAcessList()->printStaticList(moked->getId());
}

/*print rec result*/
void printRecResult(int moked)
{
	cout << "Cities accessible from source city " << moked << " (recursive algorithm): ";
}

/*print iter result*/
void printIterResult(int moked)
{
	cout << "Cities accessible from city source city " << moked << " (iterative algorithm): ";

}

/*
This function implements get to town function recursively.
Function receives the moked, and initialize the accessList of this moked
in recursively way.
*/
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

/*
This function implements get to town function iteratively.
Function receives the moked, and initialize the accessList of this moked
in iteratively way.
*/
void iterateGetToTown(Country& country, City* moked, AccessList& accessList)
{
	Stack stack = Stack();
	CityNode* cityNode = country.getCities()[moked->getId() - 1]->getHead();
	Item* item = new Item(cityNode, RecLineResult::START, &country);
	stack.push(item);

	while (!stack.isEmpty()) {
		ItemType* currItemType = stack.pop();
		Item* currItem = currItemType->getData();
		free(currItemType);
		if (currItem->getData() != nullptr) {
			cityNode = country.getCities()[currItem->getData()->getCity()->getId() - 1]->getHead();
			if (currItem->getRecLineResult() == RecLineResult::START) {
				if (accessList.getIsWhite()[currItem->getData()->getCity()->getId() - 1] == true) {
					accessList.setIsWhite(currItem->getData()->getCity()->getId() - 1, false);
					AccessNode* node = new AccessNode(currItem->getData()->getCity(), -1);
					accessList.insertToEnd(node);
					if (!country.getCities()[moked->getId() - 1]->isEmptyCityList()) {
						Item* tmp = new Item(cityNode, RecLineResult::FIRST_AFTER, &country);
						currItem->setRecLineResult(RecLineResult::START);
						stack.push(new Item(currItem->getData()->getNext(), RecLineResult::START, &country));
						stack.push(tmp);
						delete currItem;
					}
				}
				else {
					delete currItem;
				}
			}
			else if (currItem->getRecLineResult() == RecLineResult::FIRST_AFTER) {
				if (country.getCities()[cityNode->getCity()->getId() - 1]->getHead()->getNext() != nullptr) {
					currItem->setNodeData(cityNode->getNext());
					currItem->setRecLineResult(RecLineResult::START);
					stack.push(currItem);
				}
				else {
					delete currItem;
				}
			}
		}
	}
}

/*Function is used to free all memory allocation of roads*/
void freeAllRoads(vector<Road*> allRoads) {

	for (int i = 0; i < allRoads.size(); i++){
		delete allRoads[i];
	}

}
