// Keeping track of shots fired in a Battleship game using multidimentional arrays
// Zachary Waterbury
// 11/26/2018

#include <iostream>
using std::cout; using std::cin; using std::endl;

// size of the ocean
const int oceanLength = 6;
const int oceanWidth = 6;

// Function prototypes (Defined after main)
int getX(char);
void printGame(bool[oceanLength][oceanWidth]);

int main() {

	bool shots[oceanLength][oceanWidth];	// 2d array to hold shot locations

	// Variables to hold fire location
	char choiceX;
	int choiceY;
	
	char choice;	// Variable to hold user choice

	// Prompts and recieves user input
	cout << "Make a shot? [y/n]: ";
	cin >> choice;

	// Loops as long as the user's choice is not 'n'
	while (choice != 'n') {
	
		cout << endl << "Location? ";

		cin >> choiceX >> choiceY;	// Gets user's shot location

		shots[getX(choiceX) - 1][choiceY - 1] = true;	// Marks the location in the array that the user fired upon

		printGame(shots);	// Prints out the game board

		// Prompts the user if they want to fire another shot and gets their unput
		cout << "Another shot? [y/n]: ";
		cin >> choice;
	}
}

// Function that converts the character chosen by the user into an integer used for indexing
int getX(char c) {

	switch (c) {

	case 'a':
		return 1;
		break;

	case 'b':
		return 2;
		break;

	case 'c':
		return 3;
		break;

	case 'd':
		return 4;
		break;

	case 'e':
		return 5;
		break;

	case 'f':
		return 6;
		break;

	}

}

// Function that prints out the board
void printGame(bool s[oceanLength][oceanWidth]) {

	cout << endl << "All fired shots" << endl;
	cout << "  a b c d e f";

	// Prints out each row and column of the array
	for (int i = 0; i < oceanLength; ++i) {

		cout << endl << i + 1;

		for (int j = 0; j < oceanWidth; ++j)
			if (s[j][i] == true)
				cout << " " << '*';
			else
				cout << " " << ' ';

	}

	cout << endl;

}
