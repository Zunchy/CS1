// Mikhail Nesterenko
// tests battleShip functions implementation
// 10/13/2013

#include "battleship.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	srand(time(nullptr));

	// create Location
	Location mySpot;
	mySpot.x = 5;
	mySpot.y = 'e';

	// print Location 
	cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

	mySpot = pick(); // assign randomly generated Location to mySpot
	cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl;

	mySpot = fire(); // assign user input Location to mySpot
	cout << "mySpot.x = " << mySpot.x << " mySpot.y = " << mySpot.y << endl << endl;

	
	Ship myShip;

	myShip.loc = pick(); // assign random Location to myShip
	myShip.sunk = false;  // myShip is not sunk
	printShip(myShip); // print myShip information

	if (match(myShip, mySpot))
		cout << "myShip is at mySpot Location\n" << endl;
	else
		cout << "myShip is not at mySpot Location\n" << endl;

	sink(myShip); // sinking myShip
	printShip(myShip); // print sunk ship

	
	Ship myFleet[fleetSize];

	initialize(myFleet); //assigning -1 to all ship's Locations in myFleet
	printFleet(myFleet);

	deploy(myFleet); // deploying ships at random Locations
	printFleet(myFleet);

	if(check(myFleet,mySpot) != -1)
	  cout << endl << "myFleet has a ship at mySpot\n" << endl;
	else
	  cout << endl << "myFleet does not have a ship at mySpot\n" << endl;

	if(operational(myFleet))
	  cout << "at least one ship is not sunk\n" << endl;
	else
	  cout << "all ships are sunk\n" << endl;
	
}

