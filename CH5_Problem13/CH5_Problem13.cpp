/**************************************************************************************
//
//	Author: Sergio Castillo
//
//	The population of a town A is less than the population of town B.
//	However, the population of town A is growing faster than the population
//	of town B. Write a program that prompts the user to enter the
//	population and growth rate of each town. The program outputs after
//	how many years the population of town A will be greater than or equal
//	to the population of town B and the populations of both the towns at
//	that time. (A sample input is: Population of town A = 5000, growth
//	rate of town A = 4%, population of town B = 8000, and growth rate of
//	town B = 2%.)
//
**************************************************************************************/

#include <iostream>

using namespace std;

const double TOTAL_PERCENTAGE = 100.0;

int main()
{
	double popA, popB;	
	double growth_rateA, growth_rateB;
	int year = 1;

	cout << "Enter the population of town A: ";
	cin >> popA;
	cout << endl;

	cout << "Enter the growth rate of town A : ";
	cin >> growth_rateA;
	cout << endl;

	cout << "Enter the population of Town B (should be greater than town B): ";
	cin >> popB;
	cout << endl;

	cout << "Enter the growth rate of Town B: ";
	cin >> growth_rateB;
	cout << endl;

	if (popA < popB && growth_rateA > growth_rateB) {
		do {
			popA += (popA * (growth_rateA / TOTAL_PERCENTAGE)); // calculates population growth in one year
			popB += (popB * (growth_rateB / TOTAL_PERCENTAGE));
			year++;
		} 
		while (popA < popB);

		cout << "Town A will surpass Town B in population after " << static_cast<int>(year) << " years.\n";
		cout << "The final population of Town A is: " << static_cast<int>(popA) << ".\n";
		cout << "The final population of Town B is: " << static_cast<int>(popB) << ".\n";
	}
	else {
		cout << "Invalid Data." << endl;
	}

	system("pause");
	return 0;
}