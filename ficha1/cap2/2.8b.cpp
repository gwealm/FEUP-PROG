#include <iostream>
#include <cmath>
#include <iomanip>
//# define PI           3.14159265358979323846  /* pi */

using namespace std;

int main() {

    float initialValue, finalValue, step;

    double rad;

    cout << "Set the initial degree: ";
    cin  >> initialValue;
    cout << "Set the final degree: ";
    cin >> finalValue;
    cout << "Set the interval: ";
    cin >> step;

    cout << "ang\t\tsin\t\tcos\t\ttan" << endl;           // Header

    cout << fixed << setprecision(6);                   // Sets the fixed decimal places

    for (float i = 0; i  <= finalValue + step; i += step) {
        rad = i * M_PI / 180;                             // Converts degrees to radians
        cout << i << "\t" << sin(rad) << "\t" << cos(rad) << "\t";

        if (i == 90 || i == 270)                        // Checks if the tangent has an infinit value between 0 and 360 degrees
            cout << "infinite" << endl;
        else 
            cout << tan(rad) << endl;
    }

    return 0;
}