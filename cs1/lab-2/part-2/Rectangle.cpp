/**
* @file Rectangle.cpp
*
* @brief Computes the area and perimter of a rectangle.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
* @author turners
* @date 2016-09-12
*/
#include <iostream>

using std::cout;
using std::cin;
/**
* @brief Computes the area and perimter of a rectangle.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
* @return 0 is sucessful, non-0 on error
*
* Input:
*	Length: 7
*	Width: 3
* Expected:
*	Perimeter: 20
*	Area: 21
* 
* Input:
*	Length: -5
*	Width: 2
* Expected:
*	Perimeter: -6
*	Area: -10
*
* Input:
*	Length: 5.5
*	Width: 2.8
* Expected:
*	Perimeter: 16.6
*	Area: 15.4
*/
int main() {
	double length;
	double width;
	double perimeter;
	double area;

	//prompt for and read in length and width
	cout << "Enter the length of the rectangle: ";
	cin >> length;

	cout << "Enter the width of the rectangle: ";
	cin >> width;

	//compute perimeter and area
	perimeter = 2 * (length + width);
	area = length * width;

	//output results
	cout << "For a " << length << " x " << width
		<< " rectangle, the perimeter is " << perimeter
		<< " and the area is " << area << ".\n";

	return 0;
}