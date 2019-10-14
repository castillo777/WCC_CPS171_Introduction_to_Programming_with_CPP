/*****************************************************************************
Author: Sergio Castillo

The manager of a football stadium wants you to write a program that
calculates the total ticket sales after each game. There are four types of
tickets—box, sideline, premium, and general admission. After each game,
data is stored in a file in the following form:
ticketPrice numberOfTicketsSold
...

Sample data are shown below:

250 5750
100 28000
50 35750
25 18750

The first line indicates that the ticket price is $250 and that 5750 tickets were
sold at that price. Output the number of tickets sold and the total sale
amount. Format your output with two decimal places.

*****************************************************************************/

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;
	
	double ticketPrice;
	int numOfTicketsSold;
	int count = 0;
	int totalNumOfTicketsSold = 0;
	double totalSaleAmount = 0.00;

	cout << fixed << showpoint << setprecision(2);

	inFile.open("MP2-StadiumData.txt");

	if (!inFile)
	{
		cout << "Cannot open input file. "
			<< "Program terminates!" << endl;
		system("pause");
		return 1;
	}

	inFile >> ticketPrice >> numOfTicketsSold;

	while (inFile)
	{			
		totalNumOfTicketsSold = totalNumOfTicketsSold + numOfTicketsSold;
		totalSaleAmount = totalSaleAmount + (ticketPrice * numOfTicketsSold);
		count++;
		
		inFile >> ticketPrice >> numOfTicketsSold;
	}

		cout << "Total number of Tickets sold is: " << totalNumOfTicketsSold << endl;
		cout << "Total Sale Amount: $" << totalSaleAmount << endl;

	inFile.close();

	system("pause");

	return 0;
}