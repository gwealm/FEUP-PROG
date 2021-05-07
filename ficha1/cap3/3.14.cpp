#include <iostream>
#include <cmath>

using namespace std;

double integrateTR(double f(double), double a, double b, int n);

int main() {
    const unsigned int n = 99;

    int lB1 =  0, uB1 = 10, lB2 = -2, uB2= 2;                                                          // Integration limits

    // Note: These lambdas are not the most readable approach for this problem, I just opted for this path for training purposes
    double integral1 = integrateTR([](double x) -> double {return pow(x, 2);}, lB1, uB1, n);           // Integrates the lambda function between lB1 and uB1
    double integral2 = integrateTR([](double x) -> double {return sqrt(4-pow(x,2));}, lB2, uB2, n);    // Integrates the lambda function between lB2 and uB2

    cout << "integrate(x², " << lB1 << ", " << uB1 << ") = " << integral1 << endl; 
    cout << "integrate(sqrt(4-x²), " << lB2 << ", " << uB2 << ") = " << integral2 << endl; 

    return 0;
}

/**
 * @brief       - Returns the integral of a definite integral
 * 
 * @param       - function (f) 
 * @param       - Lower bound of the integral (a) 
 * @param       - Lower bound of the integral (b)  
 * @param       - Number of intervals (n) 
 * @return      - Integral result (double) 
 */
double integrateTR(double f(double), double a, double b, int n) {
    double area = 0, h = (b - a) / n;           // Initializes area to 0 and the size of integrals
    // Calculates the area of n intervals
    for (int i = 1; i <= n; i++)
        area += h/2.0 * (f(a + (i - 1) * h) + f(a + i * h));
    return area;
}