/**************************************************************************************
//
//	Author: Sergio Castillo
//
//	To make telephone numbers easier to remember, some companies use letters
//	to show their telephone number. For example, using letters, the telephone
//	number 438-5626 can be shown as GET LOAN. In some cases, to make a
//	telephone number meaningful, companies might use more than seven letters.
//	For example, 225-5466 can be displayed as CALL HOME, which uses eight
//	letters. Write a program that prompts the user to enter a telephone number
//	expressed in letters and outputs the corresponding telephone number in digits. If
//	the user enters more than seven letters, then process only the first seven letters.
//	Also output the – (hyphen) after the third digit. Allow the user to use both
//	uppercase and lowercase letters as well as spaces between words. Moreover, your
//	program should process as many telephone numbers as the user wants.
//
**************************************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int counter;
	char numberInLetters;
	char anotherTry;

	do
	{
		cout << "Enter a phone number in letters only: ";

		for (counter = 0; counter < 7; counter++)
		{
			cin >> numberInLetters;

			if (counter == 3)
				cout << "-";

			if (numberInLetters >= 'A' && numberInLetters <= 'Z'
				|| numberInLetters >= 'a' && numberInLetters <= 'z')
				switch (numberInLetters)
				{
				case 'A':
				case 'a':
				case 'B':
				case 'b':
				case 'C':
				case 'c':
					cout << 2;
					break;
				case 'D':
				case 'd':
				case 'E':
				case 'e':
				case 'F':
				case 'f':
					cout << 3;
					break;
				case 'G':
				case 'g':
				case 'H':
				case 'h':
				case 'I':
				case 'i':
					cout << 4;
					break;
				case 'J':
				case 'j':
				case 'K':
				case 'k':
				case 'L':
				case 'l':
					cout << 5;
					break;
				case 'M':
				case 'm':
				case 'N':
				case 'n':
				case 'O':
				case 'o':
					cout << 6;
					break;
				case 'P':
				case 'p':
				case 'Q':
				case 'q':
				case 'R':
				case 'r':
				case 'S':
				case 's':
					cout << 7;
					break;
				case 'T':
				case 't':
				case 'U':
				case 'u':
				case 'V':
				case 'v':
					cout << 8;
					break;
				case 'W':
				case 'w':
				case 'X':
				case 'x':
				case 'Y':
				case 'y':
				case 'Z':
				case 'z':
					cout << 9;
					break;
				}//switch ends
		}//For loop ends
		
		cout << "\nDo you want to do it again?(y/n): ";
		cin.ignore(256,'\n');
		cin >> anotherTry;
		cout << endl;

		if (anotherTry == 'n' || anotherTry == 'N')
		{
			cout << "Closing Program..." << endl;
			system("pause");
			return 1;
		}
	}//do..while body loop ends
	while (anotherTry == 'y' || anotherTry == 'Y');

	system("pause");
	return 0;
}