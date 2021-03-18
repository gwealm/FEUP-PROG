#include <iostream>
#include <cmath>

using namespace std;

bool isLeapYear(int year);
void test(int year);

int main() {

    int year;               // User input (year)

    cout << "Insert a year: ";
    cin >> year;

    cout << "Leap year: " << (isLeapYear(year) ? "YES" : "NO") << endl;

    test(year);             // Divisibility tests

    return 0;
}

/**
 * @brief       - Returns a boolean value, indicating whether the year is leap (true) or not (false) 
 * 
 * @param       - int representing the year 
 */
bool isLeapYear(int year) {

    if (year % 100 != 0) {
        if (year % 4 == 0)      // The year is divisible by 4 but not by 100
            return true;
        else                    // The year is neither divisible by 100 nor by 400
            return false;
    } else {                    // The year is divisible by 100
        if (year % 400 == 0)    // The year is divisible by 100 and 400
            return true;
        else                    // The year is divisible by 100 but not by 400
            return false;
    }
}

/**
 * @brief       - Prints tests to check if the year is divisible by  4, 100 and 400
 * 
 * @param       - int representig the year 
 */
void test(int year) {

    cout << "\nTESTS:\nDivisible by:" << endl
         << "4\t" << ((year % 4 == 0) ? "YES" : "NO") << endl
         << "100\t" << ((year % 100 == 0) ? "YES" : "NO") << endl
         << "400\t" << ((year % 400 == 0) ? "YES" : "NO") << endl;
}