/**
* @file main.cpp
*
* @brief Reads pay stub information and outputs net pay.
*
* Reads in the employee's pay stub information and calculates the
* net pay for an employee's pay stub then outputs what was read in
* and calculated.
*
* @author Sam Farris
* @date 10/6/2021
*/

/**
* Pseudocode Algorithm
*
* Prompt “Enter the employee's name: “
* Read employee
* Prompt “Enter the yearly salary: “
* Read yearlySalary
* Prompt “Enter the number of pay periods: “
* Read numOfPayPeriods
* Prompt “Enter the number of exemptions: “
* Read numOfExemptions
* Prompt “Enter the yearly cost of the health insurance: “
* Read yearlyInsurance
*
* yearlySalary = |yearlySalary|
* If (numOfPayPeriods < 1)
*	numOfPayPeriods = 1
* If (numOfExemptions < 0)
*	numOfExemptions = 0
* yearlyInsurance = |yearlyInsurance|
*
* FIFCA_RATE = 0.062;
* WITHOLDING_RATE = 0.115;
* EXEMPTIONS_REDUCE = 15;
*
* payPeriodTotal = yearlySalary / numOfPayPeriods
* fifcaAmount = payPeriodTotal(FIFCA_RATE)
* witholdingAmount = payPeriodTotal(WITHOLDING_RATE) - numOfExemptions
* insuranceAmount = yearlyInsurance / numOfPayPeriods
* netTotal = payPeriodTotal - fifcaAmount - witholdingAmount - insuranceAmount
*
* Print "Employee: " + employee +
*		"Yearly Salary: " + yearlySalary +
*		"Pay Periods: " + numOfPayPeriods +
*		"Exemptions: " + numOfExemptions +
*		Read in two decimal places for the rest +
*		"Yearly Insurance: " + yearlyInsurance +
*		"Pay Period: " + payPeriodTotal +
*		"FICFA: " + fifcaAmount +
*		"Witholding: " + witholdingAmount +
*		"Insurance: " + insuranceAmount +
*		"Net: " + netTotal
*/

/**
* Two Tests
*
* Enter the employee's name: Bobby Joe
* Enter the yearly salary: 63349
* Enter the number of pay periods: 12
* Enter the number of exemptions: 4
* Enter the yearly cost of the health insurance: 2789.10
*
* Employee:           Bobby Joe
* Yearly Salary:      63349
* Pay Periods:        12
* Exemptions:         4
* Yearly Insurance:   2789.10
* Pay Period:         5279.08
* FICFA:              327.30
* Witholding:         547.09
* Insurance:          232.42
* Net:                4172.26
*
* Enter the employee's name: 0ath! Row
* Enter the yearly salary: 40023
* Enter the number of pay periods: -10
* Enter the number of exemptions: -2
* Enter the yearly cost of the health insurance: 1802.0
*
* Employee:           0ath! Row
* Yearly Salary:      40023
* Pay Periods:        1
* Exemptions:         0
* Yearly Insurance:   1802.00
* Pay Period:         40023.00
* FICFA:              2481.43
* Witholding:         4602.65
* Insurance:          1802.00
* Net:                31136.93
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

/**
* @brief Reads pay stub information and outputs net pay.
*
* Reads in the employee's pay stub information and calculates the
* net pay for an employee's pay stub then outputs what was read in
* and calculated.
*
* @return 0 if sucessful or non-0 if there's an error.
*/

int main() {
	string employee;
	int yearlySalary;
	int numOfPayPeriods;
	int numOfExemptions;
	double yearlyInsurance;

	//prompt for and read in employee, yearly salary, pay periods, exemptions, and yearly insurance
	cout << "Enter the employee's name: ";
	getline(cin, employee);
	cout << "Enter the yearly salary: ";
	cin >> yearlySalary;
	cout << "Enter the number of pay periods: ";
	cin >> numOfPayPeriods;
	cout << "Enter the number of exemptions: ";
	cin >> numOfExemptions;
	cout << "Enter the yearly cost of the health insurance: ";
	cin >> yearlyInsurance;

	//correct the yearly salary, pay periods, exemptions, and yearly salary
	yearlySalary = abs(yearlySalary);
	numOfPayPeriods = max(1, numOfPayPeriods);
	numOfExemptions = max(0, numOfExemptions);
	yearlyInsurance = abs(yearlyInsurance);

	//fifca tax rate amount
	const double FIFCA_RATE = 0.062;
	//witholding tax rate amount
	const double WITHOLDING_RATE = 0.115;
	//amount for each exemption
	const int EXEMPTIONS_REDUCE = 15;

	//compute pay period, fifca, witholding, insurance, and net with information given
	double payPeriodTotal = static_cast<double>(yearlySalary) / numOfPayPeriods;
	double fifcaAmount = payPeriodTotal * FIFCA_RATE;
	double witholdingAmount = payPeriodTotal * WITHOLDING_RATE - (numOfExemptions * EXEMPTIONS_REDUCE);
	double insuranceAmount = yearlyInsurance / numOfPayPeriods;
	double netTotal = payPeriodTotal - fifcaAmount - witholdingAmount - insuranceAmount;

	//output the results
	cout << "\n\n" << setw(20) << left << "Employee:" << employee << endl
		<< setw(20) << "Yearly Salary:" << yearlySalary << endl
		<< setw(20) << "Pay Periods:" << numOfPayPeriods << endl
		<< setw(20) << "Exemptions:" << numOfExemptions << endl
		<< setprecision(2) << fixed
		<< setw(20) << "Yearly Insurance:" << yearlyInsurance << endl
		<< setw(20) << "Pay Period:" << payPeriodTotal << endl
		<< setw(20) << "FICFA:" << fifcaAmount << endl
		<< setw(20) << "Witholding:" << witholdingAmount << endl
		<< setw(20) << "Insurance:" << insuranceAmount << endl
		<< setw(20) << "Net:" << netTotal << endl;
	return 0;
}