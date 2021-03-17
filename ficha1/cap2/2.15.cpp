#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {

    time_t start, finish;
    float userTime;
    int userInput, res;

    srand (time(NULL));         // initialize random seed

    // random numbers between 2 and 9 (inclusive)
    int num1 = rand() % 8 + 2;  
    int num2 = rand() % 8 + 2;

    res = num1 * num2;          // the real result

    time(&start);               // starting the timing
    cout << num1 << " x " << num2 << " = ";
    cin >> userInput;
    time(&finish);              // ending the timer

    userTime = difftime(finish, start); // calculating the time that the user took to answer

    if (userInput != res)
        cout << "Very Bad" << endl;
    else if (userTime < 5)
        cout << "Good" << endl;
    else if (userTime >= 5 && userTime <= 10)
        cout << "Satisfactory" << endl;
    else
        cout << "Insufficient" << endl;

    return 0;
}