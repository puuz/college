/**
* @file main.cpp
*
* @brief Reads percent markup and array values then outputs array and computed results.
*
* Reads in the percent markup and the array values until 25 values have been entered
* or there has been a non double inputted. From that data it'll sort the array in
* asscending order, get the average, get the highest value in it, and the numbers that
* updated from the percent markup based on the value of the number. From those new values
* it'll output them in format.
*
* @author Sam Farris
* @date 11/23/2021
*/

#include "lab7.h"

/**
* @brief Reads percent markup and array values then outputs array and computed results.
*
* Reads in the percent markup and the array values until 25 values have been entered
* or there has been a non double inputted. From that data it'll sort the array in
* asscending order, get the average, get the highest value in it, and the numbers that
* updated from the percent markup based on the value of the number. From those new values
* it'll output them in format.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() { processPrices(std::cin, std::cout); }

//Doxygen comments and tests are in lab7.h file

double getAverage(double values[], int numOfValues) {
	//return 0 if there's 0 values
	if (numOfValues == 0) {
		return 0;
	}
	double sum = 0;
	//loop the array and add on each value to the sum
	for (int i = 0; i < numOfValues; i++) {
		sum += values[i];
	}
	//return the average by dividing the sum and number of values that were summed
	return sum / numOfValues;
}

double getMaximum(double values[], int numOfValues) {
	//return 0 if there's 0 values
	if (numOfValues == 0) {
		return 0;
	}
	//assign max to the first value in the array
	double max = values[0];
	//loop over the array, checking if current array value is greater than the current max value
	for (int i = 1; i <= numOfValues; i++) {
		if (max < values[i]) {
			max = values[i];
		}
	}
	return max;
}

int updatePrices(double values[], int numOfValues, double percentMarkup) {
	//anything less than stable price needs a percent markup
	const double STABLE_PRICE = 175.00;
	int numOfUpdated = 0;
	//loop the array and add the percent markup if it's lower than stable price
	for (int i = 0; i < numOfValues; i++) {
		if (values[i] < STABLE_PRICE) {
			values[i] += values[i] * percentMarkup;
			numOfUpdated++;
		}
	}
	//return number of values updated with percent markup
	return numOfUpdated;
}

std::string arrayToString(double values[], int numOfValues) {
	//start the string array with "["
	std::string stringOfValues = "[";
	//loop the array and create a string stream for the value
	for (int i = 0; i < numOfValues; i++) {
		std::stringstream valueSS;
		//string stream to round to 2 decimal places
		valueSS << std::fixed << std::setprecision(2) << values[i];
		//if the value isn't the last value in the array add a comma
		if (i + 1 != numOfValues) {
			valueSS << ", ";
		}
		//add the value from the string stream to the string array
		stringOfValues += valueSS.str();
	}
	//finish the string array with "]"
	stringOfValues += "]";
	return stringOfValues;
}

int insertValue(double values[], int numOfValues, int maxOfValues, double insertedValue) {
	//if number of values is greater than or equal to max then return max
	if (numOfValues >= maxOfValues) {
		return maxOfValues;
	}
	int i;
	//loop the array backwards while index is greater than 0 and value of next index is greater than new value
	for (i = numOfValues; i > 0 && values[i - 1] > insertedValue; i--) {
		//assign the current position with the next position
		values[i] = values[i - 1];
	}
	//assign the new value in the correct position based on the expression in the for loop
	values[i] = insertedValue;
	//return number of values including the new value
	return numOfValues + 1;
}

int readData(std::istream & input, double values[], int maxOfNums) {
	int numOfValues = 0;
	double readValue;
	//loop the array the max number times
	for (int i = 0; i < maxOfNums; i++) {
		//read in a double
		input >> readValue;
		//if the value wasn't a double return the number of values
		if (input.fail()) {
			return numOfValues;
		}
		//assign number of values to the return of insert value which correctly inserts the read value into the array
		numOfValues = insertValue(values, i, maxOfNums, readValue);
	}
	//return number of values in the array
	return numOfValues;
}

void processPrices(std::istream & input, std::ostream & output) {
	double percentMarkup;
	//read in the percent markup
	input >> percentMarkup;
	//prompt an error if the value wasn't a double
	if (input.fail()) {
		output << "Error: Couldn't read in percent markup!";
		return;
	}
	//max number of values in the array
	const int MAX_OF_NUMS = 25;
	//define the array with the max number of values
	double values[MAX_OF_NUMS];
	//read the values until it hits 25 or a non double and insert into array appropriately
	int numOfValues = readData(input, values, MAX_OF_NUMS);
	//update the prices with a percent markup that is less than stable price
	int numOfUpdated = updatePrices(values, numOfValues, percentMarkup);
	//get the largest value in the array
	double avg = getMaximum(values, numOfValues);
	//get the average of the values in the array
	double max = getAverage(values, numOfValues);
	//prompt the sorted array with computed results in format
	output << arrayToString(values, numOfValues)
		<< std::fixed << std::setprecision(2)
		<< "\nAverage:\t" << avg
		<< "\nMax:\t\t" << max
		<< std::setprecision(1)
		<< "\nPercent:\t" << percentMarkup * 100 << "%"
		<< "\nUpdated:\t" << numOfUpdated << std::endl;
}