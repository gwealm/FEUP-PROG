#include <iostream>
using namespace std;

int main() {

	float a, b, c, d, e, f;	// user input for the equation variables

	cout << "For the equation of the type:\
			\na * b + b * y = c\
			\nd * x + e * y = f\
			\nInput, respectively the values of a, b, c, d, e and f" << endl;

	cin >> a >> b >> c >> d >> e >> f;

	cout << "x = " << (c * e - b * f) / (a * e - b * d)  << endl;
	cout << "y = " << (a * f - c * d) / (a * e - b * d) << endl;

	return 0;
}