/**
* @file main.cpp
*
* @brief Reads input file with integers and outputs a file with *'s.
*
* Reads an input file that contains integers and for each integer it
* will output a new line with that integer following with *'s as many
* times as the current integer's value to a new output file. The input
* and output file names are prompt for and checked before reading and
* manipulating.
*
* @author Sam Farris
* @date 10/30/2021
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/**
* @brief Reads input file with integers and outputs a file with *'s.
*
* Reads an input file that contains integers and for each integer it
* will output a new line with that integer following with *'s as many
* times as the current integer's value to a new output file. The input
* and output file names are prompt for and checked before reading and
* manipulating.
* 
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() {
	ifstream inFS;
	ofstream outFS;
	string inputFileName;
	string outputFileName;

	//prompt for the input and output file names
	cout << "Enter the input file name: ";
	cin >> inputFileName;
	cout << "Enter the output file name: ";
	cin >> outputFileName;

	//open the input and output file names
	inFS.open(inputFileName);
	outFS.open(outputFileName);

	//check if the input and output files opened
	if (inFS.is_open() && outFS.is_open()) {
		int num;
		//primary reading
		inFS >> num;
		while (!inFS.eof()) {
			//output and format a new line for each number in the input file
			outFS << right << setw(5) << num << ": ";
			//for loop to output * as many times as the num's value
			for (int i = 0; i < num; i++) {
				outFS << "*";
			}
			outFS << endl;

			//same as the primary reading
			inFS >> num;
		}
		//prompt that the histogram was created successfully in the output file
		cout << "\n\nSuccess: The histogram has been created in file " << outputFileName << "." << endl;
	} else {
		//prompt whether the input or output file couldn't be opened
		if (!inFS.is_open()) {
			cout << "Error: Couldn't open the input file." << endl;
		} else {
			cout << "Error: Couldn't open the output file." << endl;
		}
	}

	//close both of the opened files
	outFS.close();
	inFS.close();

	return 0;
}