#include <iostream>

using namespace std;


double absolutePrecision(double val1, double val2);

int main() {

    int count = 1, lastDen = 1;         
    float res, oldRes = 999999999999;                      // Variable to store result and the previous result (starts at this value to have no conflicts entering the while loop)
    double precision;                                      // User input (precision)

    cout << "What's the precision you want ? ";
    cin >> precision;


    while (absolutePrecision(res, oldRes) > precision) {

        oldRes = res;                       // Keeps track of the last result to calculate the current precision

        lastDen += count;                       // Multiplies by the last denominator (basically calculates the factorial of n, by tracking each iteration count)
        res += 1.0 / lastDen;

        count++;
    }

    cout << "Result of the series: " << res + 1 << endl;
    
    return 0;
}


double absolutePrecision(double val1, double val2) {
    return abs(val1 - val2);
}