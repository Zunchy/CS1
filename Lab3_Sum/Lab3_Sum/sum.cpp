// Displays the sum of all negative numbers in input until a 0 is inputted
// Zachary Waterbury
// 9/4/2018

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	// Displays input instructions
	cout << "Input sequence of integers (zero to stop) : ";

	// Declares variables to keep track of number being inputted and the sum of negative numbers
	int sum = 0;
	int num;

	// Reads in first number from input to initialize num
	cin >> num;

	// Loop that iterates until num is equal to 0
	while (num != 0) {

		// Checks if num is negative and if so adds the value of num to the sum variable
		if (num < 0) sum += num;

		// Reads in the next input
		cin >> num;

	}
	
	// Displays the results
	cout << "The sum of negative numbers is: " << sum << endl;
}