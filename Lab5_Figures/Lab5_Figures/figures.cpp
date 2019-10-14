// Holds function definitions for various shapes
// Zachary Waterbury
// 9/21/2018

#include <iostream>
#include "figures.h"

using std::cout; using std::cin; using std::endl;

// Square function that prints a hollow or filled square. size parameter determines the size of the shape
void square(int size) {
	cout << "filled or hollor [f/h]: ";

	char choice;	// holds the value that determines wether the user selected a filled or hollow square
	cin >> choice;

	// prints a filled square
	if (choice == 'f') {
		for (int i = 0; i < size; ++i) {
			cout << endl;
			for (int j = 0; j < size; ++j)
				cout << "+";
		}

		cout << endl;
	}
	// prints a hollow square
	else if (choice == 'h') {
		for (int i = 0; i < size; ++i) {
			cout << endl;
			for (int j = 0; j < size; ++j) {

				if (i == 0)
					cout << "+";
				else if (i == size - 1)
					cout << "+";
				else if (j == 0)
					cout << "+";
				else if (j == size - 1)
					cout << "+";
				else
					cout << " ";

			}
		}

		cout << endl;
	}
}

// Diagonal Line function that prints a diagonal line. size parameter determines the size of the line
void dLine(int size) {

	for (int i = 0; i < size; ++i) {
		cout << endl;
		for (int j = 0; j < size; ++j) {

			if (j == i)
				cout << "+";
			else
				cout << " ";

		}
	}

	cout << endl;

}

// Bottom triangle function that prints a bottom triangle. size parameter determines the size of the line
void botTriangle(int size) {

	for (int i = 0; i < size; ++i) {
		cout << endl;
		for (int j = 0; j < size; ++j) {

			if (j <= i)
				cout << "+";
			else
				cout << " ";

		}
	}

	cout << endl;

}

// Top triangle function that prints a top triangle. size parameter determines the size of the line
void topTriangle(int size) {

	for (int i = 0; i < size; ++i) {
		cout << endl;
		for (int j = 0; j < size; ++j) {

			if (j >= i)
				cout << "+";
			else
				cout << " ";

		}
	}

	cout << endl;

}