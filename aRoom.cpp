#include "aRoom.h"
#include <iostream>
#include <string>


using namespace std;

aRoom::aRoom()
{
	shortDescription = "";
	longDescription = "";
	
}
void aRoom::setShortDescription(string rest) {
	shortDescription = rest;
	
}

void aRoom::getShortDescription() {
	cout << shortDescription;
	
}

void aRoom::setLongDescription(string aline) {
	longDescription = aline;
}

void aRoom::getLongDescription() {
	cout << longDescription << endl;
}

void aRoom::addExit(string direction, int toRoom) {
	exitList.addExit(direction, toRoom);
}

int aRoom::findExit(string direction) {
	

	return exitList.findExit(direction);
	
}

void aRoom::addItem(string name, string description, bool canTake) {
	anItem I;
	I.setName(name);
	I.setDescription(description);
	I.setCanTake(canTake);
	itemList.addItem(I);

}
int aRoom::findItem(string name) {
	return itemList.findItem(name);

}
anItem aRoom::removeItem(int index) {
	return  itemList.removeItem(index);

	
}
void aRoom::displayItems() {
	 itemList.displayItems();
}
void aRoom::displayExits() {
	 exitList.displayExits();
}
void aRoom::enter() {
	cout << shortDescription << endl;
	displayExits();
}
void aRoom::look() {
	cout << longDescription << endl;
	displayItems();
	displayExits();
}
void aRoom::examine(string name, anItemList playerInventory) {
	if (name.compare("") == 0) {
		cout << "Examine what?" << endl;
	}
	bool found = false;
	for (int i = 0; i < itemList.getNumItems(); i++) {
		if (name.compare(itemList.getItem(i).getName()) == 0 || name.compare(playerInventory.getItem(i).getName()) == 0) {
			cout << itemList.getItem(i).getDescription() << endl;
			found = true;
		}
	}


		for (int i = 0; i < itemList.getNumItems(); i++) {
			if (name.compare(itemList.getItem(i).getName()) == 0 && name.compare(playerInventory.getItem(i).getName()) == 0) {
				//cout << itemList.getItem(i).getDescription() << endl;
				found = false;
			}
			}
	
			if (found) {
				cout << "There is no " << name << endl;
			}
	
}

void aRoom::take(string name, anItemList playerInventory) {
	if (name.compare("") == 0) {
		cout << "Take what?" << endl;
		return;
	}
	else {
		bool found = false;
		for (int i = 0; i < itemList.getNumItems(); i++) {
			if (name.compare(itemList.getItem(i).getName()) == 0) {
				
				found = true;

			}

		}
		if (found) {
			for (int i = 0; i < itemList.getNumItems(); i++) {
				if (name.compare(itemList.getItem(i).getName()) == 0) {
					//cout << itemList[i].getDescription() << endl;
					found = true;
					if (itemList.getItem(i).getCanTake() == true) {
						playerInventory.addItem(itemList.getItem(i));
						itemList.removeItem(i);
						cout << "You take the " << name << endl;
					}
					if (itemList.getItem(i).getCanTake() == false) {
						cout << "That item cannot be taken" << endl;
					}
				}
			}
		}
		else {
			cout << "There is no " << name << endl;
		}
	}
	
}

void aRoom::drop(string name, anItemList playerInventory) {
	if (name.compare("") == 0) {
		cout << "Drop what?" << endl;
	}
	else {
		bool found = false;
		for (int i = 0; i < playerInventory.getNumItems(); i++) {
			if (name.compare(playerInventory.getItem(i).getName()) == 0) {
				//cout << itemList[i].getDescription() << endl;
				found = true;

			}

		}
		if (found) {
			for (int i = 0; i < playerInventory.getNumItems(); i++) {
				if (name.compare(playerInventory.getItem(i).getName()) == 0) {
					//cout << itemList[i].getDescription() << endl;
					found = true;
					itemList.addItem(playerInventory.getItem(i));
					playerInventory.removeItem(i);
					cout << "You drop the " << name << endl;


				}
			}
		}
		else {
			cout << "You don't have a " << name << endl;
		}
	}
	
}

void aRoom::print() {
	cout << "ROOM: short = " << shortDescription << endl;
	cout << longDescription << endl;
	itemList.print();
	exitList.print();
}
