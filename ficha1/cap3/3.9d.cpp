#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool isLeapYear(int year);
int numberOfDays(int month, int year);
int calculateDay(int year, int month, int day);
int calculateC(int month, bool isLeap);
void displayCalendar(int year, int month);

int main() {

    int year, day, month;                               // User input
    char sep;

    cout << "Enter a year and a month (format yy:mm): ";
    cin >> year >> sep >> month;

    displayCalendar(year, month);                       // Displays the calendar

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

/**
 * @brief       - Calculates the day of the week (0-6) that corresponds to a certain date (dd:yy:mm)
 * 
 * @param       - int which represents year 
 * @param       - int which represents month 
 * @param       - int which represents day 
 * @return      - int which represents the day of the week (0-6) 
 */
int calculateDay(int year, int month, int day) {
    int y = year, m = month, d = day;
    int s = y / 100;             // First 2 digits of year
    int a = y % 100;             // Last 2 digits of year
    bool isLeap = isLeapYear(y);
    int c = calculateC(m, isLeap);
    
    int weekdayRes = ((5 * a / 4) + c + d - 2 * (s % 4) + 7) % 7;

    return weekdayRes;
}


/**
 * @brief       - Auxiliar function that receives a month and calculates month code 
 * 
 * @param       - int that represents the month 
 * @return      - int
 */
int calculateC(int month, bool isLeap) {
    
    switch (month) {
        case (1):
            if (isLeap)
                return 6;
            else 
                return 0;
            break;

        case (2):
            if (isLeap)
                return 2;
            else 
                return 3;

        case (3): case (11): return 3;
        case (4): case (7): return 6;
        case (5): return 1;
        case (6): return 4;
        case (8): return 2;
        case (9): case (12): return 5;
        case (10): return 0;
    }
    return -1;                  // Invalid input for month
}

/**
 * @brief       - Displays the calendar of a given month and year
 * 
 * @param       - int (year) 
 * @param       - int (month) 
 */
void displayCalendar(int year, int month) {
    string months[12] = {"Jan", "Feb", "March", "Apr", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    string weekdays[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    
    const int LIMIT = numberOfDays(month, year);

    cout << months[month - 1] << "/" << year << endl;                   // Prints 'Month/Year'

    // Printing the weekday header
    for (int i = 0; i <= 6; i++) {
        if  (i == 6)
            cout << weekdays[i] << endl;
        else
            cout << weekdays[i] << setw(8);
    }

    // Printing the days calendar
    for (int day = 1; day <= LIMIT; day++) {
        
        int weekDay = calculateDay(year, month, day);       // Calculates the equivalent weekday

        if (day == 1) {                                     // First day of the month
            const int WIDTH = weekDay == 0 ? (6 * 8 + 1) : (weekDay - 1) * 8 + 1; // Calculating the initial width of the first day
            if (weekDay == 0)
                cout << setw(WIDTH) << day << endl;
            else
                cout << setw(WIDTH) << day << setw(8);
        } else {                                            // Every other day other than the 1st
            if (weekDay == 0)
                cout << day << endl;
            else if (day == 9)
                cout << day << setw(9); 
            else
                cout << day << setw(8);
        }
    }
    cout << endl;
}
