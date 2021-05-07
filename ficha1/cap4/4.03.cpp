#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/**
 * @brief sorts the function by ascending or descending order
 * 
 * @param v int vector
 * @param order 'a' for ascending order; 'd' (or any other character) for descending
 */
void bubbleSort(vector<int> &v, char order = 'a') {
    // there are only going to be needed numberofElements - 1 outer iterations to fully sort the list (worst case)
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (order == 'a') {                     // ascending order
                if (v.at(j) > v.at(j + 1))
                    swap(v.at(j), v.at(j + 1));
            } else {                                // if the user sends an order that is not supported the function just orders by ascending order (default)
                if (v.at(j) < v.at(j+1))
                    swap(v.at(j), v.at(j + 1));
            }
        }
    }
}


/**
 * @brief Sorts a list depending on the order defined by `bool f(int, int)`
 * 
 * @param v int vector
 * @param f boolean function that sets the sorting order
 */
void bubbleSortV2(vector<int> &v, bool f(int x, int y)) {
    bool notSorted = true;
    while (notSorted) {
        notSorted = false;
        for (int i = 0; i < v.size() - 1; i++) {
            int curr = v.at(i);
            int next = v.at(i + 1);
            if (f(curr, next)) {
                swap(v.at(i), v.at(i + 1));
                notSorted = true;
            }
        }
    }
}


int main() {
    // tests for the first bubbleSort method
    vector<int> intVect = {3, 4, 5, 21, 9, 1, 4, 0}; //Sorted would be {0, 1, 3, 4, 4, 5, 9, 21}
    bubbleSort(intVect, 'd');
    for_each(intVect.begin(), intVect.end(), [](const auto &el) {cout << el << " | ";});

    cout << endl;       // input separator

    // tests for the second bubbleSort method
    bubbleSortV2(intVect, [](int x, int y) {return x > y;});
    for_each(intVect.begin(), intVect.end(), [](const auto &el) {cout << el << " | ";});
	cout << endl;

	return 0;
}