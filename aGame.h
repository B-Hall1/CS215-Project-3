#pragma once
#include <string>
#include "anItemList.h"
#include "aRoom.h"
const int MAX_ROOMS = 100;

class aGame {
public:
	aGame();
	void dispHelp();

	void print();
	void readfile(string filename);
	void play();
	void look();
	void exa(string name);
	void inv();
	void drop(string name);
	void take(string name);
	bool win(string item, anItemList playerInv);
	//void help();

	//void print();

private:
	int splitFirst(string aline, string & first, string & rest);
	anItemList playerInv;
	anItemList winInv;
	aRoom rooms[MAX_ROOMS];
	int currRoom;
	int numRooms;
	int winRoom;
	string winText;
};