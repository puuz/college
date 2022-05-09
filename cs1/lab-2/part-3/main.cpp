/**
* @file main.cpp
*
* @brief Converts seconds to hours.
*
* Reads in the number of seconds and converts it
* to hours with no rounding for precise output.
*
* @author Sam Farris
* @date 9/28/2021
*
*/
#include <iostream>

using std::cout;
using std::cin;
/**
* @brief Converts seconds to hours.
*
* Reads in the number of seconds and converts it
* to hours with no rounding for precise output.
*
* @return 0 is sucessful, non-0 on error
*/
int main() {
	double seconds;
	double hours;

	//number to divide with seconds to get hours
	const int NUM_SEC_IN_HR = 3600;

	//prompts user for number of seconds and reads it in
	cout << "Enter the number of seconds: ";
	cin >> seconds;

	//calculates the number of seconds to number of hours
	hours = seconds / NUM_SEC_IN_HR;

	//outputs the results
	cout << "There's " << hours << " hours in " << seconds << " seconds.";

	return 0;
}