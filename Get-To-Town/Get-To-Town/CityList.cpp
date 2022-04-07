#include "CityList.h"

CityList::CityList()
{
}

CityList::~CityList()
{
}

void CityList::makeEmptyCityList(){
	
	this->head = this->tail = nullptr;
}

bool CityList::isEmptyCityList()
{
	bool isEmpty = false;

	if (this->head == nullptr) {
		isEmpty = true;
	}

	return isEmpty;
}

CityNode* CityList::createNewCityNode(City* city, CityNode* next) {

	return new CityNode(city, next);
}

void CityList::insertCityNodeToEndList(CityNode* tail) {

	if (isEmptyCityList()) {
		this->head = this->tail = tail;
	}

	else {
		this->tail->setNext(tail);
		this->tail = tail;
	}

	tail->setNext(nullptr);

}

void CityList::insertCityDataToEndList(City* city)
{
	CityNode* newTail;
	newTail = createNewCityNode(city,nullptr);
	insertCityNodeToEndList(newTail);

}



