#pragma once
//--------------------------------------------------------
//                    class anExitList
//--------------------------------------------------------
// Implements a partial array of anExit objects
//--------------------------------------------------------
#include <string>
#include "anExit.h"
using namespace std;

// constants pertaining to an itemList
const int MAX_EXITS = 20;
const int EXIT_NOT_FOUND = -1;

class anExitList {
public:
	anExitList();
	void addExit(anExit newExit);
	void addExit(string dir, int to_room);
	anExit getExit(int ndx);
	int  findExit(string srchName);
	int  getNumExits();
	void displayExits();
	void print();
private:
	anExit exit[MAX_EXITS];
	int numExits;
};