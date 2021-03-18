#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

time_t timeElapsed();
void displayVec(const vector<long int> &v);

int main() {

    time_t currTime, secTime;           // Variables to save, respectively the first time and the "second" time
    vector<long int> timeDiffs;         // Initializing a vector to save the time diffs
    string inp;

    cout << "Press any key to start the counter: ";
    cin >> inp;
    currTime = timeElapsed();           // Saving the first time

    while (true) {

        cout << "Insert anything to continue (ctrl + D to stop) ";
        cin >> inp;

        if (cin.eof())                   // Breaks the cycle if EOF is found
            break;
        
        secTime = timeElapsed();          // Saving the second time
        
        long int timeDiff = secTime - currTime;
        timeDiffs.push_back(timeDiff);
    }

    displayVec(timeDiffs);

    return 0;

}



/**
 * @brief       - returns the current time
 * 
 * @return      - time_t 
 */
time_t timeElapsed() {
    time_t currTime = time(NULL);
    return currTime;
}

/**
 * @brief       - displays vectors elements, separated by a ','
 * 
 * @param       - vector<long int>  
 */
void displayVec(const vector<long int> &v) {
    const int SIZE = v.size();

    for (int i = 0; i < SIZE; i++) {
        if (i == SIZE - 1)          // If it is the last item prints the element of the vector
            cout << v[i];
        else
            cout << v[i] << ", ";   // Prints the element of the array with index i followed by a ', ' 
    }
    cout << '\n';
}