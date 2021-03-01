#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

bool isPrime(int n) {

    int testLimit = ceil(sqrt(n));      //The numeric limit for the divisor tests

    // Corner cases (note that I've decided to consider only positive integers)
    if (n < 2) return false;
    if (n == 2) return true;

    // Checks if the number has any divisor (not including 1 or itself)
    for (int i = 2; i <= testLimit ; i++) {
        if (n % i == 0) 
            return false;
    }

    return true;
}


int main() {

    int num = 0, primesCount = 0;

    while (primesCount < 100) {
        if (isPrime(num)) {
            cout << num << endl;
            primesCount++;              // Next prime
        }
        num++;                           // Next number 
    }



    return 0;
}