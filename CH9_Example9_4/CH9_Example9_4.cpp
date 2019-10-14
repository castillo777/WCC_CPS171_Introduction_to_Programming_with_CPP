//Program to read five numbers, find their sum, and print the
//numbers in reverse order

#include <iostream>
#include <iomanip>

using namespace std;

double sumOfNumbers(double totalSum);
double printNumbersInReverse(double reverseNumbers);

void main()
{	
	double sum;
	double functionSumOfNumbers;

	cout << "Enter five numbers: ";

	functionSumOfNumbers = sumOfNumbers(sum);

	cout << endl;

	cout << "The sum of the number is: " << functionSumOfNumbers;
}

double sumOfNumbers(double totalSum)
{
	const int INDEX = 5;
	
	int counter;
	double sum = 0.00;
	double item[INDEX];

	for (counter = 0; counter < 5; counter++)
	{
		cin >> item[counter];
		sum += item[counter];
	}

	return sum;
}

double printNumbersInReverse(double reverseNumbers)
{
	const int INDEX = 5;

	int counter;
	double sum = 0.00;
	double item[INDEX];

	for (counter = 4; counter >= 0; counter--)
	{
		cin >> item[counter];
	}


}