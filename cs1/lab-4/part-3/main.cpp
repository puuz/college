/**
* @file main.cpp
*
* @brief Reads error code and outputs error message.
*
* Reads in an error code and outputs the corresponding error
* message by using a switch statement to know which error
* message should be sent out from the error code.
*
* @author Sam Farris
* @date 10/20/2021
*/

/**
* Six Tests
*
* Enter the error code: 0
* Error Code: 0
* Unknown Error
*
* Enter the error code: -1
* Error Code: -1
* File Not Found
*
* Enter the error code: -2
* Error Code: -2
* Invalid File Format
*
* Enter the error code: -4
* Error Code: -4
* Out of Memory
*
* Enter the error code: -8
* Error Code: -8
* Invalid Operation
*
* Enter the error code: ok
* Error Code: 0
* Unknown Error
*/

#include <iostream>

using namespace std;

/**
* @brief Reads error code and outputs error message.
*
* Reads in an error code and outputs the corresponding error
* message by using a switch statement to know which error
* message should be sent out from the error code.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() {
	int errorCode;

	//prompt for and read in error code
	cout << "Enter the error code: ";
	cin >> errorCode;

	//switch statement to output the right error message
	switch (errorCode) {
	case -1:
		cout << "\nError Code: " << errorCode
			<< "\nFile Not Found\n";
		break;
	case -2:
		cout << "\nError Code: " << errorCode
			<< "\nInvalid File Format\n";
		break;
	case -4:
		cout << "\nError Code: " << errorCode
			<< "\nOut of Memory\n";
		break;
	case -8:
		cout << "\nError Code: " << errorCode
			<< "\nInvalid Operation\n";
		break;
	default:
		cout << "\nError Code: " << errorCode
			<< "\nUnknown Error\n";
		break;
	}

	return 0;
}