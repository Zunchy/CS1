// Function Definitions for the Location, Ship, and Fleet Classes
// Zachary Waterbury
// 10/24/2018

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

// Location Functions

Location::Location() : x(-1), y('*') {}	// Intilaizes Location Object

void Location::pick() {

	// Assigns random x-coordinate to the location
	x = rand() % 6 + 1;

	// Assigns random y-coordinate to the location
	switch (rand() % 6 + 1) {

	case 1:
		y = 'a';
		break;
	case 2:
		y = 'b';
		break;
	case 3:
		y = 'c';
		break;
	case 4:
		y = 'd';
		break;
	case 5:
		y = 'e';
		break;
	case 6:
		y = 'f';
		break;

	}

}

// Gets user input on a location they would like to fire at
void Location::fire() {

	cout << endl << "Enter the loaction where you would like to fire a shot seperated by a space ex.(a 2): ";
	cin >> y >> x;
	cout << endl;

}

// Prints out Location
void Location::print() const {

	cout << y << x;

}

// Compares two locations and if they are equal returns false
bool compare(const Location& loc1, const Location& loc2) {

	if (loc1.x == loc2.x && loc1.y == loc2.y)
		return true;
	else
		return false;

}

//
//	Ship Functions
//

Ship::Ship() : sunk(false) {}	// Intilaizes Ship Object

bool Ship::match(const Location& l) const {

	if (compare(l, loc))
		return true;
	else
		return false;

}


void Ship::sink() {

	sunk = true;

}

void Ship::setLocation(const Location& l) {

	loc = l;

}

void Ship::printShip() const {

	loc.print();

	if (sunk)
		cout << " sunk, ";
	else
		cout << " up, ";

}

int Fleet::check(const Location & l) const {

	for (int i = 0; i < fleetSize; i++) {

		if (ships[i].match(l))
			return i;
	}

	return -1;

}

void Fleet::deployFleet() {

	// Keeps track of deployed ships
	int deployedShips = 0;

	Location shipLoc;

	// Loops until all ships are deployed
	while (deployedShips != fleetSize) {

		// selects random location
		shipLoc.pick();

		// Checks if there is a ship already assigned to that location
		// if not, assignes the ship to the location and sets its sunk state to false
		if (check(shipLoc) == -1) {
			ships[deployedShips].setLocation(shipLoc);
			++deployedShips;
		}
	}

}

bool Fleet::operational() const {

	for (int i = 0; i < fleetSize; i++)
		if (ships[i].isSunk() == false)
			return true;

	return false;

}

bool Fleet::isHitNSink(const Location &l) {


	int shipLocation = check(l);	// Holds the result if a ship is where the user fired a shot

	// If ship was in the location where the user fired, the ship is sunk
	if (shipLocation != -1) {

		ships[shipLocation].sink();
		return true;
	}
	else
		return false;

}

void Fleet::printFleet() const {

	for (int i = 0; i < fleetSize; i++)
		ships[i].printShip();

	cout << endl;
}