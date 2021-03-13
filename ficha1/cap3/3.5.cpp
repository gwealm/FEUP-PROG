#include <iostream>

using namespace std;

int gcd(int n1, int n2);
int gcd2(int n1, int n2, int &res);

int main() {

    int n1, n2;                    // User input
    int res1, res2;                // Result to store gcd in the call of gcd and gcd2

    cout << "Enter 2 numbers: ";
    cin >> n1 >> n2;

    res1 = gcd(n1, n2);            // Call of gcd
    gcd2(n1, n2, res2);            // Call of gcd2

    cout << "Process 1: gcd(" << n1 << ", " << n2 << ") = " << res1 << endl;
    cout << "Process 2: gcd(" << n1 << ", " << n2 << ") = " << res2 << endl;

    return 0;
}


/**
 * @brief       - Returns the greatest common divisor of n1 and n2
 * 
 * @param n1    - int
 * @param n2    - int
 * @return      - int 
 */
int gcd(int n1, int n2) {

    if (n1 == n2)
        return n1;
    else if (n1 == 0)
        return n2;
    else if (n2 == 0)
        return n1;

    while (n1 != n2) {
        if (n1 > n2)
            n1 -= n2;
        else 
            n2 -= n1;
    }
    return n1;
}

/**
 * @brief           - stores the greatest common divisor of n1 and n2 in res 
 * 
 * @param n1        - int
 * @param n2        - int
 * @param res       - int
 * @return          - int 
 */
int gcd2(int n1, int n2, int &res) {

    if (n1 == n2) {
        res = n1;

    } else if (n1 == 0) {
        res = n2;

    } else if (n2 == 0) {
        res = n1;

    } else {
        while (n1 != n2) {
            if (n1 > n2)
                n1 -= n2;
            else 
                n2 -= n1;
        }
    }
    res =  n1;
}