/**
* @file main.cpp
*
* @brief Reads values and outputs result from formula.
*
* Reads in x and y values for a formula that will then
* output the result depending on what x and y was valued as.
*
* @author Sam Farris
* @date 10/6/2021
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
/**
* @brief Reads values and outputs result from formula.
*
* Reads in x and y values for a formula that will then
* output the result depending on what x and y was valued as.
*
* @return 0 if sucessful or non-0 if there's an error.
*
* 4 Listed Tests
*
* Input:
*	x: 2
*	y: 4
* Output:
*	Using x = 2 and y = 4, the result is 2.000.
*
* Input:
*	x: 0
*	y: 0
* Output:
*	Using x = 0 and y = 0, the result is 2.000.
* 
* Input:
*	x: -9
*	y: 1
* Output:
*	Using x = -9 and y = 1, the result is -0.085.
* 
* Input:
*	x: -89
*	y: -510
* Output:
*	Using x = -89 and y = -510, the result is 5.730.
*/
int main() {
	int x;
	int y;
	double result;

	//prompt for and read in x and y
	cout << "Enter x's value: ";
	cin >> x;

	cout << "Enter y's value: ";
	cin >> y;

	//compute result for x and y in the formula
	result = (x * y + 2) / (pow(x, 2) + 1);

	//output the results
	cout << endl << "Using x = " << x << " and y = " << y << ", the result is "
		<< setprecision(3) << fixed << result << "." << endl;
}