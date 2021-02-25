#include <iostream>
#include <cmath>
using namespace std;


float mass(float radius, float materialMass) {
	const float PI = atan(1) * 4;	// approximation to pi 

	// formula of a sphere mass: M_sphere = 4/3 * (pi * M_material * r^3)
	return 4.0/3.0 * (materialMass * PI * pow(radius, 3));
};


int main() {

	float radius, materialMass;	// input operands

	cout << "Which is the radius of the sphere [m]? ";
	cin >> radius;
	cout << "Which is the mass of the sphere's material [kg/m^3]? ";
	cin >> materialMass;

	float sphereMass = mass(radius, materialMass);

	cout << "Sphere's mass is " << sphereMass << " [kg]" << endl;

	return 0;
}