#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    const unsigned RESULT_PRECISION = 3; // Result precision

    double a, b, c;  // User input for the coefficients of the equation

    cout << "Solution of Ax^2 + Bx + C = 0" << endl;
    cout << "Insert the coefficients (A B C): ";
    cin >> a >> b >> c;

    double insideSqrt = b * b - 4 * a * c;
    double root1, root2;                         

    cout << "The equation has 2 ";
    cout << fixed << setprecision(RESULT_PRECISION);    // Sets numeric precision to 3 decimal places

    if (insideSqrt < 0)                                 // 2 different complex roots
         cout << "different complex roots: " 
              << -b / (2 * a) << "+" << sqrt(-insideSqrt) / (2 * a) << "i" << " and " 
              << -b / (2 * a) << "-" << sqrt(-insideSqrt) / (2 * a) << "i" << endl;
    else if (insideSqrt == 0)                            // 2 equal real roots
        cout << "equal real root: " << -b / (2 * a) << endl;
    else                                                 // 2 different real roots
        cout << "different real roots: " << (-b - sqrt(b * b - 4 * a * c)) / (2 * a) << "and"
             << (-b + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;

    
    return 0;
}