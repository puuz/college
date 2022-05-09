/**
* @file main.cpp
*
* @brief Reads employee's encoded data then outputs it decoded.
*
* Reads in multiple employee's data on each line that has their name
* encoded then id with their group code then the number of sales seperated
* by spaces which reflects it by each day. From that the data for each employee
* will be outputted on each line with the name being decoded and formatted so
* it can be readable then the group code in its full name and their prize level
* which is reflected on the sum of the number of sales made for each day of
* that employee.
*
* @author Sam Farris
* @date 11/17/2021
*/

#include "p2.h"

/**
* @brief Reads employee's encoded data then outputs it decoded.
*
* Reads in multiple employee's data on each line that has their name
* encoded then id with their group code then the number of sales seperated
* by spaces which reflects it by each day. From that the data for each employee
* will be outputted on each line with the name being decoded and formatted so
* it can be readable then the group code in its full name and their prize level
* which is reflected on the sum of the number of sales made for each day of
* that employee.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() { runContest(cin, cout); }

//Doxygen comments and tests are in p2.h file

bool doesFileExist(string fileName) {
	ifstream inFS;
	//open passed file name as an input file
	inFS.open(fileName);
	//successfully opens return true, fails return false
	return inFS.good();
}

ContestGroup getContestGroup(string employeeId) {
	//parse the passed employeeId for the group code
	string groupCode = employeeId.substr(4, 3);
	//return the correct contest group enum value based on parsed group code
	if (groupCode == "eam" || groupCode == "epm" || groupCode == "lpm") {
		return ContestGroup::PART;
	}
	else if (groupCode == "day" || groupCode == "wke") {
		return ContestGroup::REGULAR;
	}
	else {
		return ContestGroup::EXECS;
	}
}

string getContestGroupString(ContestGroup parityType) {
	string textVersion;
	//return the correct text verison based on the passed contest group enum value
	switch (parityType) {
	case ContestGroup::PART:
		textVersion = "Part-time";
		break;
	case ContestGroup::REGULAR:
		textVersion = "Full-time";
		break;
	case ContestGroup::EXECS:
		textVersion = "Executives";
		break;
	}
	return textVersion;
}

int getPrizeLevel(int numOfSales, ContestGroup parityType) {
	//give a 25% add on to part times number of sales which is rounded down
	if (parityType == ContestGroup::PART) {
		numOfSales += numOfSales * 0.25;
	}
	int prizeSize;
	//find appropriate prize size based on number of sales
	if (numOfSales < 10) {
		prizeSize = 1;
	}
	else if (numOfSales < 20) {
		prizeSize = 2;
	}
	else if (numOfSales < 45) {
		prizeSize = 3;
	}
	else {
		prizeSize = 4;
	}
	//boost executive's prize size by 2
	if (parityType == ContestGroup::EXECS) {
		prizeSize += 2;
	}
	//dont allow anyone to have a prize size higher than 4
	if (prizeSize > 4) {
		prizeSize = 4;
	}
	return prizeSize;
}

string fixName(string employeeName) {
	string fixedName;
	//for loop to decode the employee's encoded name
	for (int i = 0; i < employeeName.length(); i++) {
		//if the character is an asterisk dont do anything
		if (employeeName.at(i) == '*') {
			continue;
			//if the character is an underscore add a space instead
		}
		else if (employeeName.at(i) == '_') {
			fixedName += " ";
			//otherwise add the character to the string
		}
		else {
			fixedName += employeeName.at(i);
		}
	}
	return fixedName;
}

int sumSales(istream& input) {
	int currentSale;
	int totalSales = 0;
	//primary reading to get the first number in the istream of number of sales as an integer
	input >> currentSale;
	//while loop to read each sale number for each day and sum by given integer
	while (input.good()) {
		//add only 10 if the sale number is greater than 10
		if (currentSale > 10) {
			totalSales += 10;
			//otherwise add
		}
		else {
			totalSales += currentSale;
		}
		//same as primary reading
		input >> currentSale;
	}
	return totalSales;
}

bool processSalesInfo(istream& input, string& employee, int& prizeLevel, ContestGroup& parityType) {
	string line;
	stringstream lineStream;
	//get the employee's line of data, includes decoded name, id, and sales
	getline(input, line);
	//pass the line to the string stream
	lineStream << line;
	string employeeName;
	string employeeId;
	//get the employee name and id out of string stream leaving the sales
	lineStream >> employeeName >> employeeId;
	//make sure there was data to read for future output
	if (lineStream.fail()) {
		return false;
	}
	//get the total of each number of sales which is what is left of the string stream
	int totalSales = sumSales(lineStream);
	//parse the employeeId for the group code to get the correct contest group enum value
	parityType = getContestGroup(employeeId);
	//get the appropriate prize level based on number of sales and parity type 
	prizeLevel = getPrizeLevel(totalSales, parityType);
	//decode the encoded employee name
	employee = fixName(employeeName);
	return true;
}

void printSalesInfo(ostream& output, string employeeName, int prizeLevel, ContestGroup parityType) {
	//output and format the passed employee name, parity type as text verison, and prize level
	output << left << setw(40) << employeeName << " "
		<< left << setw(12) << getContestGroupString(parityType) << " "
		<< right << setw(4) << prizeLevel;
	//if the prize level is 4 add an asterisk to the output stream
	if (prizeLevel == 4) {
		output << "*";
	}
	output << endl;
	return;
}

void generateContestReport(string inputFileName, string outputFileName) {
	ifstream inFS;
	ofstream outFS;
	//open the passed input and output file names;
	inFS.open(inputFileName);
	outFS.open(outputFileName);
	//if they're successfully opened start to output the data to the output file from the input file
	if (inFS.good() && outFS.good()) {
		//title for the output file of the contest
		const string TITLE = "Sales Rewards";
		//output the title
		outFS << TITLE << endl << endl;
		//define to pass by reference in process and use in print
		string employee;
		int prizeLevel;
		ContestGroup parityType;
		//while loop until the everything has been read in from the input file
		while (!inFS.eof()) {
			//if successfully read in data on the line reassign the variables and start the output
			if (processSalesInfo(inFS, employee, prizeLevel, parityType)) {
				//output the new data from process
				printSalesInfo(outFS, employee, prizeLevel, parityType);
			}
		}
		//close the opened input and output files
		inFS.close();
		outFS.close();
	}
	return;
}

void runContest(istream& input, ostream& output) {
	string inputFileName;
	//prompt and read in the input file name
	output << "Enter the input file name: ";
	input >> inputFileName;
	//open the file and check if it was successfully opened
	if (doesFileExist(inputFileName)) {
		string outputFileName;
		//prompt and read in the output file name
		output << "Enter the output file name: ";
		input >> outputFileName;
		//read in each employee's data and output the data correctly formatted
		generateContestReport(inputFileName, outputFileName);
	}
	else {
		//prompt the input file name couldn't be opened
		output << "There was an error opening the input file name: " << inputFileName;
	}
}