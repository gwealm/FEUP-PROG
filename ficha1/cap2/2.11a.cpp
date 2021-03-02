#include <iostream>

using namespace std;

int main() {

    const int STEP = 2;             // Defined step between each iteration

    int count = 0, den = 1;         
    float res;                      // Variable to store result
    int reps;                       // User input

    cout << "How many terms do you want to calculate ? ";
    cin >> reps;

    for (int i = 0; i < reps; i++, count++, den += STEP)
        (count % 2 == 0) ? res += 4.0/ den : res -= 4.0 / den;      // Depending on the parity of the operation count, the member is added or subtracted

    cout << "Result of the series: " << res << endl;

    return 0;
}