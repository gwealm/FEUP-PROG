#include <iostream>

using namespace std;

int euclidesGCD(int m, int n);

int main() {

    int num1, num2;                     // User input

    cout << "Insert 2 numbers: ";
    cin >> num1 >> num2;

    if (cin.bad() || num1 <= 0 || num2 <= 0) {
        cerr << "Invalid Input!\n";
        return -1; 
    }

    int gcd = euclidesGCD(num1, num2);  // Calculates gcd(num1, num2)

    cout << "gcd(" << num1 << ", " << num2 << ") = " << gcd << endl; 

    return 0;
}

/**
 * @brief       - returns the greatest common divisor between m and n
 * 
 * @param       - m (int) 
 * @param       - n (int) 
 * @return      - gcd(m ,n) (int) 
 */
int euclidesGCD(int m, int n) {
    if (m % n == 0)                     // m is divisible by n
        return n;
    else
        return euclidesGCD(n, m%n);
}