/********************************************************************************

Author: Sergio Castillo

Write a program that allows the user to enter the last names of five candidates
in a local election and the number of votes received by each candidate.The
program should then output each candidate’s name, the number of votes
received, and the percentage of the total votes received by the candidate.
Your program should also output the winner of the election.

*********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void getData(ifstream& infile, string candidates[], int votes[]);
double calculatePercentage(int votes[], int vote);
int findWinner(int votes[]);
void printResults(string candidates[], int votes[]);


const int NUMBER_OF_CANDIDATES = 5;

int main()
{
	string names[NUMBER_OF_CANDIDATES];
	int numOfVotes[NUMBER_OF_CANDIDATES];

	ifstream infile("VoteData.txt");

	if (!infile)
	{
		cout << "unable to open file.so exiting from program" << endl;
		return 1;
	}

	cout << fixed << showpoint << setprecision(2);

	getData(infile, names, numOfVotes);
	infile.close();
	printResults(names, numOfVotes);
		
	system("pause");
	return 0;
}

void getData(ifstream& inFile, string candidates[], int votes[])
{
	while (!inFile.eof())
	{
		for (int i = 0; i < NUMBER_OF_CANDIDATES; i++)
			inFile >> candidates[i] >> votes[i];
	}
}

double calculatePercentage(int votes[], int vote) 
{
	const double PERCENT = 100.00;
	double sumOfVotes = 0.00;

	for (int i = 0; i < NUMBER_OF_CANDIDATES; i++)
		sumOfVotes += votes[i];

	double percentage = static_cast<double>(vote) / sumOfVotes;

	return percentage * PERCENT;
}

int findWinner(int votes[])
{
	int max = votes[0];
	int maxIndex = 0;

	for (int i = 0; i < NUMBER_OF_CANDIDATES; i++)
	{
		if (max < votes[i])
		{
			max = votes[i];
			maxIndex = i;
		}
	}

	return maxIndex;
}

void printResults(string candidates[], int votes[])
{
	
	cout << left << setw(15) << "Name:" << right << setw(15) << "Votes:" << setw(17) << "Percentage:" << endl;
	
	for (int i = 0; i < NUMBER_OF_CANDIDATES; i++) 
	{
		cout << left << setw(15) << candidates[i] << right << setw(13) << votes[i] << setw(13);
		double percentage = calculatePercentage(votes, votes[i]);
		cout << percentage << "%" << endl;
	}

	cout << "\n\The winner is: " << candidates[findWinner(votes)] << endl;
}