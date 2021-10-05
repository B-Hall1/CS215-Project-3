#include <iostream>
#include "anItem.h"

anItem::anItem() {
	name = "";
	description = "";
	canTake = false;
}

void anItem::setName(string newName) {
	name = newName;
}

void anItem::setDescription(string newDescription) {
	description = newDescription;
}
void anItem::setCanTake(bool newTake) {
	canTake = newTake;
}

string anItem::getName() {
	return name;
}

string anItem::getDescription() {
	return description;
}
bool anItem::getCanTake() {
	return canTake;
}
void anItem::print() {
	cout << "ITEM: name=" << name << " canTake=" << canTake << " desc=" << description << endl;
}