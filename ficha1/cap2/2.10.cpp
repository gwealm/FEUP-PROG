#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n);

int getBiggestPrimeBellow(int n);
int getLowerDivPrime(int n);


int main() {

    int num;                        // User input

    cout << "Insert a number: ";
    cin >> num;

    int cont = 0;                   // Tracks if the while loop is on the first iteration (cont = 0) to print "x" or not

    while (num != 1) {
        int lowerPrimeDivisor = getLowerDivPrime(num);      // Gets the smaller prime that divides num

        num /= lowerPrimeDivisor;

        if (cont != 0) 
            cout << "x";                // prints "x" unless we're on the first iteration

        cout << lowerPrimeDivisor;      // primes the prime factor
        cont++;                         // Updates cont to track the iteration count
    }
    
    cout << endl;

    return 0;
}

/**
 * @brief           - Checks if a number is or isn't prime 
 * 
 * @param           - int 
 * @return          - bool 
 */
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


/**
 * @brief           - Gets the smaller prime divisor of n
 * 
 * @param           - int
 * @return          - int 
 */
int getLowerDivPrime(int n) {

    int cont = 0;       // Initializes counter

    /* We don't need to have a return outside the loop, because in the worst case ()
     * There is no smaller prime divisor of n, n is always divisible by himself
     */
    while (cont <= n) {
        if (isPrime(cont) && n % cont == 0)     // If cont is prime and divides n, it is returned as the smallest n prime divisor
            return cont;
        else
            cont++;
    }
    return -1;                                  // The function will never get to this return, but it disables some IDE warnings
}