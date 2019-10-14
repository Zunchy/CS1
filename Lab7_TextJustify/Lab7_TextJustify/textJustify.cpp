// Program that uses line justification rules to alter every line of text in a file
// and writes the justified text to another file
// Zachary Waterbury
// 10/17/2018

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using std::cout; using std::cin; using std::endl;
using std::string;
using std::ifstream; using std::ofstream;

void puncSpace(string& line);	// Inserts an extra space after every punctuation mark.
void rndSpace(string& line);	// Inserts random whitespace between words unitll line is 75 characters in length

const int lineLength = 75;		// The length that the specified line must be
const int justLimit = 40;		// The length a line must be in order to be justified


int main() {

	// inputing file name
	cout << "Input file name to print: ";
	string fileName;
	cin >> fileName;

	// opening files
	ifstream fin(fileName);
	ofstream fout("justified.txt");

	string line;

	// Reads in every line from the file
	while (getline(fin, line)) {
	
		// Checks is line is able to be justified
		if (line.size() >= justLimit)
			puncSpace(line);
		else
			cout << "The line is not long enough to be justified." << endl;

		// Checks if line needs random whitespace until it is 75 characters
		if (line.size() != lineLength && line.size() >= justLimit)
			rndSpace(line);

		// Writes the justified line to the output file
		fout << line << endl;

	}
		
	fin.close();
	fout.close();

}

void puncSpace(string& line) {

	// Variable to hold the index of an occurence of a punctuation mark
	int pos = line.find_first_of(".,!?;");

	// Loops until pos is less than one less than the length of the line
		// This is to exclude cases where the last character is a punctuation mark
	while (pos < line.size() - 1) {

		// Inserts a space at each punctuation mark
		line.insert(pos + 1, 1, ' ');

		// Stops if line reaches 75 characters in length
		if (line.size() == lineLength)
			break;

		// Locates nect occurence of a punctuation mark
		pos = line.find_first_of(".,!?;", pos + 1);

	}

}

void rndSpace(string& line) {

	// Initializes random number generator
	srand(time(nullptr));

	int pos = 0;	// Holds position of the beginning of words and the end of words

	// Loops until the length of the line is 75 characters
	while (line.size() != lineLength) {

		// Locates the end of a word
		pos = line.find_first_of(' ', pos);

		// When the end of the line is reached, the search starts from the beginning of the line
		if (pos == -1) {
			pos = 0;
			pos = line.find_first_of(' ', pos);
		}

		// Generates a random boolean value to determine if whitespace is added
		if (rand() % 2 == 0)
			line.insert(pos + 1, 1, ' ');

		// Locates the beginning of a word
		pos = line.find_first_not_of(" ", pos + 1);

	}


}