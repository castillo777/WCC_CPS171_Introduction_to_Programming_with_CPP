/*************************************************************************

 Author: Sergio Castillo

 Rewrite the program in Programming Exercise 15 of Chapter 4 (cell phone
 company) so that it uses the following functions to calculate the billing
 amount. (In this programming exercise, do not output the number of
 minutes during which the service is used.)
 
 a. regularBill: This function calculates and returns the billing amount
	for regular service.
 b. premiumBill: This function calculates and returns the billing amount
	for premium service.

*************************************************************************/

// Header file
#include <iostream>
#include <iomanip>

using namespace std;

// Named constants
const double REGULAR_ACCOUNT_FEE = 10.00;
const double REGULAR_RATE = 0.20;
const double PREMIUM_ACCOUNT_FEE = 25.00;
const double PREMIUM_DAY_RATE = 0.10;
const double PREMIUM_NIGHT_RATE = 0.05;
const double FREE_MINUTES_ON_REG_SERVICE= 50.0;
const double FREE_DAY_MINUTES_ON_PREM_SERVICE = 75.0;
const double FREE_NIGHT_MINUTES_ON_PREM_SERVICE = 100.0;

// Prototyping functions
double regularBillCalculations();
double premiumBillCalculations();

void main()
{
	int accountNumber;
	double totalBill;
	char serviceCode;

	cout << fixed << showpoint << setprecision(2);

	cout << "Please enter an account number: ";
	cin >> accountNumber;
	cout << endl;

	cout << "Please enter a service code : ";
	cin >> serviceCode;
	cout << endl;

	switch (serviceCode) 
	{
	case 'r':
	case 'R':
		totalBill = regularBillCalculations();
		cout << "Account Number: " << accountNumber
			 << endl;
		cout << "Type of Service: RESIDENTIAL"
			 << endl;
		cout << "Amount Due: $" << totalBill 
			 << endl;
		break;
	case 'p':
	case 'P':
		totalBill = premiumBillCalculations();
		cout << "Account Number: " << accountNumber
			 << endl;
		cout << "Type of Service: PREMIUM"
			 << endl;
		cout << "Amount Due: $" << totalBill
			 << endl;
		break;
	default:
		cout << "You have entered an invalid service code!" 
			 << endl;
		break;
	}
	
	system("pause");
}

double regularBillCalculations()
{
	int regularMinutesUsed;
	double regularBillAmount;

	cout << "Please enter the number of minutes used: ";
	cin >> regularMinutesUsed;
	cout << endl;
	
	if (regularMinutesUsed > FREE_MINUTES_ON_REG_SERVICE)
		regularBillAmount = ((regularMinutesUsed - FREE_MINUTES_ON_REG_SERVICE) * REGULAR_RATE) + REGULAR_ACCOUNT_FEE;
	else
		regularBillAmount = REGULAR_ACCOUNT_FEE;

	return regularBillAmount;
}

double premiumBillCalculations()
{
	int premiumDayMinutes, premiumNightMinutes;
	double premiumBillAmount = PREMIUM_ACCOUNT_FEE;

	cout << "Please enter the number of day minutes used: ";
	cin >> premiumDayMinutes;
	cout << endl;
	
	cout << "Please enter the number of night minutes used: ";
	cin >> premiumNightMinutes;
	cout << endl;

	if (premiumDayMinutes > FREE_DAY_MINUTES_ON_PREM_SERVICE)
		premiumBillAmount += ((premiumDayMinutes - FREE_DAY_MINUTES_ON_PREM_SERVICE) * PREMIUM_DAY_RATE);

	if (premiumNightMinutes > FREE_NIGHT_MINUTES_ON_PREM_SERVICE)
		premiumBillAmount += ((premiumNightMinutes - FREE_NIGHT_MINUTES_ON_PREM_SERVICE) * PREMIUM_NIGHT_RATE);
		
	return premiumBillAmount;
}