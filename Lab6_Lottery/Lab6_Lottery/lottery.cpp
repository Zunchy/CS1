// Lottery program where a user selects a number between 1 and 100
// to try and guess a number in a selection of 20 random lottery numbers
// Zachary Waterbury
// 9/27/2018

#include <ctime>
#include <cstdlib>
#include <iostream>

using std::cin; using std::cout; using std::endl;

void assign(int w[]); // assigns every element in the wins array to 0
bool check(int num, int w[]); // returns true if the variable num is equal to an element in the array w
void draw(int w[]); // gives each element in the array w a random value between 1 and 100
int entry(); // gets user input for guess at lottery numbers
void printOut(int choice, int w[]); // prints out lottery numbers and if the user won or not

// Keeps the size of the wins arrays
const int lottoSize = 20;

int main() {

	int wins[lottoSize]; // Gives the array wins a size of 20 (the value of lottoSize)
	assign(wins);	// Assigns each element of wins to 0
	draw(wins);		// Gives each element of wins a random value
	int choice = entry(); // Stores user's choice
	printOut(choice, wins);	// Prints results of the lottery
}

// Loops through each element in the array w and assigns it to 0
void assign(int w[]) {

	for (int i = 0; i < lottoSize; i++)
		w[i] = 0;

}

// Loops through each element in the array w and checks if the variable num is present in each element
bool check(int num, int w[]) {

	for (int i = 0; i < lottoSize; i++) {

		// Checks if the number is in the current element in the array
		if (num == w[i])
			return true;

	}

	return false;
		
}

void draw(int w[]) {

	// Initializes the random number generator
	srand(time(nullptr));

	// Variable to hold random numbers
	int randNum;

	// Variable used in loop to point random values to each position in the w array
	int lNum = 0;

	while (lNum < lottoSize) {

		// Selects the random number from 1-100
		randNum = rand() % 100 + 1;

		// If the random number is not in the array, the current element is assigned the
		// value of the random number and the index of the array to be checked is incremented
		if (!check(randNum, w)) {

			w[lNum] = randNum;
			lNum++;

		}
			
	}

}

// Simply gets user input as a single integer to be used as a guess at the lottery numbers
int entry() {

	cout << "Enter a single number from 1 to 100: ";
	int choice;
	cin >> choice;
	return choice;

}

// Prints our lottery numbers and if the user won the lottery or not
void printOut(int choice, int w[]) {

	cout << "The lottery numbers are: " << endl;
	
	// Prints out each lottery number
	for (int i = 0; i < lottoSize; ++i)
		cout << w[i] << endl;

	// Prints out user's choice
	cout << "The number you selected was: " << choice << endl;

	// Determines if the user won the lottery or not
	if (check(choice, w))
		cout << "Congratulations! You won." << endl;
	else 
		cout << "Sorry, you did not win." << endl;
}