#include <iostream>
#include "anExitList.h"

//------------------------------------------------------
//                     constructor
//------------------------------------------------------
// the number of items in a new list is zero
anExitList::anExitList() { numExits = 0; }

//------------------------------------------------------
//                    get methods
//------------------------------------------------------
int  anExitList::getNumExits() { return numExits; }
anExit anExitList::getExit(int ndx) {
	if (ndx < 0 || ndx >= numExits) {
		cout << "anExitList::getExit: invalid index = " << ndx << endl;
		anExit emptyExit;
		return emptyExit;
	}
	return exit[ndx];
} // getExit()

  //-----------------------------------------------------
  //                     addExit (2 overloaded)
  //------------------------------------------------------
void anExitList::addExit(anExit newExit) {
	if (numExits < MAX_EXITS)
		exit[numExits++] = newExit;
	else {
		cout << "anExitList::addExit: MAX_EXITS EXCEEDED: " <<
			" toRoom=" << newExit.getToRoom() <<
			" direction=" << newExit.getDirection() << endl;
	}
} // addExit()

void anExitList::addExit(string dir, int to_room) {
	anExit newExit;
	newExit.setToRoom(to_room);
	newExit.setDirection(dir);
	addExit(newExit);
} // addExit()

  //------------------------------------------------------
  //                     findExit
  //------------------------------------------------------
  // search the list by direction.
  // returns toRoom of found exit, or NOT_FOUND
int  anExitList::findExit(string srchDir) {
	for (int i = 0; i < numExits; i++)
		if (srchDir == exit[i].getDirection()) {
			return exit[i].getToRoom();
		}
	return EXIT_NOT_FOUND;
} // findExit()

  //------------------------------------------------------
  //                     displayExits
  //------------------------------------------------------
  // print a list of exits in this list for the player

void anExitList::displayExits() {
	if (numExits == 0) {
		cout << "There are no exits.\n";
		return;
	}
	cout << "Exits: " << exit[0].getDirection();
	for (int i = 1; i < numExits; i++)
		cout << ", " << exit[i].getDirection();
	cout << ".\n";
} // displayExits()

  //------------------------------------------------------
  //                     print
  //------------------------------------------------------
void anExitList::print() {
	cout << "EXITLIST: numExits = " << numExits << endl;
	for (int i = 0; i < numExits; i++)
		exit[i].print();
} // printList()