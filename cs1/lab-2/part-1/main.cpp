/**
* @file main.cpp
*
* @brief Formats and outputs text.
*
* Formats text into a paragraph and makes
* sure everything is correctly printed out.
*
* @author Sam Farris
* @date 9/28/2021
*
*/
#include <iostream>

using std::cout;
using std::endl;
/**
* @brief Formats and outputs text.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
* @return 0 is sucessful, non-0 on error
*/
int main() {
	cout << "\tIn Windows, putting the path to a file into the code is\n"
		<< "a little difficult as each \"\\\" in the path must be escaped. So,\n"
		<< "if your file is located at C:\\temp\\data.csv, then you would need\n"
		<< "to escape it so that it looks like C:\\\\temp\\\\data.csv. It is also\n"
		<< "good practice to put \"'s around the path. This avoids problems\n"
		<< "with spaces in the file name or the path. The \"'s would have\n"
		<< "to be escaped as well."
		<< endl;
	return 0;
}