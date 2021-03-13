#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

bool isPrime(unsigned long n);

int main() {

    unsigned long largestPrime = ULONG_MAX;     // The maximum value which can be stored in an unsigned long variable

    while (!isPrime(largestPrime)) {
        largestPrime--;
    }

    cout << largestPrime << " is the largest prime number that can be stored on an unsigned long variable" << endl;

    return 0;
}


bool isPrime(unsigned long n) {

    unsigned long testLimit = ceil(sqrt(n));      //The numeric limit for the divisor tests

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