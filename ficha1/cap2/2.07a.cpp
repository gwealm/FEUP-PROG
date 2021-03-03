#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;                              // User input. It's an unsigned int, because it is incorrect to say a negative number is prime
    bool isPrime = true;                // Boolean variable which will track if the number is or is not prime

    cout << "Insert a number: ";
    cin >> n;

    // If the input is not an integer or if it is negative, an error message is displayed and the execution ends
    if (n < 0 || !cin) {
        cerr << "Invalid input. You must input a positive integer\n";
        return 0;
    }

    int testLimit = ceil(sqrt(n));       //The numeric limit for the divisor tests

    if (n < 2) {                         // If the number is 0 or 1 it is not prime
        isPrime = false;
    } else if (n == 2) {                 // If the number is 2 it is prime (corner case)
        isPrime = true;
    } else {
        // Checks if the number has any divisor (not including 1 or itself)
        for (int i = 2; i <= testLimit ; i++) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }

    cout << n << ((isPrime) ? " is " : " is not ") << "prime" << endl;

    return 0;
}