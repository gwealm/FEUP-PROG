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
    unsigned long n;
    unsigned long cont;

    /*
    * In the next loop we are incrementing cont each iteration by 1 and, if the number is prime, we store it in cont.
    * By doing this, in the iteration when cont turns into a negative value (overflow), n will have the greatest value before overflow
    */
    while (cont > 0) {
        if (isPrime(cont))
            n = cont;  

        cont ++;
        
    }

    cout << "Largest value: " << n << endl; // Largest prime number that can be stored in a variable of type unsigned long

    return 1;
}