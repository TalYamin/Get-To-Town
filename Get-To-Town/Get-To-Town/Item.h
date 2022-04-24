#pragma once
#include "City.h"
#include "recLineResult.h"
#include "Country.h"

class Item
{
	CityNode* nodeData;
	RecLineResult rlr;
	Country* country;

public:
	//ctors + dtors
	Item(CityNode* _nodeData, RecLineResult _rlr, Country* _country);
	~Item();

	//getters + setters
	RecLineResult getRecLineResult();
	void setRecLineResult(RecLineResult _rlr);
	CityNode* getData();
	void setNodeData(CityNode* _nodeData);

private:

};
