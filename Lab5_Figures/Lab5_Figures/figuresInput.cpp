// Prints out various shapes based on user input selection
// Zachary Waterbury
// 9/21/2018

#include <iostream>
#include "figures.h"

using std::cout; using std::cin; using std::endl;

int main() {

	int figure = 0; // holds figure selection and initialized to 0 to control the loop

	do {
		// Displays instructions
		cout << "1. square" << endl;
		cout << "2. diagonal line" << endl;
		cout << "3. bottom triangle" << endl;
		cout << "4. top triangle" << endl;
		cout << "select figure: ";

		cin >> figure; // Reads in figure choice

		cout << "select size: ";

		// Holds the size of the figure and is read in
		int size; 
		cin >> size;

		// Determines the function to be called based on the figure selected
		switch (figure) {
		case 1:
			square(size);
			break;
		case 2:
			dLine(size);
			break;
		case 3:
			botTriangle(size);
			break;
		case 4:
			topTriangle(size);
			break;
		default:
			cout << "The choice selected is not a valid option.";
		}

		cout << endl;

	} while (figure > 0 && figure < 5);
}