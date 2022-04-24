#include "CityList.h"

/*empty ctor of CityList*/
CityList::CityList()
{

}

/*dtor of CityList*/
CityList::~CityList(){
	
	freeAllCityNodes();
}

/*getter of head data member*/
CityNode* CityList::getHead()
{
	return head;
}

/*getter of tail data member*/
CityNode* CityList::getTail()
{
	return tail;
}

/*
Function is used to check if cityList is empty. 
return true in case it is empty.
*/
bool CityList::isEmptyCityList()
{
	bool isEmpty = false;

	if (head == nullptr) {
		isEmpty = true;
	}

	return isEmpty;
}

/*
This function is used to create new city node.
*/
CityNode* CityList::createNewCityNode(City* city, CityNode* next) {

	return new CityNode(city, next);
}

/*
This function is used to insert city node to end of city list.
*/
void CityList::insertCityNodeToEndList(CityNode* newTail) {

	if (isEmptyCityList()) {
		head = tail = newTail;
	}

	else {
		tail->setNext(newTail);
		tail = newTail;
	}

	newTail->setNext(nullptr);
}

/*
This function is used to free all city nodes.
*/
void CityList::freeAllCityNodes(){

	CityNode* currCityNode = head;
	CityNode* tmpCityNode;
	while (currCityNode != nullptr) {
		tmpCityNode = currCityNode;
		currCityNode = currCityNode->getNext();
		delete tmpCityNode->getCity();
		delete tmpCityNode;
	}
}

/*
This function is used to insert data to end list.
*/
void CityList::insertCityDataToEndList(City* city)
{
	CityNode* newTail;
	newTail = createNewCityNode(city,nullptr);
	insertCityNodeToEndList(newTail);

}



