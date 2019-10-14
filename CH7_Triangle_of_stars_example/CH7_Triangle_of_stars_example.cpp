// Program that prints a triangle of stars

#include <iostream>

using namespace std;

	// prototyping functions
void printStars(int blanks, int starsInLines);

int main()
{
		// declaring variables
	int noOfLines; // variable to store number of lines
	int counter; // for loop control variable
	int noOfBlanks; // variable to store number of blanks

	cout << "Enter the number of star lines (1 to 20) "
		 << "to be printed: ";	
	
	cin >> noOfLines;

	while (noOfLines < 0 || noOfLines > 20)
	{
		cout << "Number of star lines should be "
			 << "between 1 and 20" << endl;

		cout << "Enter the number of star lines "
			 << "(1 to 20) to be printed: ";		
		
		cin >> noOfLines;
	}

	cout << endl << endl;
	noOfBlanks = 30;

	for (counter = 1; counter <= noOfLines; counter++)
	{
		printStars(noOfBlanks, counter);
		noOfBlanks--;
	}

	system("pause");
	return 0;
}

void printStars(int blanks, int starsInLines)
{
	int count;

	for (count = 1; count <= blanks; count++)
		cout << ' ';

	for (count = 1; count <= starsInLines; count++)
		cout << " * ";
	
	cout << endl;
}