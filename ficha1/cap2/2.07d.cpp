#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

bool isPrime(unsigned long n); 

int main() {
    unsigned long n = ULONG_MAX;

    for (n; !isPrime(n); n--)
        ;

    cout << "Largest value: " << n << endl; // Largest prime number that can be stored in a variable of type unsigned long

    return 1;
}

bool isPrime(unsigned long n) {

    const unsigned long LIMIT = ceil(sqrt(n));      //The numeric limit for the divisor tests

    // Corner cases (note that I've decided to consider only positive integers)
    if (n < 2) return false;
    if (n == 2) return true;

    // Checks if the number has any divisor (not including 1 or itself)
    for (int i = 2; i <= LIMIT ; i++) {
        if (n % i == 0) 
            return false;
    }
    return true;
}