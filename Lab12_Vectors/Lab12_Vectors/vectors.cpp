// Allows user to add and remove numbers to a vector
// Zachary Waterbury
// 11/18/2018

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector;

// Function Definitions Defined Under Main
void output(vector<double>);
bool check(double, vector<double>);

int main() {

	vector<double> v;

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
			cin >> number; // Gets number choice from user

			if(!check(number, v))	// Checks if the number is already in the vector
				v.push_back(number);	// Adds the number to the vector

			output(v); // Prints out the elements of the vector
			break;

		// Removes a number if user input was 'r'
		case 'r':
			cin >> number; // Gets number choice from user

			if (check(number, v)) {	// Checks if the number is in the vector

				vector<double>::iterator toRemove = v.begin();

				for (vector<double>::iterator ip = v.begin(); ip != v.end(); ++ip)
					if (*ip == number) {
						toRemove = ip;
						v.erase(toRemove);
						break;
					}
			}
				
			output(v); // Prints out the elements of the vector
			break;

		}
	}
}

// Outputs the elements in the vector
void output(vector<double> vec) {

	for (vector<double>::iterator ip = vec.begin(); ip != vec.end(); ++ip)
		cout << *ip << " ";

	cout << endl;

}

// Checks if the user's input is in the vector
bool check(double num, vector<double> vec) {

	for (vector<double>::iterator ip = vec.begin(); ip != vec.end(); ++ip)
		if (*ip == num)
			return true;

	return false;

}