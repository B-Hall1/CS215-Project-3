#include <iostream>
#include "aGame.h"
#include <sstream>
#include <fstream>
#include "anExitList.h"
#include "anItemList.h"
#include "anItem.h"
#include "aRoom.h"
using namespace std;
aGame::aGame(){
	currRoom = 0;
    numRooms = 0;
	winRoom = 0;
	winText = "";
}
//--------------------------------------------------------------
//                     dispHelp
//--------------------------------------------------------------
void aGame::dispHelp() {
	cout << "Discover a task to complete. Complete it by findin/taking \n";
	cout << "items from places throughout the world, then dropping the items\n";
	cout << "in the place instructed. Good Luck!\n";
	cout << "Commands: \n";
	cout << "- look:          see the room description, objects and exits.\n";
	cout << "- exa <object>:  examine an object in the room or inventory.\n";
	cout << "- inv:           see a list of your inventory\n";
	cout << "- drop <object>: drop inventory object in the roo\n";
	cout << "- take <object>: take object from room into your inventory.\n";
	cout << "- help:          display this menu again.\n";
	cout << "- quit:          exit the game\n";
	cout << "- print:         for debugging: print internal data structures.\n";
	cout << "ALSO: all exits are commands to take the exit.\n";
	rooms[currRoom].enter();
	cout << "==>";
	string command;
	string rest;
	//cin >> command;
	string aline;
	cin.ignore();
	getline(cin, aline);
	splitFirst(aline, command, rest);
	while (command.compare("quit") != 0) {


		if (command.compare("look") == 0) {
			rooms[currRoom].look();
		}
		else if (command.compare("exa") == 0) {
			rooms[currRoom].examine(rest, playerInv);
		}
		else if (command.compare("inv") == 0) {
			inv();
		}
		else if (command.compare("drop") == 0) {
			bool gameWin = win(rest, playerInv);
		}
		else if (command.compare("take") == 0) {
			rooms[currRoom].take(rest, playerInv);
		}

		else if (command.compare("dispHelp") == 0) {
			dispHelp();
		}

		else if (command.compare("print") == 0) {
			print();
		}

		else {
			cout << "What?" << endl;


		}


		if (command.compare("quit") == 0) {
			cout << "Thanks for playing! Bye!" << endl;
		}
		cout << "==>";
		getline(cin, aline);
		splitFirst(aline, command, rest);
	}



} // dispHelp()

  //------------------------------------------------------------------------------------------
  //                                    splitFirst
  //------------------------------------------------------------------------------------------
  // Given:		aline: any string
  // Modifies:    first: the first word of aline
  //              rest:  all words of aline with the first word removed
  //                     multiple contiguous white spaces are reduced to one blank
  // Returns:     0: aline was empty, nothing to split
  //              1: aline only contained one word, so command is empty
  //              2: alone containted two or more words and was split
  // Splits a given string into the first word in the string and the rest of the string.
  // Returns the number of resulting strings.
  // Examples:
  //		splitFirst("", first, rest)                 sets first="", rest="" and  returns 0
  //      splitFirst("look", first, rest)             sets first="look", rest="" and returns 1
  //      splitFirst("look over      there", first, rest)  sets first="look", rest="over there" and
  //                                                       returns 2
  //-----------------------------------------------------------------------------------------
int aGame::splitFirst(string aline, string & first, string & rest) {
	first = rest = "";				// init results to empty string
	if (aline == "") return 0;		// if nothing to split, we're done
	string next;					// next word in aline
	istringstream iss(aline);		// converts aline into a input string stream
	iss >> first;                   // extract the first word, if any
	iss >> rest;                    // extract the second word, if any
	if (rest == "") return 1;       // if the second word is empty, only 1 word in aline
	iss >> next;					// extract the third word, if any
	while (iss && next != "") {     // while there are more words in the stream
		rest = rest + " " + next;   //       stick it on the end of rest
		iss >> next;                //       get the next word, if any
	}
	return 2;                       // aline was split into two parts.
} // splitFirst()

  //--------------------------------------------------------------
  //                     print
  //--------------------------------------------------------------
  // note: may have to change the names of some things here.
void aGame::print() {
	cout << "GAME: currRoom=" << currRoom << " winRoom=" << winRoom << " winText=" << winText << endl;
	cout << "GAME WIN INVENTORY: \n";
	winInv.print();
	cout << "GAME PLAYER INVENTORY: \n";
	playerInv.print();
	cout << "GAME: numRooms = " << numRooms << endl;
	for (int i = 0; i < numRooms; i++)
		rooms[i].print();
} // print()
void aGame::readfile(string filename) {
	ifstream f;
	f.open(filename);
	if (f.fail()) {

		cout << "File is not valid" << endl;
	}
bool j;
int n = 0;
	if (f.is_open()) {

		
		numRooms = 0;
		/*tag.compare("quit") != 0*/
		while (n != 1) {

			string command;
			string rest;
			string aline;
			//f.ignore();
			getline(f, aline);
			n = splitFirst(aline, command, rest);
			if (command.compare("WIN_ROOM:") == 0) {

				istringstream stoi(rest);
				if (command == "WIN_ROOM:") {
					stoi >> winRoom;
				}
			}
			else if (command.compare("WIN_ITEM:") == 0) {
				if (command == "WIN_ITEM:") {
					winInv.addItem(rest, "", true);
				}
			}

			else if (command.compare("WIN_TEXT") == 0) {

				if (command == "WIN_TEXT:") {
					winText = rest;
				}
			}
			else if (command.compare("ROOM:") == 0) {

				if (command == "ROOM:") {
					rooms[numRooms].setShortDescription(rest);
					getline(f, aline);
					rooms[numRooms].setLongDescription(aline);
					//rooms[numRooms].getShortDescription();
					numRooms++;
				}
			}

			else if (command.compare("ROOM_ITEM:") == 0) {

				if (command == "ROOM_ITEM:") {
					
					splitFirst(rest, command, rest);
					if (command == "true") {
						j = true;
					}
					else {
						j = false;
					}

					getline(f, aline);
					rooms[numRooms - 1].addItem(rest, aline, j);

				}
				//numItems++;
			} 
			

			else if (command.compare("EXIT:") == 0) {
				
				if (command == "EXIT:") {
					splitFirst(rest, command, rest);
					int i = stoi(command);
					rooms[numRooms - 1].addExit(rest, i);
				}
			}
			
			/*else {
				tag = "quit"
			}*/
		}
	}

	f.close();

	
}
	void aGame::play() {
		string filename;
		cout << "+-----------------------------------------------+" << endl;
		cout << "|                  SimpleQuest                  |" << endl;
		cout << "|               by Blair Hall                   |" << endl;
		cout << "+-----------------------------------------------+" << endl;
		cout << "Enter game data file name: ";
		cin >> filename;
		readfile(filename);


		cout << "Discover a task to complete.Complete it by findin / taking" << endl;
		cout << "items from places throughout the world, then dropping the items" << endl;
		cout << "in the place instructed.Good Luck!" << endl;
		cout << "Commands:" << endl;
		cout << "- look:          see the room description, objects and exits." << endl;
		cout << "- exa <object> : examine an object in the room or inventory. " << endl;
		cout << "- inv : see a list of your inventory" << endl;
		cout << "- drop <object> : drop inventory object in the room" << endl;
		cout << "- take <object> : take object from room into your inventory." << endl;
		cout << "- help : display this menu again." << endl;
		cout << "- quit : exit the game" << endl;
		cout << "- print : for debugging : print internal data structures." << endl;
		cout << "ALSO : all exits are commands to take the exit." << endl;
		system("pause");
		system("cls");
		cout << "You fall asleep and enter the world of dreams…" << endl;


		rooms[currRoom].enter();
		cout << "==>";
		string command;
		string rest;
		//cin >> command;
		string aline;
		cin.ignore();
		getline(cin, aline);
		splitFirst(aline, command, rest);
		while (command.compare("quit") != 0) {


			if (command.compare("look") == 0) {
				rooms[currRoom].look();
			}
			else if (command.compare("exa") == 0) {
				rooms[currRoom].examine(rest, playerInv);
			}
			else if (command.compare("inv") == 0) {
				inv();
			}
			else if (command.compare("drop") == 0) {
				bool gameWin = win(rest, playerInv);
			}
			else if (command.compare("take") == 0) {
				rooms[currRoom].take(rest, playerInv);
			}

			else if (command.compare("help") == 0) {
				dispHelp();
			}

			else if (command.compare("print") == 0) {
				print();
			}

			else {
				cout << "What?" << endl;


			}
			

		if (command.compare("quit") == 0) {
			cout << "Thanks for playing! Bye!" << endl;
		}
		cout << "==>";
		getline(cin, aline);
		splitFirst(aline, command, rest);
		}
		
	}
void aGame::look() {
	rooms[currRoom].look();
}

void aGame::exa(string name) {
	
	rooms[currRoom].examine(name, playerInv);
}

void aGame::inv() {
	for (int i = 0; i < playerInv.getNumItems(); i++) {
		playerInv.getItem(i).print();
		
	}
}

void aGame::drop(string name) {
	rooms[currRoom].drop(name, playerInv);
}

void aGame::take(string name) {
	rooms[currRoom].take(name, playerInv);
}


bool aGame::win(string item, anItemList playerInv) {
	rooms[currRoom].drop(item, playerInv);
		if (currRoom == winRoom) { 
		
			for (int i = 0; i < winInv.getNumItems(); i++) {
				if (rooms[currRoom].findItem(winInv.getItem(i).getName()) == NOT_FOUND) {
					return false;
				}
				return true;
		}
			return false;
	}
}