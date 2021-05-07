#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <string>

// Typedefs
typedef std::vector<std::vector<uint>> pluv;
typedef std::pair<uint, uint> date; 

// Global Variables
const uint MAX_PLUV = 250; // In percentage
std::vector<std::string> monthNames = {
    "January", 
    "February",
    "March", 
    "April", 
    "May", 
    "June", 
    "July", 
    "August", 
    "September", 
    "October", 
    "November", 
    "December"};


// Functions
bool isLeapYear(int year);
int numberOfDays(int month, int year);
pluv readPluviosityData(int year);
float getMonthlyAvg(const std::vector<uint> &monthPluv);
float getDailyAvg(const pluv &yearlyPluv);
std::vector<date> getAboveAvgDates(const pluv &yearlyPluv);
std::vector<date> getMaxDates(const pluv &yearlyPluv);
void displayDate(date date);

int main() {

    const std::string SEP = "----------------------------------";
    int year;
    

    std::cout << "Insert a year: ";
    std::cin >> year;

    // Bad input
    if (std::cin.bad() || std::cin.peek() != '\n' || std::cin.eof()) {
        std::cerr << "Bad input!\n";
        return -1;
    }

    std::cout << std::fixed << std::setprecision(3);

    pluv yearPluv = readPluviosityData(year);

    std::cout << "Daily pluv average: " << getDailyAvg(yearPluv) << std::endl;
    std::cout << SEP << std::endl;
    std::cout << "Monthly averages:" << std::endl;

    for (int i = 0; i < 12; i++) {
        std::cout << monthNames.at(i) << ": " << getMonthlyAvg(yearPluv.at(i)) << std::endl;
    }

    std::cout << SEP << std::endl;
    std::cout << "Dates with pluv above average:";
    for (date date : getAboveAvgDates(yearPluv)) {displayDate(date);}


    std::cout << SEP << std::endl;
    std::cout << "Dates with the maximum pluv:";
    for (date date2 : getMaxDates(yearPluv)) {displayDate(date2);}

    return 0;
}


/**
 * @brief Returns a boolean value, indicating whether the year is leap (true) or not (false) 
 * 
 * @param int representing the year 
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
 * @brief Returns the number of days of a given month in a given year
 * 
 * @param int representing the month 
 * @param int representing the year 
 * @return int representing the number of days 
 */
int numberOfDays(int month, int year) {
    bool isLeap = isLeapYear(year);  // Checks if the year is or not leap

    if (0 <= month <= 11) {         // Valid month number
        if (month != 1) {
            if (month == 0 ||month == 2||month == 4||month == 6||month == 7||month == 9 ||month == 11)     // Months of 31 days
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
 * @brief Returns a random list of the yearly pluviousity rates (%)
 * 
 * @param year int representing the year 
 * @return vector<vector<int>> 
 */
pluv readPluviosityData(int year) {
        
    pluv yearlyPluvVals;
    for (int cont = 0; cont < 12; cont++) {
        int monthDays = numberOfDays(cont, year);
        std::vector<uint> currMonth;
        for (int j = 0; j < monthDays; j++) {
            int randPluv = rand() % (MAX_PLUV + 1);
            currMonth.push_back(randPluv);
        }
        yearlyPluvVals.push_back(currMonth);
    }

    return yearlyPluvVals;
}


/**
 * @brief Calculates the monthly pluv average
 * 
 * @param monthPluv 
 * @return float 
 */
float getMonthlyAvg(const std::vector<uint> &monthPluv) {
    uint pluvSum = 0;
    for (int i = 0; i < monthPluv.size(); i++) {
        pluvSum += monthPluv.at(i);
    }
    return static_cast<float>(pluvSum) / monthPluv.size();
}


/**
 * @brief Get the Daily pluv average
 * 
 * @param yearlyPluv 
 * @return float 
 */
float getDailyAvg(const pluv &yearlyPluv) {
    uint dayCont = 0, pluvSum = 0;
    for (auto monthPluv : yearlyPluv) {
        for (auto dayPluv : monthPluv) {
            pluvSum += dayPluv;
            dayCont++;
        }
    }
    return static_cast<float>(pluvSum) / dayCont;
}


/**
 * @brief Get the Dates above the average pluv
 * 
 * @param yearlyPluv 
 * @return std::vector<date> 
 */
std::vector<date> getAboveAvgDates(const pluv &yearlyPluv) {
    std::vector<date> dates;
    float average = getDailyAvg(yearlyPluv);

    for (int i = 0; i < yearlyPluv.size(); i++) {
        for (int j = 0; j < yearlyPluv.at(i).size(); j++) {
            float dayPluv = yearlyPluv.at(i).at(j);                   // The pluv of the day `j` of month `i`
            if (dayPluv > average) {dates.push_back({j, i});}
        }
    }
    return dates;
}


/**
 * @brief Get the Max pluv dates
 * 
 * @param yearlyPluv 
 * @return std::vector<date> 
 */
std::vector<date> getMaxDates(const pluv &yearlyPluv) {
    std::vector<date> dates;

    for (int i = 0; i < yearlyPluv.size(); i++) {
        for (int j = 0; j < yearlyPluv.at(i).size(); j++) {
            float dayPluv = yearlyPluv.at(i).at(j);                   // The pluv of the day `j` of month `i`
            if (dayPluv == MAX_PLUV) {dates.push_back({j, i});}
        }
    }
    return dates;
}


/**
 * @brief Displays a date
 * 
 * @param date std::pair<int, int> 
 */
void displayDate(date date) {
    std::cout << std::setfill('0') << std::setw(2) << date.first + 1 << " of " << monthNames.at(date.second) << std::endl;
}