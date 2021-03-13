#include <iostream>
#include <cmath>

using namespace std;

double calculateSqrt(double num, double precision, int maxIterations);

int main() {

    int nMaxIter;
    double num, precision;


    cout << "Insert, respectively, a number to calcute the square root, the maximum number of iterations and  the precision" << endl;
    cin >> num >> nMaxIter >> precision ;

    double sqroot = calculateSqrt(num, precision, nMaxIter);  

    cout << "sqrt(" << num << ") = " << sqroot << endl;

    return 0;
}



double calculateSqrt(double num, double precision, int maxIterations) {

    double rq  = 1.0;
    double rqn = (rq + num / rq) / 2.0;
    double dif = num - pow(rqn, 2);

    while (abs(dif) > abs(precision) && maxIterations > 0) {

        rq = rqn;
        rqn = (rq + num / rq) / 2.0;
        dif = num - pow(rqn, 2);
        maxIterations--;
    }

    return rqn;
}