#ifndef LAB7_H_11_22_2021
#define LAB7_H_11_22_2021

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

/**
* @brief Computes the average of the values in the array.
*
* Computes the average of the values in the array by looping the
* array to get the sum of all the values and dividing that with
* the number of values in the array. It'll return 0 if number of
* values is 0.
*
* @param values The array of all the read in values.
* @param numOfValues The number of values in the array.
*
* @return average The average of the values in the array.
*
* 3 Tests
*
* values: { 393.2, 21.4904, 3, 3902.1 }
* numOfValues: 4
* Result: 1079.95
*
* values: {}
* numOfValues: 0
* Result: 0
*
* values: { 3012.2, 493.2, -49.1, 49034.3, 32, 10.390, -304, 12.930 }
* numOfValues: 8
* Result: 6530.24
*/

double getAverage(double values[], int numOfValues);

/**
* @brief Finds the largest value in the array.
*
* Finds the largest value in the array by looping the array to
* check if the current max value is less than the current array
* value. It'll return 0 if number of values is 0.
*
* @param values The array of all the read in values.
* @param numOfValues The number of values in the array.
*
* @return max The largest value in the array.
*
* 3 Tests
*
* values: { 9023.94, 493.4, 3, 9, 430, 92321.4, 434.4 }
* numOfValues: 7
* Result: 92321.4
*
* values: { 320.32, 60.5, 105 }
* numOfValues: 3
* Result: 320.32
*
* values: {}
* numOfValues: 0
* Result: 0
*/

double getMaximum(double values[], int numOfValues);

/**
* @brief Updates the values that are lower then the stable price.
*
* Updates the values in the array that are lower then the stable
* price with an add on of the percent markup for that current
* value. It'll then return the number of values that were updated.
*
* @param values The array of all the read in values.
* @param numOfValues The number of values in the array.
* @param percentMarkup The percent to markup on low values.
*
* @return numOfUpdated The number of values that were updated.
*
* 3 Tests
*
* values: {}
* numOfValues: 0
* percentMarkup: 0.25
* Result: 0
* values = {}
*
* values: { 1.2, 643.5, 32.9, 490.2 }
* numOfValues: 4
* percentMarkup: .4
* Result: 2
* values = { 1.68, 643.50, 46.06, 490.20 }
*
* values: { 89.394, 4, 434.4, 49, 13.23 }
* numOfValues: 5
* percentMarkup: .10
* Result: 4
* values = { 98.33, 4.40, 434.40, 53.90, 14.55 }
*/

int updatePrices(double values[], int numOfValues, double percentMarkup);

/**
* @brief Converts an array of values into a formatted string.
*
* Converts an array of values into a fomatted string that starts with
* "[" and ends with "]" with a comma seperating each number inbetween
* the array and not numbers by the "[" or "]".
*
* @param values The array of all the read in values.
* @param numOfValues The number of values in the array.
*
* @return stringOfValues The array of values as [] in a string.
*
* 3 Tests
*
* values: { 890.8, 785.78954, -99, 347667.8, 7 }
* numOfValues: 5
* Result: [ 890.80, 785.79, -99.00, 347667.80, 7.00 ]
*
* values: {}
* numOfValues: 0
* Result: []
*
* values: { 39.20932, -439, 7902.2, -9.9890 }
* numOfValues: 4
* Result: [ 39.21, -439.00, 7902.20, -9.99 ]
*/

std::string arrayToString(double values[], int numOfValues);

/**
* @brief Inserts the new value into the array in the appropriate place.
*
* Inserts the new value into the array in the appropriate place by looping
* backwards and checking if the current index is greater than 0 and next
* value is greater than the new inserting value. It'll return the max
* number of values if it's less than the number of values.
*
* @param values The array of all the read in values.
* @param numOfValues The number of values in the array.
* @param maxOfValues The max number of values to be in the array.
* @param insertedValue The new value to insert into the array.
*
* @return numOfValues The new number of values after the inserted value.
*/

int insertValue(double values[], int numOfValues, int maxOfValues, double insertedValue);

/**
* @brief Reads in values and inserts them into the array accordingly.
*
* Reads in values and inserts them into the array in ascending order
* until the number of values reaches the max number of values or
* a read in value is not a double.
*
* @param input The input stream to read values from.
* @param values The array of all the read in values.
* @param maxOfNums The max number of values to be in the array.
*
* @return numOfValues The new number of values after the inserting.
*/

int readData(std::istream & input, double values[], int maxOfNums);

/**
* @brief Reads percent markup and array values then outputs array and computed results.
*
* Reads in the percent markup and the array values until 25 values have been entered
* or there has been a non double inputted. From that data it'll sort the array in
* asscending order, get the average, get the highest value in it, and the numbers that
* updated from the percent markup based on the value of the number. From those new values
* it'll output them in format.
*
* @param input The input stream to read values from.
* @param output The output stream to prompt text to.
*
* 3 Tests
*
* input: std::cin
* output: std::cout
* Percent Markup: yo
* Result: Error: Couldn't read in percent markup!
*
* input: std::cin
* output: std::cout
* Percent Markup: .35
* values: { 8.32, 390.4, 2, 90.24, 403.4903490, 49, f }
* Result: [2.70, 11.23, 66.15, 121.82, 390.40, 403.49]
* Average:	403.49
* Max:		165.97
* Percent:	35.0%
* Updated:	4
*
* input: std::cin
* output: std::cout
* Percent Markup: .230943
* values: { 9430.23, 323.3, 48, 4903.2903021312, 12, 87.092, ok }
* Result: [14.77, 59.09, 107.21, 323.30, 4903.29, 9430.23]
* Average:	9430.23
* Max:		2472.98
* Percent:	23.1%
* Updated:	3
*/

void processPrices(std::istream & input, std::ostream & output);

#endif