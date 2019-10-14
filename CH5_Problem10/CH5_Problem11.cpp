/**************************************************************************************
//
//	Author: Sergio Castillo
//
//    Write a program that uses do..while loops to perform the following steps:
//	  a. Prompt the user to input two integers: firstNum and secondNum
//	     (firstNum must be less than secondNum).
//	  b. Output all odd numbers between firstNum and secondNum.
//	  c. Output the sum of all even numbers between firstNum and
//       secondNum.
//	  d. Output the numbers and their squares between 1 and 10.
//	  e. Output the sum of the square of the odd numbers between firstNum
//       and secondNum.
//	  f. Output all uppercase letters.
//
**************************************************************************************/

// header files
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int firstNum, secondNum;
	int sumEvenNum = 0;
	int sumSquareOddNum = 0;
	char chCounter;
	int counter;

	//Part a
	cout << "Enter two integers ";
	cout << "(First number must be lesser than ";
	cout << "the second number you enter): " << flush;

	cin >> firstNum >> secondNum;
	cout << endl;

	if (firstNum >= secondNum)
	{
		cout << "Invalid input. first integer must be less than second integer!!!"
			 << "\nClosing Program...";
		cout << endl;
		system("pause");
		return 1;
	}
	
	//Part b
	if (firstNum % 2 == 0)
		counter = firstNum + 1;
	else
		counter = firstNum;

	cout << "Odd integers between " << firstNum << " and "
		<< secondNum << " are: " << endl;

	do
	{
		cout << counter << " ";
		counter = counter + 2;
	} 
	while (counter <= secondNum);
	
	cout << endl;

	//Part c
	if (firstNum % 2 == 0)
		counter = firstNum;
	else
		counter = firstNum + 1;

	do
	{
		sumEvenNum = sumEvenNum + counter;
		counter = counter + 2;
	}
	while (counter <= secondNum);

	cout << "Sum of even integers between " << firstNum << " and "
		<< secondNum << " = " << sumEvenNum << endl;

	//Part d
	cout << "Number: Square of Number:" << endl;
	counter = 1;
	
	do
	{
		cout << setw(6) << counter << setw(18)
			 << counter * counter << endl;
		counter++;
	}
	while (counter <= 10);

	cout << endl;

	//Part e
	if (firstNum % 2 == 0)
		counter = firstNum + 1;
	else
		counter = firstNum;

	do
	{
		sumSquareOddNum = sumSquareOddNum + counter * counter;
		counter = counter + 2;
	}
	while (counter <= secondNum);

	cout << "Sum of the squares of odd integers between "
		<< firstNum << " and " << secondNum << " = "
		<< sumSquareOddNum << endl;

	//Part f
	cout << "Upper case letters are: ";

	chCounter = 'A';	
	
	do
	{
		cout << chCounter << " ";
		chCounter++;
	}
	while (chCounter <= 'Z');

	cout << endl;

	system("pause");
	return 0;
}