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

const int NUMBER_OF_SCORES_PER_STUDENTS = 5;
const int MAX = 50;


struct courseData
{	
	string studentFullName;
	int testScores[MAX];
	double averageTestScore;
	double totalClassAverage;
	char letterGrade;
};

struct studentData
{
	string studentFullName;
	int testScores[MAX];
};

struct classGradesAndAverageScores
{
	double averageTestScore;
	char letterGrade;
};

struct classTotalAverage
{
	double totalAverage;
};

void getData(ifstream& inFile, studentData student[], int& n)
{
	n = 0;
	int studentList = 0;

	while (!inFile.eof())
	{
		inFile >> student[studentList].studentFullName;
		for (int scoreList = 0; scoreList < NUMBER_OF_SCORES_PER_STUDENTS; scoreList++)
			inFile >> student[studentList].testScores[scoreList];
		
		studentList++;
	}
	n = studentList;
}

char determineGrade(classGradesAndAverageScores avg)
{
	if (avg.averageTestScore >= 90)
		return 'A';
	else if (avg.averageTestScore >= 80)
		return 'B';
	else if (avg.averageTestScore >= 70)
		return 'C';
	else if (avg.averageTestScore >= 60)
		return 'D';
	else
		return 'F';
}

void average(studentData scoreAvg[], classGradesAndAverageScores studentScoreAvg[], int numberOfStudents)
{ 
	for (int studentList = 0; studentList < numberOfStudents; studentList++)
	{	
		double sum = 0;

		for (int scoresList = 0; scoresList < NUMBER_OF_SCORES_PER_STUDENTS; scoresList++)
			sum += scoreAvg[studentList].testScores[scoresList];
		studentScoreAvg[studentList].averageTestScore = sum / static_cast<double>(NUMBER_OF_SCORES_PER_STUDENTS);
		studentScoreAvg[studentList].letterGrade = determineGrade(studentScoreAvg[studentList]);
	}
}

void printResults(studentData studentInfo[], classGradesAndAverageScores classInfo[], classTotalAverage& totalAverage, int n)
{
	double sum = 0.00;

	for (int studentList = 0; studentList < n; studentList++)
	{
		cout << left << setw(10) << studentInfo[studentList].studentFullName;

	for (int scoresList = 0; scoresList < NUMBER_OF_SCORES_PER_STUDENTS; scoresList++)
			cout << setw(8) << studentInfo[studentList].testScores[scoresList];

		cout << setw(8) << classInfo[studentList].averageTestScore;
		cout << setw(8) << classInfo[studentList].letterGrade;
		cout << endl;
	}

	for (int studentList = 0; studentList < n; studentList++)
		sum += classInfo[studentList].averageTestScore;

	totalAverage.totalAverage = sum / static_cast<double>(n);

	cout << "\n\nClass Average: " << totalAverage.totalAverage << endl;
}

int main()
{
	int numOfStudents;

	studentData studentsRecords[MAX];
	classGradesAndAverageScores classRecords[MAX];
	classTotalAverage classAverage;

	ifstream infile("GradeData.txt");

	if (!infile)
	{
		cout << "unable to open file.so exiting from program" << endl;
		return 1;
	}

	cout << fixed << showpoint << setprecision(2);

	getData(infile, studentsRecords, numOfStudents);
	infile.close();
	average(studentsRecords, classRecords, numOfStudents);
	printResults(studentsRecords, classRecords, classAverage, numOfStudents);

	system("pause");
	return 0;
}


