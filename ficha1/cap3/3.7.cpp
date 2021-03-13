#include <iostream>
#include <ios>
#include <limits>

using namespace std;

bool readInt(int &x);

int main() {

    int num;

    cout << "Enter a number: ";

    bool isValid = readInt(num);

    cout << "The value" (isValid ? " is " : " is not ") << "an integer." << endl;

    return 0;
}


bool readInt(int &x) {

    cin >> x;

    bool isInt = cin.good() && cin.peek() == '\n';                  // Checks if the input is an int                       

    cin.clear();                                                    // Clears error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n');            // Clears instream buffer

    return isInt;
}