#include <iostream>
#include <cmath>

using namespace std;


double absolutePrecision(double val1, double val2);

int main() {

    int count = 1, lastDen = 1;         
    double res = 1, oldRes = 999999999999;                 // Variable to store result and the previous result (starts at this value to have no conflicts entering the while loop)
    double precision;                                      // User input (precision)
    int x;                                                 // User input 


    cout << "Insert x to calculate e^(-x): ";
    cin >> x;

    cout << "What's the precision you want ? ";
    cin >> precision;


    while (absolutePrecision(res, oldRes) > precision) {

        oldRes = res;                       // Keeps track of the last result to calculate the current precision

        lastDen *= count;
        double operation = static_cast<double> (pow(x, count)) / lastDen;
        (count % 2 == 0) ? res += operation : res -= operation;  // Depending on the parity of the operation count, the member is added or subtracted

        count++;
    }

    cout << "Result of the series: " << res << endl;
    
    return 0;
}


double absolutePrecision(double val1, double val2) {
    return abs(val1 - val2);
}