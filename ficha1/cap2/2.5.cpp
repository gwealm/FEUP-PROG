#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    const unsigned RESULT_PRECISION = 3;

    double a, b, c;  // User input for the coefficients of the equation

    cout << "Solution of Ax^2 + Bx + C = 0" << endl;
    cout << "Insert the coefficients (A B C): ";
    cin >> a >> b >> c;

    double insideSqrt = b * b - 4 * a * c;
    double root1, root2;                         
    bool isComplex, areEqual;                   // Booleans to flag if the roots are or aren't equal and complex

    root1 = (-b + sqrt(insideSqrt)) / 2 * a;    // First root
    root2 = (-b - sqrt(insideSqrt)) / 2 * a;    // Second root

    if (insideSqrt < 0)                          // Checks if what's inside of the root is negative (if yes the result will be a complex number)
        isComplex = true;
    if (root1 == root2)                         // Checks if the equation has 2 equal roots
        areEqual = true;

    // By using ternary operator I changed the output message, according to the previously obtained results

    cout << fixed << setprecision(RESULT_PRECISION);
    cout << "The equation has 2 " << ((areEqual) ? "equal " : "different ")
         << ((isComplex) ? "complex " : "reals ") << "roots: "
         << root1 << " and " << root2 << endl;   

    return 0;
}