/*****************************************************************************
Author: Sergio Castillo

Problem 10
Write a program that mimics a calculator. The program should take as input
two integers and the operation to be performed. It should then output the
numbers, the operator, and the result. (For division, if the denominator is
zero, output an appropriate message.) Some sample outputs follow:

3 + 4 = 7
13 * 5 = 65

Redo Exercise 9 to handle floating-point numbers. (Format your output to
two decimal places.)

*****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Declares variables
	double firstNum, secondNum, result;
	char mathOperation;

	cout << fixed << showpoint << setprecision(2);

	//Prompts user for two integers and the operation to be performed
	cout << "Calculate two numbers: ";
	cin >> firstNum >> mathOperation >> secondNum;

	switch (mathOperation) { //Starts switch
	case '+':
		result = firstNum + secondNum;
		cout << firstNum << " + " << secondNum << " = " << result;
		cout << endl;
		break;
	case '-':
		result = firstNum - secondNum;
		cout << firstNum << " - " << secondNum << " = " << result;
		cout << endl;
		break;
	case '*':
		result = firstNum * secondNum;
		cout << firstNum << " * " << secondNum << " = " << result;
		cout << endl;
		break;
	case '/':
		if (secondNum > 0) 
		{
			result = firstNum / secondNum;
			cout << firstNum << " / " << secondNum << " = " << result;
			cout << endl;
		}
		else
			cout << "Invalid entry. Denominator cannot be zero!!!!!" << endl;
		break;
	default:
		cout << "Invalid Operation given" << endl;
		cout << endl;
		break;
	} //Ends switch

	system("pause");

	return 0;
}