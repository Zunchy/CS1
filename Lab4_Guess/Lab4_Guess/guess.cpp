// Game where user tries to guess a random number between 1 and 200
// Zachary Waterbury
// 9/13/2018

#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;

int main() {

	// Initializes the random number generator
	srand(time(nullptr));

	// Selects the random number from 1-200
	int randNum = rand() % 200 + 1;

	// Prompts Instructions and reads in the user's guess
	cout << "I selected a number between 1 and 200, what is it ?    ";
	int guess;
	cin >> guess;

	// Loop that iterates until the number is correctly guessed
	do {
		// Checks if guess is smaller or larger than the random number
		if (guess < randNum) {
			cout << "wrong, it is larger, what is it?    ";
			cin >> guess;
		} else {
			cout << "wrong, it is smaller, what is it?    ";
			cin >> guess;
		}
	} while (guess != randNum);

	// Displays when number is correctly guessed
	cout << "correct!" << endl;

}
