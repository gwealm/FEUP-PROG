#include <iostream>
#include <iomanip>


struct Date {
    unsigned int year, month, day;
};


void readDate(Date *d);
void writeDate(const Date *d);
void sortDates(Date *d1, Date *d2);
int compareDates(const Date *d1, const Date *d2);


int main() {
    Date d1, d2;

    // Reading the dates
    readDate(&d1);
    readDate(&d2);

    // Sorting the dates
    sortDates(&d1, &d2);

    // Printing the dates
    writeDate(&d1);
    writeDate(&d2);
}


void readDate(Date *d) {
    char sep = '/';
    std::cout << "Insert a date in the format YYYY/MM/DD: ";
    std::cin >> d->year >> sep >> d->month >> sep >> d->day;
}


void writeDate(const Date *d) {
    char sep = '/';
    std::cout << std::setfill('0') << d->year << sep << std::setw(2) << d->month
              << sep << std::setw(2) << d->day << std::endl;
}


void sortDates(Date *d1, Date *d2) {
    if (compareDates(d1, d2) == 1) {
        // If the dates are not sorted, changes their positions
        Date aux{*d1};
        *d1 = *d2;
        *d2 = aux;
    }
}


int compareDates(const Date *d1, const Date *d2) {

    if (d1->year == d2->year) {                         // same year
        if (d1->month == d2->month) {
            if (d1->day == d2->day) return 0;           // same date
            else {
                
                int res = (d1->day < d2->day ? -1 : 1);
                std::cout << "KEK: "<< res << std::endl;
                return res;
            }  
        } else {
            int res = (d1->month < d2->month ? -1 : 1);
            return res;
        }
    } else {                                            // different years
        int res = (d1->year < d2->year ? -1 : 1);
        return res;
    }
}