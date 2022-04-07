#include <iostream>
#include "Country.h"
#include "Road.h"
#include "vector"
#include <string>
#define DELIIMITER ' '

using namespace std;

int main() {
	Country country;
	vector<Road*> allRoads;
	string inputAllRoads;
	Road* road;
	int cityAmounts;
	int roadAmounts;
	int src;
	int dest;
	size_t pos = 0;
	string token;
	cin >> cityAmounts;
	country.setCitiesAmount(cityAmounts);
	cin >> roadAmounts;
	getline(cin, inputAllRoads);
	while ((pos = inputAllRoads.find(DELIIMITER)) != string::npos) {
		token = inputAllRoads.substr(0, pos);
		while (token[0] == ' ') {
			inputAllRoads.erase(0, pos + 1);//size of ' '
		}
		src = stoi(token);
		inputAllRoads.erase(0, pos + 1);//size of ' '
		pos = inputAllRoads.find(DELIIMITER);
		token = inputAllRoads.substr(0, pos);
		while (token[0] == ' ') {
			inputAllRoads.erase(0, 1);//size of ' '
		}
		dest = stoi(token);
		road = new Road(src, dest);
		allRoads.push_back(road);
		inputAllRoads.erase(0, pos + 1);//size of ' '
	}
}