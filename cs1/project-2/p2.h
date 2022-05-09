#ifndef P2_H_11_17_2021
#define P2_H_11_17_2021

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/**
* Holds the PART vlaue for part timers, REGULAR for full timers,
* and EXECS for executives. These enum values are to determine
* prize levels and convert group codes to it's full text
* verison name.
*/
enum class ContestGroup { PART, REGULAR, EXECS };

/**
* @brief Opens and checks if the file name was opened.
*
* Opens the input file name and checks if it was successfully
* opened and will return the boolean based on the condition.
*
* @param fileName The input file name to open and validate.
*
* @return true or false based on the condition of file name.
*/
bool doesFileExist(string fileName);

/**
* @brief Gets group code from employeeId for correct contest group.
*
* Parses the employee Id for the group code and based on the
* group code it'll return the appropriate ContestGroup enum value.
*
* @param employeeId The employee's id that needs to be parsed.
*
* @return ContestGroup enum value based on the group code.
*
* 3 Tests
*
* employeeId: 974-eam-9093
* Result: ContestGroup::PART
*
* employeeId: 120-wku-3784
* Result: ContestGroup::REGULAR
*
* employeeId: 749-jfm-0203
* Result: ContestGroup::EXECS
*/
ContestGroup getContestGroup(string employeeId);

/**
* @brief Gives text verison of given contest group.
*
* Gives the appropriate text verison of the passed ContestGroup
* enum value using a switch statement.
*
* @param parityType The ContestGroup enum value.
*
* @return textVerison based on the ContestGroup enum value.
*
* 3 Tests
*
* parityType: ContestGroup::PART
* Result: Part-time
*
* parityType: ContestGroup::REGULAR
* Result: Full-time
*
* parityType: ContestGroup::EXECS
* Result: Executives
*/
string getContestGroupString(ContestGroup parityType);

/**
* @brief Gives prize level based on given sales and role in company.
*
* Gives the appropriate prize level based on the number of sales
* the employee has and the role in the company they have.
*
* @param numOfSales The total number of sales.
* @param parityType The ContestGroup enum value.
*
* @return prizeLevel based on the number of sales and ContestGroup
* enum value.
*
* 4 Tests
*
* numOfSales: 9
* parityType: ContestGroup::PART
* Result: 2
*
* numOfSales: 43
* parityType: ContestGroup::REGULAR
* Result: 3
*
* numOfSales: 57
* parityType: ContestGroup::EXECS
* Result: 4
*
* numOfSales: 2
* parityType: ContestGroup::EXECS
* Result: 3
*/
int getPrizeLevel(int numOfSales, ContestGroup parityType);

/**
* @brief Fixes the hard to read employee name.
*
* Fixes the decoded and hard to read employee name by removing
* the asterisks and replacing the underscores with spaces.
*
* @param employeeName The encoded and hard to read employee name.
*
* @return fixedName of the encoded to decoded name.
*
* 3 Tests
*
* employeeName: **Sa*m_Will*iam*_F*a*rris*
* Result: Sam William Farris
*
* employeeName: Tom*_Vi*nce*nt_*Van*g*u*ard
* Result: Tom Vincent Vanguard
*
* employeeName: B*ob_*J*oe_Ste**ve
* Result: Bob Joe Steve
*/
string fixName(string employeeName);

/**
* @brief Adds each number up in the input stream.
*
* Adds each number up in the given input stream and will only
* add 10 if the number read in is greater than 10.
*
* @param input the input stream for each number of sales a day.
*
* @return totalSales the number of sales for each day summed.
*
* 3 Tests
*
* input: 9034 1239 3
* Result: 23
*
* input: 1 12 0 32
* Result: 45
*
* input: 8
* Result: 8
*/
int sumSales(istream& input);

/**
* @brief Reads in line and formats the data for output.
*
* Reads in the relevant line and puts it to a string stream
* for getting the employee name and id then the number of
* sales they had each day seperated by spaces. From that
* the data will be correctly formatted and computed to assign
* the variables that are passed by reference for output.
*
* @param input the input stream for all of the employee's data.
* @param employee the employee name to pass by reference for outputting.
* @param prizeLevel the prize level to pass by reference for outputting.
* @param parityType the ContestGroup enum value to pass by reference
* for outputting.
*
* @return true or false based on being able to read in the input stream.
*
* 3 Tests
*
* input:
* Result: false
* Doesn't assign variables to anything
*
* input: A*lex_Ho*me*s_Gui*t*erre*z* 493-knm-0858 7
* Result: true
* employee = Alex Homes Guiterrez
* prizeLevel = 3
* parityType = ContestGroup::EXEC
*
* input: Y*oko*_Na*mo_**Stan*e* 939-day-9329 4 9 1 23 8
* Result: true
* employee = Yoko Namo Stane
* prizeLevel = 3
* parityTYpe = ContestGroup::REGULAR
*/
bool processSalesInfo(istream& input, string& employee, int& prizeLevel, ContestGroup& parityType);

/**
* @brief Outputs and formats the employee name, prize level, and role in company.
*
* Outputs and formats the formatted employee name, calculated prize level and
* ContestGroup enum value converted to a text variation for their role in the
* company. An asterisk will be added to prize level if it's 4.
*
* @param output the output stream for writing the employee's data.
* @param employeeName the employee name as it being readable.
* @param prizeLevel the prize level to show what prize they can have.
* @param parityType the ContestGroup enum value to convert to text verison.
*/
void printSalesInfo(ostream& output, string employeeName, int prizeLevel, ContestGroup parityType);

/**
* @brief Opens files and writes formatted data to input from output.
*
* Opens the input and output file name. If they're both opened it'll start
* writting to the output file all the data from the input file in the needed
* format and by writing a readable employee names and roles they have with the
* prize level they deserve based on the role in the company and number of sales.
*
* @param inputFileName the input file name to read the employee's data from.
* @param outputFileName the output file name to write the employee's data to.
*/
void generateContestReport(string inputFileName, string outputFileName);

/**
* @brief Prompts input and output file and starts the formatting.
*
* Prompts for the input file name. If the input file is opened it'll then
* prompt for the output file name and start reading the data from the input
* file and output the correctly formatted data and their prize level. If the
* input file doesn't open it'll prompt an error.
*
* @param input the input stream to ask for the file names.
* @param output the output stream to prompt for files and error if invalid input file.
*/
void runContest(istream& input, ostream& output);

#endif