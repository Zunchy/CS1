// Sorts 3 numbers in increasing order
// Zachary Waterbury
// 9/24/2018

#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int&, int&); // Swaps the values of the 1st and 2nd paramenter

int main() {

	// inputs the numbers
	cout << "Enter three numbers: ";
	int x, y, z;
	cin >> x >> y >> z;

	// Calls swap method when first number is greater than the second
	if(x > y)
		swap(x,y);

	// Calls swap method when first number is greater than the third
	if(x > z)
		swap(x,z);

	// Calls swap method when second number is greater than the third
	if (y > z)
		swap(y,z);

	// Displays Results
	cout << x << " " << y << " " << z << endl;
}

// Swaps the values of num1 and num2
void swap(int& num1, int& num2) {

	int tmp = num1;
	num1 = num2;
	num2 = tmp;

}