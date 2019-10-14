// Allows user to add and remove numbers to an array implemented with a dynamic class
// Zachary Waterbury
// 11/18/2018

#include "varArray.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	varArray arr;	// Creates Object to hold array starting with size 0

	// Variables to hold user input
	char operation = ' ';
	double number;

	// Loops as long as user does not input q as a choice
	while (operation != 'q') {

		// Getting user input
		cout << "enter operation [a/r/q] and number: ";
		cin >> operation;

		// Determines wether to add a number or remove a number
		switch (operation) {

			// Adds a number if user input was 'a'
		case 'a':
			cin >> number;	// Gets number choice from user
			arr.addNumber(number);	// Adds user number to the array
			arr.output(); // Prints out the array
			break;

			// Removes a number if user input was 'r'
		case 'r':
			cin >> number;	// Gets number choice from user
			arr.removeNumber(number);	// Removes user number from the array
			arr.output(); // Prints out the array
			break;

		}
	}

}