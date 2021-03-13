#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateSqrt(double num, double precision, int maxIterations);

double calculatePrecision(double n);

int main() {

    int nMaxIter;
    double num, precision;


    cout << "Insert, respectively, a number to calcute the square root, the maximum number of iterations and  the precision" << endl;
    cin >> num >> nMaxIter >> precision ;

    double sqroot = calculateSqrt(num, precision, nMaxIter);  
    const int PREC = calculatePrecision(precision); 

    cout << fixed << setprecision(PREC);

    cout << "Real: sqrt(" << num << ") = " << sqroot << endl;
    cout << "Approximation: sqrt(" << num << ") = " << sqrt(num) << endl;

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

double calculatePrecision(double n) {

    int cont = 0;

    while (n < 1) {
        n *= 10;
        cont++;
    }

    return cont;
}