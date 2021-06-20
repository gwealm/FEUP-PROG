#include "Date.h"

Date::Date() {
	time_t t = time(0);		// current time
	tm* now = localtime(&t);
	setDate(now->tm_year + 1900, now->tm_mon, now->tm_mday);
}


Date::Date(unsigned int year, unsigned int month, unsigned int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}


Date::Date(string yearMonthDay) {
	unsigned int year, month, day;
	char sep = '/';
	istringstream parseStream(yearMonthDay);
	parseStream >> year >> sep >> month >> sep >> day;
	setDate(year, month, day);
}


void Date::setYear(unsigned int year) {
	this->year = year;
}


void Date::setMonth(unsigned int month) {
	this->month = month;
}


void Date::setDay(unsigned int day) {
	this->day = day;
}


void Date::setDate(unsigned int year, unsigned int month, unsigned int day) {
	setDay(day);
	setYear(year);
	setMonth(month);
}


unsigned int Date::getYear() const {
	return this->year;
}


unsigned int Date::getMonth() const {
	return this->month;
}


unsigned int Date::getDay() const {
	return this->day;
}


string Date::getDate() const {
	char sep = '/';
	string date = to_string(getYear()) + sep + to_string(getMonth()) + sep + to_string(getDay());
	return date;
}


void Date::show() const {
	cout << getDate() << endl;
}


int Date::getDaysNum() const {

	bool isLeap = isLeapYear(year);		// Checks if the year is or not leap
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	case 2: return 28 + isLeapYear(year);
	default: return -1;

	}
}


bool Date::isValid() const {
	int MAX_DAYS = getDaysNum(), MAX_MONTH = 12, MAX_YEAR = 2022, MIN = 0;
	int day = getDay(), month = getMonth(), year = getYear();

	// The condition bellow checks if the month is invalid, so by negating it we are returning its validity
	return !(day <= MIN || day > MAX_DAYS || month > MAX_MONTH || month <= MIN || year > MAX_YEAR || year <= MIN);
}


bool Date::isLeapYear(int year) const {
	if (year % 100 != 0) {
		return (year % 4 == 0);
	}
	else {                    // The year is divisible by 100
		return (year % 400 == 0);
	}
}