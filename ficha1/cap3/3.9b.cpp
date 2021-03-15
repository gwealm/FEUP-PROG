#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

bool isLeapYear(int year);
int numberOfDays(int month, int year);

int main() {

    int year;
    string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    cout << "Insert an year: ";
    cin >> year;

    for (int i = 0; i < 12; i++) {
        if (i == 11)
            cout << month[i] << endl;
        else
            cout << month[i] << setw(8);
    }

    for (int i = 1; i <= 12; i++)
        cout << numberOfDays(i, year) << setw(8);
    
    cout << endl;

    return 0;
}

/**
 * @brief       - Returns a boolean value, indicating wheter the year is leap (true) or not (false) 
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
 * @brief       - Returns the number of days of a given month in a given year
 * 
 * @param       - int representing the month 
 * @param       - int representing the year 
 * @return      - int representing the number of days 
 */
int numberOfDays(int month, int year) {
    bool isLeap = isLeapYear(year);  // Checks if the year is or not leap

    if (1 <= month <= 12) {         // Valid month number
        if (month != 2) {
        if (month == 1 ||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)     // Months of 31 days
                return 31;
            else                    // Months of 30 days
                return 30;
        } else {                    // Month is February
            if (isLeap)             // February in a leap year (29 days)
                return 29;
            else                    // February in a non-leap year
                return 28;
        }
    } else {                        // Invalid month number
        return -1;                  // Error sign for bad input
    }
}