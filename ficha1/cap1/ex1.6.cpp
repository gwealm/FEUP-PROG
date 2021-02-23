#include <iostream>
#include <cmath>
using namespace std;


double distance(double x1, double y1, double x2, double y2) {
	double deltaX = pow(x2 - x1, 2);
	double deltaY = pow(y2 - y1, 2);

	return sqrt(deltaX + deltaY);
}
	

int main() {

	double x1, y1, x2, y2, x3, y3;

	cout << "Insert, respectively, x and y coordinates of the first point: ";
	cin >> x1 >> y1;

	cout << "Insert, respectively, x and y coordinates of the second point: ";
	cin >> x2 >> y2;

	cout << "Insert, respectively, x and y coordinates of the third point: ";
	cin >> x3 >> y3;

	//We're going to call an auxiliar function to calculate the length of each side of the triangle
	double lengthSide1 = distance(x1, y1, x2, y2);	
	double lengthSide2 = distance(x1, y1, x3, y3);
	double lengthSide3 = distance(x2, y2, x3, y3);

	double semiPerimeter = (lengthSide1 + lengthSide2 + lengthSide3) / 2.0;

	//The following area is calculated according to Heron's formula
	double area = sqrt(semiPerimeter * 
		(semiPerimeter - lengthSide1) * 
		(semiPerimeter - lengthSide2) * 
		(semiPerimeter - lengthSide3));

	cout << "The area of the triangle is " << area << " u.a" << endl;

	return 0;
}