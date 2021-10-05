#pragma once

#include <string>
#include "anItem.h"
using namespace std;
const int MAX_ITEMS = 20;
const int NOT_FOUND = -1;
//#define MAX_ITEMS 20 

class anItemList {
public:
	anItemList();
	void addItem(anItem item);
	void addItem(string name, string description, bool canTake);
	anItem getItem(int index);
	anItem removeItem(int index);
	int findItem(string name);
	int getNumItems();
	void print();
	void displayItems();
private:
	int numItems;
	anItem objectS[MAX_ITEMS];

};
