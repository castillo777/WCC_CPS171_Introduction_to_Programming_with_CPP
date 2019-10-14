/******************************************************************************

 Author: Sergio Castillo

 The following formula gives the distance between two points, (x1, y1) and
 (x2, y2) in the Cartesian plane:

 sqrt((x2-x1)^2+(y2-y1)^2)

 Given the center and a point on the circle, you can use this formula to find
 the radius of the circle. Write a program that prompts the user to enter the
 center and a point on the circle. The program should then output the
 circle’s radius, diameter, circumference, and area. Your program must have
 at least the following functions:

 a. distance: This function takes as its parameters four numbers that
	represent two points in the plane and returns the distance between them.
 b. radius: This function takes as its parameters four numbers that represent
	the center and a point on the circle, calls the function distance
	to find the radius of the circle, and returns the circle’s radius.
 c. circumference: This function takes as its parameter a number that
	represents the radius of the circle and returns the circle’s circumference.
	(If r is the radius, the circumference is 2pr.)
 d. area: This function takes as its parameter a number that represents the
	radius of the circle and returns the circle’s area. (If r is the radius, 
	the area is pr2.)
	Assume that p = 3.1416.

********************************************************************************/

// Header file
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Named constants
double const  PI = 3.1416;
double const SQUARE = 2.0;
double const CONSTANT_ON_DIAMETER_OF_CIRCLE_FORMULA = 2.0;
double const CONSTANT_ON_CIRCUMFERENCE_OF_CIRCLE_FORMULA = 2.0;

// Prototyping Functions
double centerToOuterPointDistance(double xDistancePoint2, double xDistancePoint1, double yDistancePoint2, double yDistancePoint1);
double radiusOfCircle(double xAxisPoint2, double xAxisPoint1, double yAxisPoint2, double yAxisPoint1);
double diameterOfCircle(double circleRadius);
double circumferenceOfCircle(double circleRadius);
double areaOfCircle(double circleRadius);

void main()
{
	// Declaring variables
	double radius, diameter, circumference, area;
	double xAxisCenterOnCircle, xAxisPointOnCircle;
	double yAxisCenterOnCircle, yAxisPointOnCircle;
	
	cout << "Enter the coordinates for the center on your circle (x y): ";
	cin >> xAxisCenterOnCircle >> yAxisCenterOnCircle;
	cout << endl;

	cout << "Enter the coordinates for the outer point on your circle (x y): ";
	cin >> xAxisPointOnCircle >> yAxisPointOnCircle;
	cout << endl;

	radius = radiusOfCircle(xAxisCenterOnCircle, xAxisPointOnCircle, yAxisCenterOnCircle, yAxisPointOnCircle);
	
	diameter = diameterOfCircle(radius);
	
	circumference = circumferenceOfCircle(radius);

	area = areaOfCircle(radius);

	cout << fixed << showpoint << setprecision(2);

	cout << "The circle's radius is: "
		 << radius << " inches." << endl;

	cout << "The circle's diameter is: "
		 << diameter << " inches." << endl;

	cout << "The circle's circumference is: "
		<< circumference << " inches." << endl;

	cout << "The circle's area is: "
		 << area << " inches squared." << endl;
	
	system("pause");
}

double centerToOuterPointDistance(double xDistancePoint2, double xDistancePoint1, double yDistancePoint2, double yDistancePoint1)
{
	double distanceBetweenPoints;	

	return distanceBetweenPoints = (sqrt((pow((xDistancePoint2) - (xDistancePoint1), SQUARE)) + (pow((yDistancePoint2) - (yDistancePoint1), SQUARE))));
}

double radiusOfCircle(double xAxisPoint2, double xAxisPoint1, double yAxisPoint2, double yAxisPoint1)
{
	double radiusOnCircle;

	return radiusOnCircle = centerToOuterPointDistance(xAxisPoint2, xAxisPoint1, yAxisPoint2, yAxisPoint1);
}

double diameterOfCircle(double circleRadius)
{
	double diameterOnCircle;

	return diameterOnCircle = (circleRadius * CONSTANT_ON_DIAMETER_OF_CIRCLE_FORMULA);
}

double circumferenceOfCircle(double circleRadius)
{
	double circumferenceOnCircle;

	return circumferenceOnCircle = (CONSTANT_ON_CIRCUMFERENCE_OF_CIRCLE_FORMULA * PI * circleRadius);
}

double areaOfCircle(double circleRadius)
{
	double areaOnCircle;

	return areaOnCircle = (PI * (pow(circleRadius, SQUARE)));;
}