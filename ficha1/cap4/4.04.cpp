#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief searches an element in a vector (worst case performance -> O(log n))
 *
 * @param v ordered vector
 * @param value searching value
 * @return the index of the searching value in `v` or -1 if it was not found
 */
int binarySearch(const vector<int> &v, int value) {
    int first = 0, last = v.size() - 1;
    int middle = (last - first) / 2;
    bool found = false;

    while (first <= last && !found) {
        middle = (last - first) / 2;

        if (value == v.at(middle)) {        // middle value is the searching value
            found = true;
        } else if (value < middle) {        // middle value is lower than the searching value
            last = middle - 1;
        } else {                            // middle value is higher than the searching value
            first = middle + 1;
        }
    }
    if (found) return middle;               // if the value was found returns the index
    else return -1;
}


/**
 * @brief reads a vector from the user input
 * 
 * @param v empty vector to be filled
 */
void readVector(vector<int> &v) {
    int el;
    while (cin >> el && !cin.eof()) {
        v.push_back(el);
        cin.clear();
        cin.ignore(1000, '\n');
    }
}


/**
 * @brief prints an integer vector
 * 
 * @param v vector
 */
void displayVec(const vector<int> &v) {
    for (auto i : v)
        cout << i << " | ";
    cout << endl;
}


int main() {
    vector<int> numVec;
    int searchEl;

    cout << "Which element do you want to search for ? ";
    cin >> searchEl;
    cout << "Enter the elements of the ordered list (eof to stop)" << endl;
    readVector(numVec);

    sort(numVec.begin(), numVec.end());   // just to make sure the user doesn't input an unordered vector by accident

    cout << "Searching for " << searchEl << " in: ";
    displayVec(numVec);

    int found = binarySearch(numVec, searchEl);

    if (found != -1) {
        cout << "The element was found at position " << found << endl;
    } else {
        cout << "The element was not found!" << endl;
    }
    return 0;
}