// Function definitions for Dynamically allocated objects
// Zachary Waterbury
// 11/16/2018

#include <iostream>
#include "vararray.h"

using std::cout; using std::cin; using std::endl;


// Void constructor to initialize member variables
varArray::varArray() {

	size = 0;
	dArray = new double(0);

}

// Checks if num is in the array and return the index if it is, otherwise returns -1
int varArray::check(double num) {

	for (int i = 0; i < size; ++i) {

		if (dArray[i] == num)
			return i;

	}

	return -1;

}

// Outputs array contents
void varArray::output() {

	for (int i = 0; i < size; ++i) {

		cout << dArray[i] << " ";

	}

	cout << endl;

}

void varArray::addNumber(double num) {

	// Executes loop if the number specified is not already in the array
	if (check(num) == -1) {

		double* newArr = new double[size + 1];		// New Array to accommodate the new number

		// Copies elements of old array to the new array
		for (int i = 0; i < size; i++)
			newArr[i] = dArray[i];

		// Adds the new element to the array
		newArr[size] = num;

		delete[] dArray;	// Deallocates the old array

		dArray = newArr;	// Assigns the array pointer to the new array

		++size;	// Increases size variable of the array
	}

}

void varArray::removeNumber(double num) {

	if (check(num) != -1) {

		double* newArr = new double[size - 1];		// New array to handle the deletion of an element

		bool found = false;		// Keeps track if the number to be deleted has been found

		// Loops through size of the old array
		for (int i = 0; i < size; ++i) {

			if (dArray[i] == num)	// If the number to be deleted has been found,						
				found = true;	// sets found to true
			else
				if (!found)
					newArr[i] = dArray[i];		// If the number hasn't been found copies element over as normal
				else
					newArr[i - 1] = dArray[i];	// If number has been found copies the old element to the new array 1 position to the left

		}

		delete[] dArray;	// Deallocates the old array

		dArray = newArr;	// Assigns the array pointer to the new array

		--size;			// Decreases size variable of the array	
	}

}

// Copy constructor
varArray::varArray(const varArray& arr) {

	// Assignes the member variables to the object from the argument
	size = arr.size;			
	dArray = new double[size];

	// Copies element of the array to the object array
	for (int i = 0; i < size; i++)
		dArray[i] = arr.dArray[i];
}

// Destructor, Deallocates the array in the object
varArray::~varArray() {

	delete[] dArray;

}

// Asignment Overloading
varArray& varArray::operator= (const varArray& r) {

	// Checks for equality 
	if (this != &r) {
	
		// Assignes the member variables to the object from the argument and deallocates the old array
		size = r.size;
		delete[] dArray;
		dArray = new double[size];

		// Copies element of the array over
		for (int i = 0; i < size; i++)
			dArray[i] = r.dArray[i];
	
	}

	return *this;

}

