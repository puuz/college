/**
* @file main.cpp
*
* @brief Reads rectangular coordinate then outputs polar coordinate.
*
* Reads in x and y rectangular coordinate then calculates the r and theta value
* of a polar coordinate using the read in values then outputs the rectangular
* coordinate and polar coordinate with formatting.
*
* @author Sam Farris
* @date 11/9/2021
*/

#include "lab6.h"

/**
* @brief Reads rectangular coordinate then outputs polar coordinate.
*
* Reads in x and y rectangular coordinate then calculates the r and theta value
* of a polar coordinate using the read in values then outputs the rectangular
* coordinate and polar coordinate with formatting.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() { convertRectToPolar(cin, cout); }

//Doxygen comments and tests are in lab6.h file

double calculateR(double x, double y) {
	//formula to compute r with x and y rectangular coordinate
	double r = sqrt(pow(x, 2) + pow(y, 2));
	return r;
}

double radToDegrees(double angleInRadians) {
	//value of PI in math rounded to the 8th decimal
	const double PI = 3.14159265;
	//formula to compute degrees with an angle in radians
	double degrees = 180 * angleInRadians / PI;
	return degrees;
}

double calculateTheta(double x, double y) {
	//formula to get the radian with x and y rectangular coordinate
	double radian = atan2(y, x);
	//convert the radian to degrees
	double degrees = radToDegrees(radian);
	//add 360 degrees if the computed degree is a negative
	if (degrees < 0) {
		degrees += 360;
	}
	return degrees;
}

string formatPoint(double x, double y) {
	ostringstream formatOSS;
	//format the given x and y values as coordinates to the 3rd decimal
	formatOSS << setprecision(3) << fixed << "(" << x << ", " << y << ")";
	//converts the string stream buffer to a string
	string result = formatOSS.str();
	return result;
}

double getValue(istream& input, ostream& output, string prompt) {
	//prompt for the coordinate
	output << prompt;
	//store the coordinate
	double value;
	input >> value;
	return value;
}

void convertRectToPolar(istream& input, ostream& output) {
	//prompt for and store x and y rectangular coordinate
	double x = getValue(input, output, "Enter the value for x: ");
	double y = getValue(input, output, "Enter the value for y: ");

	//check if istream has failed
	if (input.fail()) {
		output << "Input has failed!" << endl;
	}
	else {
		//calculate and store r with x and y rectangular coordinates
		double r = calculateR(x, y);
		//calcualte and store theta with x and y rectangular coordinates
		double theta = calculateTheta(x, y);
		//output and format x and y rectangular coordinates and the converted polar coordinates
		output << formatPoint(x, y) << " -> " << formatPoint(r, theta);
	}
}