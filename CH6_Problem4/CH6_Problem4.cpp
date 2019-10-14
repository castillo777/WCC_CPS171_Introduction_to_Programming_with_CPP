/*****************************************************************************

 Author: Sergio Castillo

 Write a program that defines the named constant PI, const double
 PI = 3.1419;, which stores the value of pi. The program should use PI
 and the functions listed in Table 6-1 to accomplish the following.

 a. Output the value of square root of pi.
 b. Prompt the user to input the value of a double variable r, which stores
    the radius of a sphere. The program then outputs the following:

    i. The value of 4pr^2, which is the surface area of the sphere.
    ii. The value of (4/3)pr^3, which is the volume of the sphere.

*****************************************************************************/

//Header file
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//Named constants
const double PI = 3.1419;
const double SQUARE = 2.0;
const double CUBE = 3.0;
const double CONSTANT_ON_AREA_OF_SPHERE_FORMULA = 4.0;
const double CONSTANT_ON_VOLUME_OF_SPHERE_FORMULA = 4.0 / 3.0;

//Prototyping functions
double surfaceAreaOfSphere(double radiusForArea);
double volumeOfSphere(double radiusForVolume);

int main()
{	
	//Declaring variables
	double radiusOfSphere, area, volume;

	cout << fixed << showpoint << setprecision(2);

	cout << "The square root of pi is: "
		 << sqrt(PI) << endl;

	cout << "\nEnter the radius of your sphere: ";
	cin >> radiusOfSphere;
	cout << endl;
		
	area = surfaceAreaOfSphere(radiusOfSphere);
	
	volume = volumeOfSphere(radiusOfSphere);

	cout << "The surface area of the sphere is: "
		 << area << " inches squared." << endl;

	cout << "The volume of the sphere is: "
		 << volume << " inches cubed." << endl;

	system("pause");
	return 0;
}

double surfaceAreaOfSphere(double radiusForArea)
{
	double surfaceArea;

	return surfaceArea = (CONSTANT_ON_AREA_OF_SPHERE_FORMULA * PI * (pow(radiusForArea, SQUARE)));
}

double volumeOfSphere(double radiusForVolume)
{
	double sphereVolume;

	return sphereVolume = ((CONSTANT_ON_VOLUME_OF_SPHERE_FORMULA) * PI * (pow(radiusForVolume, CUBE)));
}