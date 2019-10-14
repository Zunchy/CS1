// Implementation of the Battleship Game where users guess to sink 6 randomly placed ships
// Zachary Waterbury
// 10/23/2018

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	srand(time(nullptr));	// Initializes random number generator

	Ship gameShips[fleetSize];	// Creates a fleet of ships

	initialize(gameShips);		// Initializes each ship
	deploy(gameShips);			// Deploys each ship to a random location

	
	// Prints out ship locations if user wishes
	cout << "Would you like to display the locations of the ships? [y,n]: ";
	char choice;
	cin >> choice;

	if(choice == 'y')
		printFleet(gameShips);

	// Main Game Loop
	while (operational(gameShips)) {
		
		Location choice = fire();	// Gets a position to fire upon

		int shipLocation = check(gameShips, choice);	// Holds the result if a ship is where the user fired a shot

		// If ship was in the location where the user fired, the ship is sunk
		if (shipLocation != -1) {

			gameShips[shipLocation].sunk = true;
			cout << "Hit!" << endl;
		}
		else
			cout << "Miss!" << endl;
	}

	// Displays when game is over
	cout << endl << "All ships have been sunk! " << endl << endl;

}