#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    double mean, aMean, bMean, cMean;

    cout << "Please input 3 integer numbers" << endl;
	
    cout << "A ? ";
    cin >> a;

    cout << "B ? ";
    cin >> b;

    cout << "C ? ";
    cin >> c;

    mean = (a + b + c) / 3.0; //Used 3.0 instead of 3 to prevent 
    aMean = a - mean;
    bMean = b - mean;
    cMean = c - mean;

    cout.precision(3); //Modifier that sets the precision to 3 decimal places

    cout << "mean = " << fixed << mean << endl;
    cout << "A-mean = " << aMean << endl;
    cout << "B-mean = " << bMean << endl;
    cout << "C-mean = " << cMean << endl;

    return 0;
}

