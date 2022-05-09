/**
* @file main.cpp
*
* @brief Reads gpa and credits then outputs class and standing.
*
* Reads in the student's gpa and number of credits completed then
* does checking for invalid inputs and finds the student's class
* level and standing status. Finally outputs what was read in
* and the student's class level and standing status.
*
* @author Sam Farris
* @date 10/20/2021
*/

/**
* Five Tests
* 
* Enter the GPA: 2.1
* Enter the number of credits completed: 56
* 
* GPA: 2.1
* Credits: 56 (Sophomore)
* In good standing
* 
* Enter the GPA: 3.62
* Enter the number of credits completed: 61
* 
* GPA: 3.6
* Credits: 61 (Junior)
* In good standing
* 
* Enter the GPA: 2.29
* Enter the number of credits completed: 95
* 
* GPA: 2.3
* Credits: 95 (Senior)
* On probation
* 
* Enter the GPA: -2
* Enter the number of credits completed: -30
* 
* GPA: 0.0
* Credits: 0 (Freshman)
* On probation
* 
* Enter the GPA: 9
* Enter the number of credits completed: 150
* 
* GPA: 0.0
* Credits: 150 (Senior)
* On probation
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
* @brief Reads gpa and credits then outputs class and standing.
*
* Reads in the student's gpa and number of credits completed then
* does checking for invalid inputs and finds the student's class
* level and standing status. Finally outputs what was read in
* and the student's class level and standing status.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() {
	double gpa;
	int numOfCredits;
	string classLevel;
	string standingStatus;

	//first high school class level
	const string CLASS_LEVEL_1 = "Freshman";
	//second high school class level
	const string CLASS_LEVEL_2 = "Sophomore";
	//third high school class level
	const string CLASS_LEVEL_3 = "Junior";
	//fourth high school class level
	const string CLASS_LEVEL_4 = "Senior";

	//good standing for given gpa on credits range
	const string GOOD_STANDING = "In good standing";
	//bad standing for given gpa on credits range
	const string BAD_STANDING = "On probation";

	//prompt for and read in gpa and number of credits
	cout << "Enter the GPA: ";
	cin >> gpa;
	cout << "Enter the number of credits completed: ";
	cin >> numOfCredits;

	//if input is bad, correct the gpa and number of credits
	if (gpa < 0.0 || gpa > 4.0) {
		gpa = 0.0;
	}
	if (numOfCredits < 0) {
		numOfCredits = 0;
	}

	//find the class level according to the number of credits
	if (numOfCredits >= 0 && numOfCredits <= 29) {
		classLevel = CLASS_LEVEL_1;
	} else if (numOfCredits >= 30 && numOfCredits <= 59) {
		classLevel = CLASS_LEVEL_2;
	} else if (numOfCredits >= 60 && numOfCredits <= 89) {
		classLevel = CLASS_LEVEL_3;
	} else {
		classLevel = CLASS_LEVEL_4;
	}
	
	//find the standing status according to the number of credits and gpa
	if (numOfCredits >= 0 && numOfCredits <= 59) {
		if (gpa >= 2.0) {
			standingStatus = GOOD_STANDING;
		} else {
			standingStatus = BAD_STANDING;
		}
	} else {
		if (gpa >= 2.5) {
			standingStatus = GOOD_STANDING;
		} else {
			standingStatus = BAD_STANDING;
		}
	}

	//output the results
	cout << endl << setprecision(1) << fixed
		<< "GPA: " << gpa << endl;
	cout << "Credits: " << numOfCredits << " (" << classLevel << ")" << endl
		<< standingStatus << endl;

	return 0;
}