// This program reads a course score and prints
// the associated course grade

//header file
#include <iostream>

using namespace std;

// Prototyping functions
void getScore(int& score);
void printScore(int cScore);

int main()
{
	int courseScore;

	cout << "Based on the course score, "
		 << "this program computes the "
		 << "course grade." << endl;

	getScore(courseScore);
	
	printScore(courseScore);

	system("pause");
	return 0;
}

void getScore(int& score)
{
	cout << "Enter course score: ";
	cin >> score;
	cout << endl << "Course score is: "
		 << score << endl;
}

void printScore(int cScore)
{
	cout << "Your grade for the course is ";

	if (cScore >= 90)
		cout << "A." << endl;
	else if (cScore >= 80)
		cout << "B." << endl;
	else if (cScore >= 70)
		cout << "C." << endl;
	else if (cScore >= 60)
		cout << "D." << endl;
	else
		cout << "F." << endl;
}