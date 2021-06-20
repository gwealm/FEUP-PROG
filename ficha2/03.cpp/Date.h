#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

class Date {
public:
	Date(unsigned int year, unsigned int month, unsigned int day);
	Date(string yearMonthDay);						// yearMonthDay must be in format "yyyy/mm/dd"
	Date();
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	void setDate(unsigned int year, unsigned int month, unsigned int day);
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	string getDate() const;							// returns the date in format "yyyy/mm/dd"   
	void show() const;								// shows the date on the screen in format "yyyy/mm/dd" 
	bool isValid() const;
private:
	int getDaysNum() const;
	bool isLeapYear(int year) const;
	unsigned int year;
	unsigned int month;
	unsigned int day;
};