/**************************************************************************************
//
//	Author: Sergio Castillo
//
//  Write a program that prompts the user to input a positive integer. It should then
//	output a message indicating whether the number is a prime number. (Note: An
//	even number is prime if it is 2. An odd integer is prime if it is not divisible by
//	any odd integer less than or equal to the square root of the number.)
//
**************************************************************************************/

// header files
#include <iostream>

using namespace std;

int main()
{
	int numEntered;
	char ch;
	
	do
		{
			cout << "Enter a positive interger: ";
			cin >> numEntered;
			cout << endl;

			int prime = 0;

			for (int i = 1; i <= numEntered / 2; i++)
			{
				if (numEntered % i == 0)
					prime++;
			}
			
			if (prime > 1)
				cout << "The number you entered is not a prime number" << endl;
			else
				cout << "The number you entered is a prime number" << endl;
			
			cout << "\nDo you want to do it again?(y/n) ";
			cin >> ch;

			if (ch == 'n' || ch == 'N')
			{
				cout << "Closing Program..." << endl;
				system("pause");
				return 1;
			}
		}
	while (ch == 'y' || ch == 'Y');

	system("pause");
	return 0;
}