#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    int num, nMaxIter;
    double rq = 1.0, rqn, delta;

    cout << "Insert, respectively, a number, the max number of iterations, and the precision: ";
    cin >> num >> nMaxIter >> delta;

    rqn = (rq + num / rq) / 2.0;
    delta = num - pow(rqn, 2);

    // The loop will continue until the absolute precision is better or equal to the given precision or until the Max Number of iterations is passed 
    while (abs(delta) >= 0.000001 && nMaxIter > 0) {
        rq = rqn;
        rqn = (rq + num / rq) / 2.0;
        delta = num - pow(rqn, 2);
        nMaxIter--;
    }
    
    cout << fixed << setprecision(4) << "sqrt(" << num << ") = " << rq << endl;

    return 0;
}