// Computes absolute value, square root, floor operation, and power operation of values based on user input
// Zachary Waterbury
// 9/10/2018

#include <iostream>
#include <cstdlib>
#include <cmath>

using std::cout; using std::cin; using std::endl;

int main() {

	// Displays Options
	cout << "1. absolute value" << endl;
	cout << "2. square root" << endl;
	cout << "3. floor" << endl;
	cout << "4. power" << endl;

	// Declares variable to hold user selection and initializes it to 0 in order
	// for it to be used in the do while conditional
	int choice = 0;

	do {
		cout << "Select an operation: ";

		// Stores the user's operation selection
		cin >> choice;

		// Determines what operation to perform based on user selection
		switch (choice) {
		// Computes absolute value operation
		case 1:
			cout << "Enter a Number ";
			double absNum;
			cin >> absNum;
			cout << "The result is: " << abs(absNum) << endl;
			break;
		// Computes square root operation
		case 2:
			cout << "Enter a Number: ";
			double sqrtNum;
			cin >> sqrtNum;
			cout << "The result is: " << sqrt(sqrtNum) << endl;
			break;
		// Computes floor operation
		case 3:
			cout << "Enter a Number ";
			double floorNum;
			cin >> floorNum;
			cout << "The result is: " << floor(floorNum) << endl;
			break;
		// Computes power operation
		case 4:
			cout << "Enter Base: ";
			double baseNum;
			cin >> baseNum;
			cout << "Enter exponent: ";
			double expNum;
			cin >> expNum;
			cout << "The result is: " << pow(baseNum, expNum) << endl;
			break;
		// Alerts the user when the input is not a listed option and exits the program
		default:
			cout << "Your selection was not a listed option." << endl;
			break;
		} 
	// Loop that continues to run the program until a value that is not listed as an option is entered
	} while (choice > 0 && choice < 5);
	
}
