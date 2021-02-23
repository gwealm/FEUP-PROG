#include <iostream>
#include <cmath>
using namespace std;

/**
 * @brief       - Calculates the mass of a given sphere
 *
 * @param[in]   - radius
 * @param[in]   - materialMass
 * @return[out] - float
 */
float mass(float radius, float materialMass) {
	float pi = atan(1) * 4;	//approximation to pi 

	//formula of a sphere mass: M_sphere = 4/3 * (pi * M_material * r^3)
	return 4 / 3 * materialMass * pi * pow(radius, 3);
};

int main() {

	float radius, materialMass;

	cout << "Which is the radius of the sphere [m]? ";
	cin >> radius;
	cout << "Which is the mass of the sphere's material [kg/m^3]? ";
	cin >> materialMass;

	float sphereMass = mass(radius, materialMass);

	cout << "Sphere's mass is " << sphereMass << " [kg]" << endl;

	return 0;
}