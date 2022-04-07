#pragma once

class Road
{
	int src;
	int dest;
public:

	//ctors + dtors
	Road();
	Road(int _src, int _dest);
	~Road();

	//getters + setters
	int getSrc();
	int getDest();

private:

};


