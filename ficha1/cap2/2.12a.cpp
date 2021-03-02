#include <iostream>

using namespace std;

double absolutePrecision(double val1, double val2);


int main() {

    const int STEP = 2;                                    // Defined step between each iteration

    int count = 0, den = 1;         
    float res, oldRes = 999999999999;                      // Variable to store result and the previous result (starts at this value to have no conflicts entering the while loop)
    double precision;


    cout << "What's the precision you want ? ";
    cin >> precision;

    while (absolutePrecision(res, oldRes) > precision) {

        oldRes = res;                                               // Keeps track of the last result to calculate the current precision

        (count % 2 == 0) ? res += 4.0/ den : res -= 4.0 / den;      // Depending on the parity of the operation count, the member is added or subtracted

        count++;                                                    // Updates the iteration counter
        den += STEP;                                                // Adds the fixed step to the denominator
    }

    cout << "Result of the series: " << res << endl;

    return 0;
}

double absolutePrecision(double val1, double val2) {
    return abs(val1 - val2);
}

