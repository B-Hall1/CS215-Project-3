#pragma once

#include <string>
using namespace std;

class anItem {
public:
	anItem();
	void setName(string newName);
	void setDescription(string newDescription);
	void setCanTake(bool newTake);
	string getName();
	string getDescription();
	bool getCanTake();
	void print();

private:
	string name;
	string description;
	bool canTake;
};