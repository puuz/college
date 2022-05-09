/**
* @file main.cpp
*
* @brief Reads txt file with coordinates and outputs log file with distance.
*
* Reads a txt file that contains x1, y1, x2, y2 coordinates on
* each line and formats each of them on new lines to a new log file
* with a computed distance for using the distance formula with the
* provided coordinates in the txt file.
*
* @author Sam Farris
* @date 10/30/2021
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

/**
* @brief Reads txt file with coordinates and outputs log file with distance.
*
* Reads a txt file that contains x1, y1, x2, y2 coordinates on
* each line and formats each of them on new lines to a new log file
* with a computed distance for using the distance formula with the
* provided coordinates in the txt file.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() {
	ifstream inFS;
	ofstream outFS;
	string fileName;

	//prompt for a file name until one is able to be opened
	do {
		//case sensitive and format must be included
		cout << "Enter the file name: ";
		cin >> fileName;
		inFS.open(fileName);
	} while (inFS.fail());

	//prompt that it's reading the file
	cout << "Reading File ... ";

	//.txt character length (4 characters)
	const int TXT_FORMAT_LENGTH = 4;
	//file name character length minus the format length (4 characters)
	const int FILE_NAME_LENGTH = fileName.length() - TXT_FORMAT_LENGTH;
	//file format name (skipping FILE_NAME_LENGTH)
	const string FILE_FORMAT = fileName.substr(FILE_NAME_LENGTH);

	//change file format to .log for fileName string variable
	if (FILE_FORMAT != ".txt") {
		fileName += ".log";
	} else {
		fileName = fileName.substr(0, FILE_NAME_LENGTH);
		fileName += ".log";
	}

	//open new file with same name but .log as format
	outFS.open(fileName);

	//check if the log file was successfully opened
	if (outFS.fail()) {
		cout << "Couldn't open the log file.";
		return 1;
	}

	int x1;
	int y1;
	int x2;
	int y2;
	double distance;

	//read in coordinates from the file inputted (primary reading)
	inFS >> x1 >> y1 >> x2 >> y2;

	//check if the txt file was able to read the 4 coordinates.
	if (inFS.fail()) {
		cout << "Couldn't read in the txt file.";
		return 1;
	}

	//loop to keep reading the file inputted until nothing is left
	while (!inFS.eof()) {
		//compute the distance with the coordinates
		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		//format and output results
		outFS << "(" << x1 << ", " << y1 << ") : (" << x2 << ", " << y2 << ") -> "
			<< fixed << setprecision(3) << distance << endl;

		//same as the primary reading
		inFS >> x1 >> y1 >> x2 >> y2;
	}

	//prompt that it's done
	cout << "Done" << endl;

	//close both opened files
	outFS.close();
	inFS.close();

	return 0;
}