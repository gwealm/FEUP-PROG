#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int lastDen = 1;              
    long double res = 1;                    // Adding 1 (the first member of the series manually)
    int x, reps;                            // User input

    cout << "Insert x to calculate e^(-x): ";
    cin >> x;

    cout << "How many terms do you want to calculate ? ";
    cin >> reps;


    for (int i = 1; i < reps; i++) {
        lastDen *= i;           // Multiplies by the last denominator (basically calculates the factorial of n, by tracking each iteration count)
        long double operation = static_cast<double> (pow(x, i)) / lastDen;
        (i % 2 == 0) ? res += operation : res -= operation;  // Depending on the parity of the operation count, the member is added or subtracted
    }

    cout << "Result of the series: " << res << endl;

    return 0;
}