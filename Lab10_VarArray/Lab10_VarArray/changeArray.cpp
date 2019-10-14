// Allows user to add and remove numbers to an array
// Zachary Waterbury
// 11/8/2018

#include "varArray.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	int size = 0;  // Sets array size to 0 to start
	double *array = new double[size]; // Array to be shrunken and grown
	
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
			cin >> number;	// Reads in number from user
			addNumber(array, number, size);	// Adds user number to the array
			output(array, size); // Prints out the array
			break;

		// Removes a number if user input was 'r'
		case 'r':
			cin >> number;	// Reads in number from user
			removeNumber(array, number, size);	// Removes user number from the array
			output(array, size); // Prints out the array
			break;

		}
	}

	delete[] array; // Deallocates the array

}