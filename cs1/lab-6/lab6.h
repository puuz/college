#ifndef LAB6_H_11_9_2021
#define LAB6_H_11_9_2021

#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

/**
* @brief Calculates r with x and y rectangular coordinate.
*
* Calculates r using a formula with x and y rectangular
* coordinate.
*
* @param x The x coordinate for the rectangular coordinate.
* @param y The y coordinate for the rectangular coordinate.
*
* @return r value of a polar coordinate.
*
* Tests
*
* x: 18.3
* y: 12.1
* Result: 21.9386
*
* x: 18
* y: 33
* Result: 37.5899
*
* x: 5
* y: -10
* Result: 11.1803
*/
double calculateR(double x, double y);

/**
* @brief Converts an angle in radians to degrees.
*
* Converts an angle in radians to degrees using a
* formula with the angle in radians.
*
* @param angleInRadians The angle in radians.
*
* @return degree value of the angle in radians.
*
* Tests
*
* angleInRadians: 1.20218
* Result: 68.8801
*
* angleInRadians: 0.244979
* Result: 14.0362
*
* angleInRadians: -1.32582
* Result: -75.9638
*/
double radToDegrees(double angleInRadians);

/**
* @brief Calculates theta with x and y rectangular coordinate.
*
* Calculates theta using a formula with x and y rectangular
* coordinate and adds 360 degrees if degree is below 360.
*
* @param x The x coordinate for the rectangular coordinate.
* @param y The y coordinate for the rectangular coordinate.
*
* @return theta value of a polar coordinate.
*
* Tests
*
* x: 30
* y: 45
* Result: 56.3099
*
* x: 73.083
* y: -44.99
* Result: 328.383
*
* x: 37.9
* y: 71
* Result: 61.9066
*/
double calculateTheta(double x, double y);

/**
* @brief Formats the x and y values as a coordinate.
*
* Formats the x and y values as coordinate with both values
* rounded to the 3rd decimal place.
*
* @param x The x coordinate to be formated with y.
* @param y The y coordinate to be formated with x.
*
* @return the x and y values formated as a coordinate.
*
* Tests
*
* x: 83
* y: 9.74839
* Result: (83.000, 9.748)
*
* x: -39
* y: -13
* Result: (-39.000, -13.000)
*
* x: 0.3490583
* y: 4231
* Result: (0.349, 4231.000)
*/
string formatPoint(double x, double y);

/**
* @brief Prompts for and returns a value.
*
* Prompts for and returns a value with the prompt
* message used in the parameter.
*
* @param input The input type used to get the value and store it.
* @param output The output type used to prompt for the value.
* @param prompt The message that will be sent to prompt for the value.
*
* @return the value that was inputed in the prompt.
*/
double getValue(istream& input, ostream& output, string prompt);

/**
* @brief Reads rectangular coordinate then outputs polar coordinate.
*
* Reads in x and y rectangular coordinate then calculates the r and theta value
* of a polar coordinate using the read in values then outputs the rectangular
* coordinate and polar coordinate with formatting.
*
* @param input The input type used to handle the input stream.
* @param output The output type used to handle the output stream.
*
* Tests
*
* input: cin
* output: cout
* x: 82
* y: 33
* Result: (82.000, 33.000) -> (88.391, 21.922)
*
* input: inFS
* output: outFS
* x: -483
* y: -230.39
* Result: (-483.000, -230.390) -> (535.134, 205.501)
*
* input: inFS (invalid file)
* output: cout
* x: blank
* y: blank
* Result: Enter the value for x: Enter the value for y: Input has failed!
*/
void convertRectToPolar(istream& input, ostream& output);

#endif