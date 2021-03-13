#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int main() {

    int num;                            // User input
    const int BOUND = 1000;             //Upper limit for the for loop

    cout << "Insert a number: ";
    cin >> num;

    cout << num << ((isPrime) ? " is " : " is not ") << "prime" << endl;


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