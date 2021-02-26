#include <iostream>

using namespace std;

int main() {

    float a, b, c, d, e, f; //User inputs for the equation parameters

    cout << "For the equation of the type:\
        \na * b + b * y = c\
        \nd * x + e * y = f\
        \nInput, respectively the values of a, b, c, d, e and f" << endl;
        
    cin >> a >> b >> c >> d >> e >> f;

    float num1, num2, den;  //The variables we need in order to solve the equations

    num1 = (c * e - b * f); 
    num2 = (a * f - c * d);
    den = (a * e - b * d);  

    if (den == 0)
        cerr << "Impossible system\n";
    else if (num1 == 0 || num2 == 0)
        cerr << "Inconsistent system\n";
    else
        cout << "x = " << num1 / den << endl
             << "y = " << num2 / den << endl;
        
    return 0;
}