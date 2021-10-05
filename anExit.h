#pragma once
//--------------------------------------------------------
//                        class anExit
//--------------------------------------------------------
// Describes an exit in a room
//--------------------------------------------------------
#include <string>
using namespace std;

class anExit {
public:
	anExit();
	void   setDirection(string dir);
	void   setToRoom(int roomIndex);
	string getDirection();
	int    getToRoom();
	void   print();
private:
	string direction; // direction user enters to take the exit
	int    toRoom;    // index of the room the exit leads to
};

