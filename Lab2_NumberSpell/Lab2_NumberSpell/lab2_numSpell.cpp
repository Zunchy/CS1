// take a number and prints out its name spelled in English
// Zachary Waterbury
// 8/27/2018
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main() {

	// inputs the numbers
	cout << "Enter a number between 1 and 50: ";
	int num;
	cin >> num;

	// extracts tens out of num
	int tens = num / 10;
	// extracts singles out of num
	int singles = num % 10;

	// determines if num is less than 10 and prints the numbers text
	if (tens == 0) {
		switch (singles) {
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		case 5:
			cout << "five";
			break;
		case 6:
			cout << "six";
			break;
		case 7:
			cout << "seven";
			break;
		case 8:
			cout << "eight";
			break;
		case 9:
			cout << "nine";
			break;
		}
	}
	// determines if num is between 9 and 20 and prints the numbers text
	else if (tens == 1) {

		switch (singles) {
		case 0:
			cout << "ten";
			break;
		case 1:
			cout << "eleven";
			break;
		case 2:
			cout << "twelve";
			break;
		case 3:
			cout << "thirteen";
			break;
		case 4:
			cout << "fourteen";
			break;
		case 5:
			cout << "fifteen";
			break;
		case 6:
			cout << "sixteen";
			break;
		case 7:
			cout << "seventeen";
			break;
		case 8:
			cout << "eighteen";
			break;
		case 9:
			cout << "nineteen";
			break;
		}
	}
	// determines if num is between 19 and 51 and prints text related to number of tens
	else {
		switch (tens) {

		case 2:
			cout << "twenty";
			break;
		case 3:
			cout << "thirty";
			break;
		case 4:
			cout << "fourty";
			break;
		case 5:
			cout << "fifty";
			break;
		}
		// determines the single digit number after the tens to be displayed if num is between 19 and 51
		switch (singles) {
		case 1:
			cout << " one";
			break;
		case 2:
			cout << " two";
			break;
		case 3:
			cout << " three";
			break;
		case 4:
			cout << " four";
			break;
		case 5:
			cout << " five";
			break;
		case 6:
			cout << " six";
			break;
		case 7:
			cout << " seven";
			break;
		case 8:
			cout << " eight";
			break;
		case 9:
			cout << " nine";
			break;
		}

	}
}