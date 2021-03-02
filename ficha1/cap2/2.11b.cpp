#include <iostream>

using namespace std;


int main() {
    int lastDen = 1;              
    long double res = 1;                    // Variable to store the result
    int reps;                               // User input (number of times to calculate the series)

    cout << "How many terms do you want to calculate ? ";
    cin >> reps;

    for (int i = 1; i < reps; i++) {
        lastDen *= i;                       // Multiplies by the last denominator (basically calculates the factorial of n, by tracking each iteration count)
        res += 1.0 / lastDen;
    }

    cout << "Result of the series: " << res << endl;

    return 0;
}


/*
* This was my first resolution, but I decided not to use it oficially and stick to not using
* functions, as it was intended

#include <iostream>

using namespace std;

// unsigned factorial(unsigned n);


int main() {

    int cont = 0, reps;
    float res = 0;              // Will store the result

    cout << "How many terms do you want to calculate ? ";
    cin >> reps;

    for (int i = 0; i < reps; i++)
        res += 1.0 / factorial(i);

    cout << "Result of the series: " << res << endl;

    return 0;
}


unsigned factorial(unsigned n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
*/