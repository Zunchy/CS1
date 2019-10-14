// Function Definitions for changing an array's size
// Zachary Waterbury
// 11/8/2018

#include "varArray.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;


// Prints out elements of the array
void output(double *ap, int s) {

	for (int i = 0; i < s; ++i) {
	
		cout << ap[i] << " ";
	
	}

	cout << endl;

}

// Checks if the num is present in the array and returns the index, if it is not, then it returns -1
int check(double *ap, double num, int s) {

	for (int i = 0; i < s; ++i) {

		if (ap[i] == num)
			return i;

	}

	return -1;

}

// Adds a specified number to the array
void addNumber(double *& ap, double num, int &s) {

	// Executes loop if the number specified is not already in the array
	if (check(ap, num, s) == -1) {

		double* newArr = new double[s + 1];		// New Array to accommodate the new number

		// Copies elements of old array to the new array
		for (int i = 0; i < s; i++)
			newArr[i] = ap[i];

		// Adds the new element to the array
		newArr[s] = num;

		delete[] ap;	// Deallocates the old array

		ap = newArr;	// Assigns the array pointer to the new array

		++s;	// Increases size variable of the array
	}

}

// Removes a specified number from the array
void removeNumber(double *& ap, double num, int &s) {

	if (check(ap, num, s) != -1) {

		double* newArr = new double[s - 1];		// New array to handle the deletion of an element

		bool found = false;		// Keeps track if the number to be deleted has been found

		// Loops through size of the old array
		for (int i = 0; i < s; ++i) {

			if (ap[i] == num)	// If the number to be deleted has been found,						
				found = true;	// sets found to true
			else
				if (!found)
					newArr[i] = ap[i];		// If the number hasn't been found copies element over as normal
				else
					newArr[i - 1] = ap[i];	// If number has been found copies the old element to the new array 1 position to the left

		}

		delete[] ap;	// Deallocates the old array

		ap = newArr;	// Assigns the array pointer to the new array

		--s;			// Decreases size variable of the array	
	}
}


