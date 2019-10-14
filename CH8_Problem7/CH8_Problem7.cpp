/********************************************************************************

Author: Sergio M. Castillo

(Fraction calculator) Write a program that lets the user perform arithmetic
operations on fractions. Fractions are of the form a/b, in which a and b are
integers and b != 0. Your program must be menu driven, allowing the user to
select the operation (+, -, *, or /) and input the numerator and denominator
of each fraction. Furthermore, your program must consist of at least the
following functions:

a. Function menu: This function informs the user about the program’s
   purpose, explains how to enter data, and allows the user to select the
   operation.
b. Function addFractions: This function takes as input four integers
   representing the numerators and denominators of two fractions, adds the
   fractions, and returns the numerator and denominator of the result.
   (Notice that this function has a total of six parameters.)
c. Function subtractFractions: This function takes as input four
   integers representing the numerators and denominators of two fractions,
   subtracts the fractions, and returns the numerator and denominator of
   the result. (Notice that this function has a total of six parameters.)
d. Function multiplyFractions: This function takes as input four
   integers representing the numerators and denominators of two fractions,
   multiplies the fractions, and returns the numerators and denominators of
   the result. (Notice that this function has a total of six parameters.)
e. Function divideFractions: This function takes as input four integers
   representing the numerators and denominators of two fractions, divides
   the fractions, and returns the numerator and denominator of the result.
   (Notice that this function has a total of six parameters.)

   Some sample outputs are:
   
   3 / 4 + 2 / 5 = 23 / 20
   2 / 3 * 3 / 5 = 6 / 15

   Your answer need not be in the lowest terms.

*********************************************************************************/


#include <iostream>

using namespace std;

void functionMenu(); // displays main menu
void getFractions(int& numOne, int& denomOne, int& numTwo, int& denomTwo); // gets fraction inputs from user
void addFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns); // adds fractions
void subtractFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns); // subtracts fractions
void multiplyFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns); // multiplies fractions
void divideFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns); // divides fractions
void reduceFractions(int& numAns, int& denomAns); // reduces fractions
void displayResult(int choice, int numOne, int denomOne, int numTwo, int denomTwo, int numAns, int denomAns); // displays results of each task

int main()
{
	//Declare variables
	int choice, numOne, denomOne, numTwo, denomTwo;

	//variables for answers to fraction calculations
	int numAns = 0;
	int denomAns = 0;

	do
	{
		system("cls");
		functionMenu();
		cin >> choice;
		cin.clear();

		cout << endl << endl;

		switch (choice)
		{
		case 1: // adds two fractions
			system("cls");
			getFractions(numOne, denomOne, numTwo, denomTwo);
			addFractions(numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			displayResult(choice, numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			system("pause");
			break;
		case 2: // subtracts two fractions
			system("cls");
			getFractions(numOne, denomOne, numTwo, denomTwo);
			subtractFractions(numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			displayResult(choice, numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			system("pause");
			break;
		case 3: // multiplies two fractions
			system("cls");
			getFractions(numOne, denomOne, numTwo, denomTwo);
			multiplyFractions(numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			displayResult(choice, numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			system("pause");
			break;
		case 4: // divides two fractions
			system("cls");
			getFractions(numOne, denomOne, numTwo, denomTwo);
			divideFractions(numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			displayResult(choice, numOne, denomOne, numTwo, denomTwo, numAns, denomAns);
			system("pause");
			break;
		case 5: // exits program
			return 1;
		default: // the default result that is displayed if a user enters a number that does not match any of the cases
			cout << "Invalid input, please press any key to try again." << endl << endl;
			system("pause");
			break;
		}
	} 
	while (choice != 5);

	system("pause");
	return 0;
}

//user definied function to show the menu screen
void functionMenu()
{
	cout << "This program allows users to perform arithmetic operations on fractions." << endl
		<< "Fractions are in the form of a/b, and a and b must be integers." << endl
		<< "b should not equal 0." << endl << endl
		<< "Enter the menu number of the operation you would like to perform." << endl << endl
		<< "Menu: " << endl
		<< "\t1.\tAddition (two fractions)" << endl
		<< "\t2.\tSubtraction (two fractions)" << endl
		<< "\t3.\tMultiply (two fractions)" << endl
		<< "\t4.\tDivide (two fractions)" << endl
		<< "\t5.\tExit" << endl << endl
		<< "Your choice: ";
}

//user defined function to get the fractions
void getFractions(int& numOne, int& denomOne, int& numTwo, int& denomTwo)
{
	char d; // dummy variable for '/' in fraction entered by user.

	cout << "Fractions should be entered to include the '/'." << endl << endl
		<< "Enter the first fraction: ";
	cin >> numOne >> d >> denomOne;
	cin.clear();
	cout << "Enter the second fraction: ";
	cin >> numTwo >> d >> denomTwo;
	cin.clear();
	cout << endl;
}

//user defined function to add two fractions
void addFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns)
{
	numAns = (numOne * denomTwo) + (denomOne * numTwo);
	denomAns = denomOne * denomTwo;
	reduceFractions(numAns, denomAns);
}

//user defined function to subtract two fractions
void subtractFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns)
{
	numAns = (numOne * denomTwo) - (denomOne * numTwo);
	denomAns = denomOne * denomTwo;
	reduceFractions(numAns, denomAns);
}

//user defined function to multiply two fractions
void multiplyFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns)
{
	numAns = numOne * numTwo;
	denomAns = denomOne * denomTwo;
	reduceFractions(numAns, denomAns);
}

//user defined function to divide two fractions
void divideFractions(int numOne, int denomOne, int numTwo, int denomTwo, int& numAns, int& denomAns)
{
	numAns = numOne * denomTwo;
	denomAns = denomOne * numTwo;
	reduceFractions(numAns, denomAns);
}

//user defined function to reduce fractions.
void reduceFractions(int& numAns, int& denomAns)
{
	for (int i = denomAns * numAns; i > 1; i--)
		if ((denomAns % i == 0) && (numAns % i == 0))
		{
			denomAns /= i;
			numAns /= i;
		}
}

//user defined function to display results based on the calculation chosen by user
void displayResult(int choice, int numOne, int denomOne, int numTwo, int denomTwo, int numAns, int denomAns)
{
	switch (choice)
	{
	case 1: // display results if addition
		cout << numOne << "/" << denomOne << " + " << numTwo << "/" << denomTwo
			<< " = " << numAns << "/" << denomAns << endl << endl;
		break;
	case 2: // display results if subtractions
		cout << numOne << "/" << denomOne << " - " << numTwo << "/" << denomTwo
			<< " = " << numAns << "/" << denomAns << endl << endl;
		break;
	case 3: // dipslay results if multiplication
		cout << numOne << "/" << denomOne << " * " << numTwo << "/" << denomTwo
			<< " = " << numAns << "/" << denomAns << endl << endl;
		break;
	case 4: // dipsplay results if division
		cout << numOne << "/" << denomOne << " / " << numTwo << "/" << denomTwo
			<< " = " << numAns << "/" << denomAns << endl << endl;
		break;
	}
}