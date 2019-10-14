// Implementation of Battleship game using classes
// Zachary Waterbury
// 10/28/2018

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	srand(time(nullptr)); // Random seed

	Fleet ships;	// Object that holds the fleet of ships

	ships.deployFleet();	// Deploys ships in fleet in random locations

	// Asks user if fleets' location and status are to be printed throughout the game
	cout << "Print ship location and status throghout the game? [y/n]: ";
	char choice;
	cin >> choice;

	// Loops while there are ships that are not sunk
	while (ships.operational()) {
	
		Location shotLoc;	// Loaction obkect to store users shot

		shotLoc.fire();		// Gets input of user's shot

		// Sinks ship if user's shot matches ship location
		if (ships.isHitNSink(shotLoc))
			cout << endl << "Hit!" << endl;
		else
			cout << endl << "Miss" << endl;

		// Prints fleet if user requested it
		if (choice == 'y') {
			cout << endl;
			ships.printFleet();
		}

	
	}

	// Prints when game is finished and all ships are sunk
	cout << endl << "All ships have been sunk!" << endl;


}