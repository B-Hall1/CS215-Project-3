#pragma once

#include <string>
//#include "anItem.h"
#include "anItemList.h"
#include "anExitList.h"
using namespace std;

//const int aRoom_NOT_FOUND = -1;

class aRoom {
public:
	aRoom();
	void setShortDescription(string rest);
	void getShortDescription();
	void setLongDescription(string aline);
	void getLongDescription();
	void addExit( string direction, int toRoom);
	int findExit(string direction);
	void addItem(string name, string direction, bool canTake);
	int findItem(string name);
	anItem removeItem(int index);
	void displayItems();
	void displayExits();
	void enter();
	void look();
	void examine(string name, anItemList playerInventory);
	void take(string name, anItemList playerInventory);
	void drop(string name, anItemList playerInventory);
	void print();
private:
	string shortDescription;
	string longDescription;
	anItemList itemList;
	anExitList exitList;

};
