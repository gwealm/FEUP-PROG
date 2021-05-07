#include <iostream>
#include <climits>

using namespace std;

unsigned long long factorial_ite(unsigned int n);
unsigned long long factorial_rec(unsigned int n);

int main() {

    unsigned int num, lastFact;                                   // User input
    unsigned long long fact = 1, MAX = ULLONG_MAX;                // Max value supported by an unsigned long long variable

    cout << "Insert a number: ";
    cin >> num;

    while (fact > 0) {
        lastFact = fact;
        fact = factorial_ite(num);
    }

    cout << "Max ULL value: " << MAX << endl
         << "(" << num << ")! = " << lastFact << endl;

    return 0;
}


unsigned long long factorial_ite(unsigned int n) {

    unsigned int cont = 1;
    unsigned long long res = 1;

    while (cont <= n) {
        res *= cont;
        cont++;
    }

    return res;
}