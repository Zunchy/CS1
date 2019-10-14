// Determines how many doughnuts one can eat per day based on the BMR calculation of data entered
// Zachary Waterbury
// 9/19/2018

#include <iostream>

using std::cout; using std::cin; using std::endl;

// Function prototypes for calculating the BMR of men and women
double bmrMen(double w, double h, int a);
double bmrWomen(double w, double h, int a);

int main() {

	// Constant to hold how many calories are in an average doughnut
	const int doughnut = 195;

	// Promts gender input as a character and assigns it to variable gender
	cout << "Enter your gender ('m' for male, 'w' for female): ";
	char gender;
	cin >> gender;

	// Promts weight input and assigns it to variable weight
	cout << "Enter your weight in pounds: ";
	double weight;
	cin >> weight;

	// Prompts height input in feet and inches and assigns them to variables feet and inches
	cout << "Enter your height in feet and inches seperated by a space: ";
	double feet, inches;
	cin >> feet >> inches;

	// Calculates total height in inches
	double height = (feet * 12) + inches;

	// Promts age input and assigns it to variable age
	cout << "Enter your age in years: ";
	int age;
	cin >> age;

	// Determines wether to call the functions bmrMen or bmrWomen and displays
	// the amount of doughnuts one can eat based on their calculated BMR
	if (gender == 'm')
		cout << "You can consume " << static_cast<int>(bmrMen(weight, height, age)) / doughnut << " doughnuts" << endl;
	else if (gender == 'w')
		cout << "You can consume " << static_cast<int>(bmrWomen(weight, height, age)) / doughnut << " doughnuts" << endl;

}

// Calculates and returns the BMR for a male using values passed in
// from the weight, height, and age values in main(), using them as
// variables w, h, and a
double bmrMen(double w, double h, int a) {

	return 66 + (6.3 * w) + (12.9 * h) - (6.8 * a);

}

// Calculates and returns the BMR for a female using values passed in
// from the weight, height, and age values in main(), using them as
// variables w, h, and a
double bmrWomen(double w, double h, int a) {

	return 655 + (4.3 * w) + (4.7 * h) - (4.7 * a);

}
