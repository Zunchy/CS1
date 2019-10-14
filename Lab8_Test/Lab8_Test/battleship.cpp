// Function Definitions for the Battleship Game
// Zachary Waterbury
// 10/22/2018

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// Loops through number of ships and initializes each ship to an unassigned location
void initialize(Ship ships[]) {

	for (int i = 0; i < fleetSize; i++) {

		ships[i].loc.x = -1;
		ships[i].loc.y = '*';
	}
}

Location pick() {

	// Location to be returned
	Location rndLoc = {};


	// Assigns random x-coordinate to the location
	rndLoc.x = rand() % 6 + 1;

	// Assigns random y-coordinate to the location
	switch (rand() % 6 + 1) {

	case 1:
		rndLoc.y = 'a';
		break;
	case 2:
		rndLoc.y = 'b';
		break;
	case 3:
		rndLoc.y = 'c';
		break;
	case 4:
		rndLoc.y = 'd';
		break;
	case 5:
		rndLoc.y = 'e';
		break;
	case 6:
		rndLoc.y = 'f';
		break;

	}

	return rndLoc;

}

// Checks if the location of the ship matches the location passed in to the function
bool match(const Ship s, Location l) {

	if (s.loc.x == l.x && s.loc.y == l.y)
		return true;
	else
		return false;
}

// Checks if any of the ships in the fleet have the location of the location passed in to the function
int check(const Ship ships[], Location l) {

	for (int i = 0; i < fleetSize; i++) {

		if (match(ships[i], l))
			return i;
	}

	return -1;

}

// Deploys fleet of ships to randomly assigned locations, locations limited to one per ship
void deploy(Ship ships[]) {

	// Keeps track of deployed ships
	int deployedShips = 0;

	// Holds random location
	Location shipLoc;

	// Loops until all ships are deployed
	while (deployedShips != fleetSize) {

		// selects random location
		shipLoc = pick();

		// Checks if there is a ship already assigned to that location
		// if not, assignes the ship to the location and sets its sunk state to false
		if (check(ships, shipLoc) == -1) {
			ships[deployedShips].loc = shipLoc;
			ships[deployedShips].sunk = false;
			++deployedShips;
		}
	}
}

// Prints out ship stats
void printShip(const Ship s) {

	cout << s.loc.y << s.loc.x;

	if (s.sunk)
		cout << " sunk, ";
	else
		cout << " up, ";

}

// Prints out fleet stats
void printFleet(const Ship ships[]) {

	for (int i = 0; i < fleetSize; i++)
		printShip(ships[i]);

	cout << endl;
}

// Determines if at least one ship in the fleet is operational
bool operational(const Ship ships[]) {

	for (int i = 0; i < fleetSize; i++)
		if (ships[i].sunk == false)
			return true;

	return false;
}

// Creates a location based on user input on where to fire
Location fire() {

	Location choice;

	cout << endl << "Enter the loaction where you would like to fire a shot seperated by a space ex.(a 2): ";
	cin >> choice.y >> choice.x;
	cout << endl;
	return choice;

	return choice;
}

// Sinks a ship
void sink(Ship& s) {

	s.sunk = true;

}