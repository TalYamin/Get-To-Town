#include "CityList.h"

CityList::CityList()
{

}

CityList::~CityList()
{
}

CityNode* CityList::getHead()
{
	return head;
}

CityNode* CityList::getTail()
{
	return tail;
}

bool CityList::isEmptyCityList()
{
	bool isEmpty = false;

	if (head == nullptr) {
		isEmpty = true;
	}

	return isEmpty;
}

CityNode* CityList::createNewCityNode(City* city, CityNode* next) {

	return new CityNode(city, next);
}

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

void CityList::insertCityDataToEndList(City* city)
{
	CityNode* newTail;
	newTail = createNewCityNode(city,nullptr);
	insertCityNodeToEndList(newTail);

}



