/*****************************************************************************************
Author: Sergio Castillo

Write a program that calculates and prints the monthly paycheck for an
employee. The net pay is calculated after taking the following deductions:

Federal Income Tax : 15%
State Tax : 3.5%
Social Security Tax : 5.75%
Medicare / Medicaid Tax : 2.75%
Pension Plan : 5%
Health Insurance : $75.00

Your program should prompt the user to input the gross amount and the
employee name.The output will be stored in a file. Format your output to
have two decimal places. A sample output follows:

Bill Robinson
Gross Amount : ............ $3575.00
Federal Tax : ............. $536.25
State Tax : ............... $125.13
Social Security Tax : ..... $205.56
Medicare / Medicaid Tax : ...$98.31
Pension Plan : ............ $178.75
Health Insurance : ........ $75.00
Net Pay : ................. $2356.00

Note that the first column is left-justified, and the right column is right-justified.

******************************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const double FEDERAL_INCOME_TAX = 0.15;
const double STATE_TAX = 0.035;
const double SOCIAL_SECURITY_TAX = 0.0575;
const double MEDICAID_MEDICARE_TAX = 0.0275;
const double PENSION_PLAN = 0.05;
const double HEALTH_INSURANCE = 75.00;

int main()
{
	string employeeName;

	double grossAmount, federalTax, stateTax, socialSecurityTax, medicareMedicaidTax, pensionPlan, healthInsurance, netPay;

	ofstream outFile;

	outFile.open("MP2-Ch3_Ex6Data_output.txt");

	outFile << fixed << showpoint << setprecision(2);

	cout << "Enter name of employee: ";
		getline(cin, employeeName);
		cout << endl;

	cout << "Enter the gross amount: $";
		cin >> grossAmount;
		cout << endl;
	
	federalTax = grossAmount * FEDERAL_INCOME_TAX;
	stateTax = grossAmount * STATE_TAX;
	socialSecurityTax = grossAmount * SOCIAL_SECURITY_TAX;
	medicareMedicaidTax = grossAmount * MEDICAID_MEDICARE_TAX;
	pensionPlan = grossAmount * PENSION_PLAN;
	healthInsurance = HEALTH_INSURANCE;
	netPay = grossAmount - (federalTax + stateTax + socialSecurityTax + medicareMedicaidTax + pensionPlan + healthInsurance);

	outFile << employeeName << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Gross Amount: "
		<< setfill(' ') << right << " $"
		<< setw(7) << grossAmount << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Federal Tax: "
		<< setfill(' ') << right << " $"
		<< setw(7) << federalTax << endl;

	outFile << setfill('.') << left << setw(26)
		<< "State Tax: "
		<< setfill(' ') << right << " $"
		<< setw(7) << stateTax << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Social Security Tax: "
		<< setfill(' ') << right << " $"
		<< setw(7) << socialSecurityTax << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Medicare/Medicade Tax: "
		<< setfill(' ') << right << " $"
		<< setw(7) << medicareMedicaidTax << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Pension Plan: "
		<< setfill(' ') << right << " $"
		<< setw(7) << pensionPlan << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Health Insurance: "
		<< setfill(' ') << right << " $"
		<< setw(7) << healthInsurance << endl;

	outFile << setfill('.') << left << setw(26)
		<< "Net Pay: "
		<< setfill(' ') << right << " $"
		<< setw(7) << netPay << endl;

	outFile.close();

	system("pause");

	return 0;

}