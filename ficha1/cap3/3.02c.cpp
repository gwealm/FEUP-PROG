#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);


int main() {

    int cont1 = 0, num = 0;         // Variables to track the current iteration number and number of primes 
    const int BOUND = 100;          // Upper limit of the for loop

    while (cont1 < BOUND) {
        if (isPrime(num)) {
            cout << num << endl;
            cont1++;
        }
        num++;
    }
    return 0;
}


bool isPrime(int n) {

    const int LIMIT = ceil(sqrt(n));

    // Corner cases
    if (n == 1) return false;
    if (n == 2) return true;

    for (int i = 2; i < LIMIT; i++) {
        if (n % i == 0)                 // if the number has a divisor different to 1 and itself it is not prime
            return false;
    }

    return true;                         // If the number has no divisors different to 1 and itself, it is not prime
}