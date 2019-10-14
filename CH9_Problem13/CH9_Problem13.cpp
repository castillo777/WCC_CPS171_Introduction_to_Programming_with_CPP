/*

Author: Sergio Castillo

Write a program to calculate students’ average test scores and their grades.
You may assume the following input data:

Johnson 85 83 77 91 76
Aniston 80 90 95 93 48
Cooper 78 81 11 90 73
Gupta 92 83 30 69 87
Blair 23 45 96 38 59
Clark 60 85 45 39 67
Kennedy 77 31 52 74 83
Bronson 93 94 89 77 97
Sunny 79 85 28 93 82
Smith 85 72 49 75 63

Use three arrays: a one-dimensional array to store the students’ names, a
(parallel) two-dimensional array to store the test scores, and a parallel one dimensional
array to store grades. Your program must contain at least the
following functions: a function to read and store data into two arrays, a
function to calculate the average test score and grade, and a function to
output the results. Have your program also output the class average.

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const int NUMBER_OF_COLUMNS = 5;
const int MAX = 50;

void getData(ifstream& inFile, string name[], int scores[][NUMBER_OF_COLUMNS], int& n)
{
	n = 0;
	int i = 0;
	int j = 0;

	while (!inFile.eof())
	{
		inFile >> name[i];
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
			inFile >> scores[i][j];
		i++;
	}
	
	n = i;
}

char determineGrade(double avg)
{
	if (avg >= 90)
		return 'A';
	else if (avg >= 80 && avg <= 89)
		return 'B';
	else if (avg >= 70 && avg <= 79)
		return 'C';
	else if (avg >= 60 && avg <= 69)
		return 'D';
	else
		return 'F';
}

void average(int a[][NUMBER_OF_COLUMNS], char grade[], double avg[], int no_of_students)
{
	for (int i = 0; i < no_of_students; i++)
	{		
		double sum = 0;

		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
			sum += a[i][j];
		avg[i] = sum / static_cast<double>(NUMBER_OF_COLUMNS);
		grade[i] = determineGrade(avg[i]);
	}
}

void printResults(string name[], double avg[], int scores[][NUMBER_OF_COLUMNS], char grade[], int n)
{
	double sum = 0;
	double classAvg;

	for (int i = 0; i < n; i++)
	{
		cout << left << setw(10) << name[i];
		
		for (int k = 0; k < NUMBER_OF_COLUMNS; k++)
			cout << setw(8) << scores[i][k];
		
		cout << setw(8) << avg[i];
		cout << setw(8) << grade[i];
		cout << endl;
	}

	for (int i = 0; i < n; i++)
		sum += avg[i];	

	classAvg = sum / static_cast<double>(n);

	cout << "\n\nClass Average: " << classAvg << endl;
}

int main()
{
	// a one-dimensional array to store the students names.
	string name[MAX];
	// a (parallel) two-dimensional array to store the test scores.
	int scores[MAX][NUMBER_OF_COLUMNS];
	// a parallel one-dimensional array to store grades.
	char grade[MAX];
	int no_of_students;
	double avg[MAX];

	ifstream infile("GradeData.txt");

	if (!infile)
	{
		cout << "unable to open file.so exiting from program" << endl;
		return 1;
	}

	cout << fixed << showpoint << setprecision(2);

	getData(infile, name, scores, no_of_students);
	infile.close();
	average(scores, grade, avg, no_of_students);
	printResults(name, avg, scores, grade, no_of_students);

	system("pause");
	return 0;
}