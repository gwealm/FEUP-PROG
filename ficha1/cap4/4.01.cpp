#include <iostream>
#include <climits>
#include <cstdlib>

using namespace std;

void readArray(int  a[], size_t nElem);
void displayArray(int  a[], size_t nElem);
int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2);
int findMultValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]);


int main() {
    size_t size;

    cout << "Insert the size of the array: ";
    cin >> size;

    cin.clear();
    cin.ignore(1000, '\n');

    int *numArray = (int *) malloc(size * sizeof(int));

    readArray(numArray, size);
    displayArray(numArray, size);

    char wantSearch;

    cout << "Do you want to search an element ['y'/'n'] ? ";
    cin >> wantSearch;

    cin.clear();
    cin.ignore(1000, '\n');

    if (tolower(wantSearch) == 'y') {
        int searchEl, lowerIdx, upperIdx;

        cout << "Insert the element to search: ";
        cin >> searchEl;
        cout << "Insert the lower and upper search indexes: ";
        cin >> lowerIdx >> upperIdx;

        cin.clear();
        cin.ignore(1000, '\n');

        if (lowerIdx < 0)
            lowerIdx = 0;
        else if (upperIdx > size)
            upperIdx = size;

        int foundVal = findValueInArray(numArray, size, searchEl, lowerIdx, upperIdx);

        if (foundVal == -1) {
            cout << "Value was not found!" << endl;
            free(numArray);
        } else {
            size_t *occurArray = (size_t *) malloc(size * sizeof(int));          // initializing array that will contain the indexes of the overlapping occurrences
            int numOccur = findMultValueInArray(numArray, size, searchEl, lowerIdx, upperIdx, occurArray);

            cout << "Value was firstly found at index " << foundVal << endl;
            cout << "Total number of occurrences: " << numOccur << endl;

            for (int w = 0; w < size; w++) {
                cout << occurArray[w] << " | ";
            }
            cout << endl;

            // deallocate heap memory
            free(occurArray);
            free(numArray);
        }
    }
    return 0;
}
/**
 * @brief Sets the array's elements
 *
 * @param a     - array
 * @param nElem - number of elements of the array
 */
    void readArray(int a[], size_t nElem) {
        for (int i = 0; i < nElem; i++) {
            cout << "Insert the element number " << i << ": ";
            cin >> a[i];
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }


/**
 * @brief displays the array's elements
 *
 * @param a     - array
 * @param nElem - number of elements of the array
 */
    void displayArray(int a[], size_t nElem) {
        cout << "Array: ";
        for (int i = 0; i < nElem; i++) {
            cout << a[i] << " | ";
        }
        cout << endl;
    }


/**
 * @brief finds the first occurrence of `value` in `a` between the indexes `pos1` and `pos2`
 *
 * @param a array of ints
 * @param nElem size of the array
 * @param value value to find
 * @param pos1 lower search index
 * @param pos2 upper search index
 * @return int the index of the first occurrence of `value` or -1 if there's no one
 */
    int findValueInArray(const int a[], size_t nElem, int value, size_t pos1 = 0, size_t pos2 = ULLONG_MAX) {
        for (int i = pos1; i < pos2; i++) {
            if (a[i] == value)
                return i;
        }
        return -1;
    }


/**
 * @brief returns the number of overlaps of `value` in the array `a`
 *
 * @param a array of ints
 * @param nElem size of the array
 * @param value value to find
 * @param pos1 lower search index
 * @param pos2 upper search index
 * @param index array which will contain the elements of `nElem` that overlap with `value`
 * @return int the number of occurrences of `value`
 */
    int findMultValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]) {
        int cont = 0;
        for (int i = 0; i < nElem; i++) {
            index[i] = 0;
            if (a[i] == value) {
                index[cont] = i;
                cont++;
            }
        }
        return cont;
    }