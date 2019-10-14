/******************************************************************************

Author: Sergio Castillo

Problem: 19
One way to determine how healthy a person is by measuring the body fat
of the person.The formulas to determine the body fat for female and male
are as follows :
Body fat formula for women :
	A1 = (body weight x 0.732) + 8.987
	A2 = wrist measurement(at fullest point) / 3.140
	A3 = waist measurement(at navel) x 0.157
	A4 = hip measurement(at fullest point) x 0.249
	A5 = forearm measurement(at fullest point) x 0.434
	B = A1 + A2 – A3 – A4 + A5
	Body fat = body weight – B
	Body fat percentage = body fat x 100 / body weight
Body fat formula for men:
	A1 = (body weight x 1.082) + 94.42
	A2 = wrist measurement x 4.15
	B = A1 – A2
	Body fat = body weight – B
	Body fat percentage = body fat x 100 / body weight
	Write a program to calculate the body fat of a person.

*****************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Daclares variables
	char gender;
	double bodyWeight, wristMeasurement, waistMeasurement, hipMeasurement, forearmMeasurement, B, bodyFat, bodyFatPercentage;
	double A1, A2, A3, A4, A5;

	cout << fixed << showpoint << setprecision(2);

	cout << "Input gender (M/F): ";
	cin >> gender;
	cout << endl;


	switch (gender)
	{   //Starts switch
	case 'm':
	case 'M':
		cout << "Enter body weight: ";
		cin >> bodyWeight;
		cout << endl;

		cout << "Enter wrist measurement (at fullest point): ";
		cin >> wristMeasurement;
		cout << endl;

		A1 = (bodyWeight * 1.082) + 94.42;
		A2 = wristMeasurement * 4.15;

		B = (A1 - A2);
		bodyFat = (bodyWeight - B);
		bodyFatPercentage = (bodyFat * 100) / bodyWeight;
		break;
	case 'f':
	case 'F':
		cout << "Enter body weight: ";
		cin >> bodyWeight;
		cout << endl;

		cout << "Enter wrist measurement (at fullest point): ";
		cin >> wristMeasurement;
		cout << endl;

		cout << "Enter waist measurement (at navel): ";
		cin >> waistMeasurement;
		cout << endl;

		cout << "Enter hip measurement (at fullest point): ";
		cin >> hipMeasurement;
		cout << endl;

		cout << "Enter forearm measurement (at fullest point): ";
		cin >> forearmMeasurement;
		cout << endl;

		A1 = (bodyWeight * 0.732) + 8.987;
		A2 = wristMeasurement / 3.140;
		A3 = waistMeasurement * 0.157;
		A4 = hipMeasurement * 0.249;
		A5 = forearmMeasurement * 0.434;

		B = A1 + A2 - A3 - A4 + A5;
		bodyFat = (bodyWeight - B);
		bodyFatPercentage = (bodyFat * 100) / bodyWeight;
		break;
	default:
		cout << "Invalid gender given" << endl;
		cout << endl;
		system("pause");
		return 1;
		break;
	}  //Ends switch

	cout << "Your body fat is: " << bodyFat << endl
		 << "Body fat percentage: " << bodyFatPercentage << "%"
		 << endl;

	system("pause");

	return 0;
}