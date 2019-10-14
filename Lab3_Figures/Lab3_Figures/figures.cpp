// Takes a number and prints out 5 different rectangles represented by + and " "
// Zachary Waterbury
// 9/7/2018

#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() {

	cout << "Input Number: ";

	// creates and initialize input variable 
	int num;
	cin >> num;

	// creates a numXnum rectangle made out of + signs
	for (int i = 0; i < num; ++i) {
		cout << endl;
		for (int j = 0; j < num; ++j)
			cout << "+";

	}

	cout << endl;

	// creates a numXnum rectangle made mostly out of " " and a + sign only when i == j
	for (int i = 0; i < num; ++i) {
		cout << endl;
		for (int j = 0; j < num; ++j) {

			if (j == i) 
				cout << "+";
			else 
				cout << " ";

		}
	}

	cout << endl;

	// creates a numXnum rectangle made out of + signs when i <= j, the rest of the shape being " "
	for (int i = 0; i < num; ++i) {
		cout << endl;
		for (int j = 0; j < num; ++j) {

			if (j <= i)
				cout << "+";
			else
				cout << " ";

		}
	}

	cout << endl;

	// creates a numXnum rectangle made out of + signs when i >= j, the rest of the shape being " "
	for (int i = 0; i < num; ++i) {
		cout << endl;
		for (int j = 0; j < num; ++j) {

			if (j >= i)
				cout << "+";
			else
				cout << " ";

		}
	}

	cout << endl;

	// creates a numXnum rectangle where only the permieter is made out of + signs
	for (int i = 0; i < num; ++i) {
		cout << endl;
		for (int j = 0; j < num; ++j) {

			if (i == 0)
				cout << "+";
			else if (i == num - 1)
				cout << "+";
			else if (j == 0)
				cout << "+";
			else if (j == num - 1)
				cout << "+";
			else
				cout << " ";

		}
	}

	cout << endl;

}