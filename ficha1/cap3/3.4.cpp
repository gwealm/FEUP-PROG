#include <iostream>
#include <cmath>

using namespace std;

double round(double x, unsigned n);

int main() {

    double num;         // User input (number)
    unsigned prec;      // User input (precision)

    cout << "Insert a decimal point value to be round: ";
    cin >> num;

    cout << "Number of decimal places to be displayed: ";
    cin >> prec;


    double rounded = round(num, prec);  // Round the number to prec decimal places

    cout << "floor(" << num << ") ~= " << rounded << endl; 

    return 0;
}

double round(double x, unsigned n) {

    double roundedValue = floor(x * pow(10, n) + 0.5) / pow(10, n);

    return roundedValue;

}