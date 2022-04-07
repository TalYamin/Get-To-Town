#include "CityList.h"

CityList::CityList()
{
}

CityList::~CityList()
{
}

void CityList::makeEmptyCityList(CityList* cityList){
	
	cityList->head = cityList->tail = nullptr;
}

bool CityList::isEmptyCityList(CityList* cityList)
{
	bool isEmpty = false;

	if (cityList->head == nullptr) {
		isEmpty = true;
	}

	return isEmpty;
}

CityNode* CityList::createNewCityNode(City* city, CityNode* next) {

	return new CityNode(city, next);
}

void CityList::insertCityNodeToEndList(CityList* cityList, CityNode* tail) {

	if (isEmptyCityList(cityList)) {
		cityList->head = cityList->tail = tail;
	}

	else {
		cityList->tail->setNext(tail);
		cityList->tail = tail;
	}

	tail->setNext(nullptr);

}

void CityList::insertCityDataToEndList(CityList* cityList, City* city)
{
	CityNode* newTail;
	newTail = createNewCityNode(city,nullptr);
	insertCityNodeToEndList(cityList, newTail);

}



