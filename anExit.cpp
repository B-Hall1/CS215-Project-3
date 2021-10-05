#include <iostream>
#include "anExit.h"

//------------------------------------------------------
//                     constructor 
//------------------------------------------------------
anExit::anExit() { toRoom = -1; direction = ""; }

//------------------------------------------------------
//                     set methods
//------------------------------------------------------
void   anExit::setDirection(string dir) { direction = dir; }
void   anExit::setToRoom(int roomIndex) { toRoom = roomIndex; }

//------------------------------------------------------
//                     get methods
//------------------------------------------------------
string anExit::getDirection() { return direction; }
int    anExit::getToRoom() { return toRoom; }

//------------------------------------------------------
//                        print
//------------------------------------------------------
void anExit::print() {
	cout << "EXIT: toRoom = " << toRoom << " direction = " << direction << endl;
} // print()