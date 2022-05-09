/**
* @file main.cpp
*
* @brief Reads order information and outputs order's total.
*
* Reads in order information for a company and calculates the total
* for how much it costs regarding the number of units, cost per units,
* and the markup percentage cost for each unit.
*
* @author Sam Farris
* @date 10/6/2021
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
/**
* @brief Reads order information and outputs order's total.
*
* Reads in order information for a company and calculates the total
* for how much it costs regarding the number of units, cost per units,
* and the markup percentage cost for each unit.
*
* @return 0 if sucessful or non-0 if there's an error.
* 
* 4 Listed Tests
* 
* Input:
*	Company: Just some company
*	Units: 15
*	Cost Per: 3
*	Markup: 0.15
* Output:
*	Just some company
*	Units: 15
*	Cost Per: 3.00
*	Markup: 15.0%
*	Total Cost: 3627.70
* 
* Input:
*	Company: 123 Company
*	Units: 10
*	Cost Per: 4.5
*	Markup: .2
* Output:
*	123 Company
*	Units: 10
*	Cost Per: 4.50
*	Markup: 20.0%
*	Total Cost: 3629.95
* 
* Input:
*	Company: "OOL" 90
*	Units: 1284
*	Cost Per: 2.99
*	Markup: -.1
* Output:
*	"OOL" 90
*	Units: 1284
*	Cost Per: 2.99
*	Markup: -10.0%
*	Total Cost: 7031.19
* 
* Input:
*	Company: L O L
*	Units: -190
*	Cost Per: -.2
*	Markup: .8398
* Output:
*	L O L
*	Units: -190
*	Cost Per: -0.20
*	Markup: 84.0%
*	Total Cost: 3645.86
*/
int main() {
	string companyName;
	int numOfUnits;
	double costPerUnit;
	double percentMarkup;
	double computedTotal;

	//number to add to total cost for setup
	const double SETUP_COST = 3575.95;
	//number to multiply to percent markup to format decimal to percentage
	const double TO_PERCENTAGE = 100.0;

	//prompt for and read in company, units, cost per, and markup
	cout << "Enter the name of the company purchasing the units: ";
	getline(cin, companyName);

	cout << "Enter the number of units the company is buying: ";
	cin >> numOfUnits;

	cout << "Enter the cost for each unit: ";
	cin >> costPerUnit;

	cout << "Enter the percent markup for the units: ";
	cin >> percentMarkup;

	//compute total cost for the information given
	computedTotal = (numOfUnits * ((costPerUnit * percentMarkup) + costPerUnit)) + SETUP_COST;
	
	//output the results
	cout << endl << companyName << endl
		<< "Units:" << setw(15) << right << numOfUnits << endl
		<< setprecision(2) << fixed
		<< "Cost Per:" << setw(12) << right << costPerUnit << endl
		<< setprecision(1) << fixed
		<< "Markup:" << setw(13) << right << percentMarkup * TO_PERCENTAGE << "%" << endl
		<< setprecision(2) << fixed
		<< "Total Cost:" << setw(10) << right << computedTotal << endl;
}