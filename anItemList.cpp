#include <iostream>
#include "anItemList.h"

anItemList::anItemList() {
	numItems = 0;
}

void anItemList::addItem(anItem item) {
	if (numItems < MAX_ITEMS) {
		numItems++;
		objectS[numItems-1] = item;
	}
	else if (numItems >= MAX_ITEMS) {
		cout << "Array Full!" << endl;
	}
}

void anItemList::addItem(string name, string description, bool canTake) {
	anItem item; 
	item.setName(name);
	item.setDescription(description);
	item.setCanTake(canTake);
	addItem(item);
}

anItem anItemList::getItem(int index) {
	if (index > 0 && index <= MAX_ITEMS) {
		return objectS[index-1];
	}
	else {
		cout << "Error, index out of range." << endl;
		anItem item;
		return item;
	}
}

anItem anItemList::removeItem(int index) {
	if (index > 0 && index <= MAX_ITEMS) {
		anItem y = objectS[index-1];
		anItem item;
		objectS[index-1] = item;
		return y;
		
	}
	else {
		cout << "Error, index out of range." << endl;
		anItem item;
		return item;
	}
}

int anItemList::findItem(string name) {
	for (int i = 0; i < numItems; i++) {

		if (name.compare(objectS[i].getName()) == 0) {
			return i;
		}
	}
	return NOT_FOUND;
}

int anItemList::getNumItems() {
	return numItems;
}
void anItemList::print() {
	cout << "ITEMLIST: numItems " << numItems << endl;
	for (int i = 0; i < getNumItems(); i++) {
		getItem(i).print();

	}
}

void anItemList::displayItems() {
	string messPrefix = "You notice the following: ";
	string noItemsMess = "You are holding: ";
	if (numItems > 0) {

		cout << messPrefix;
		int i;
		for (i = 0; i < numItems-1 && numItems -1 >= 0; i++) {
			cout << objectS[i].getName() << ", ";
		}
		cout << objectS[i].getName();
		cout << "." << endl;
	}
	else if (numItems == 0 && noItemsMess.compare("") != 0) {
		cout << noItemsMess;
	}
	else  { 
		
	}
}