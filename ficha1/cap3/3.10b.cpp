#include <iostream>

using namespace std;

unsigned long long factorial_rec(unsigned int n);

int main() {
    unsigned int num;

    cout << "Insert a number: ";
    cin >> num;

    unsigned long long numFact = factorial_rec(num);

    cout << "(" << num << ")! = " << numFact << endl;

    return 0;
}

/**
 * @brief       - returns n!
 * 
 * @param       - unsigned int n 
 * @return      - unsigned long long 
 */
unsigned long long factorial_rec(unsigned int n) {
    if (n <= 1)
        return n - 1;
    else
        return n * factorial_rec(n - 1);
}