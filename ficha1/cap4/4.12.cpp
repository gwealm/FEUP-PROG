
/**
 * @file 4.12.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include <climits>
#include <cstdlib>


void readArray(int  *a, size_t nElem);
void displayArray(int  *a, size_t nElem);
int findValueInArray(const int value, const int *pos1, const int *pos2);
int findMultValueInArray(const int *pos1, const int *pos2, size_t, int value, size_t *index);


int main() {
    size_t size;

    std::cout << "Insert the size of the array: ";
    std::cin >> size;

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    int *numArray = (int *) malloc(size * sizeof(int));

    readArray(numArray, size);
    displayArray(numArray, size);

    char wantSearch;

    std::cout << "Do you want to search an element ['y'/'n'] ? ";
    std::cin >> wantSearch;

    std::cin.clear();
    std::cin.ignore(1000, '\n');

    if (tolower(wantSearch) == 'y') {
        int searchEl, lowerIdx, upperIdx;

        std::cout << "Insert the element to search: ";
        std::cin >> searchEl;
        std::cout << "Insert the lower and upper search indexes: ";
        std::cin >> lowerIdx >> upperIdx;

        std::cin.clear();
        std::cin.ignore(1000, '\n');

        if (lowerIdx < 0)
            lowerIdx = 0;
        else if (upperIdx > size)
            upperIdx = size;

        int foundVal = findValueInArray(searchEl, numArrary[lowerIdx], numArray[upperIdx]);

        if (foundVal == -1) {
            std::cout << "Value was not found!" << std::endl;
            free(numArray);
        } else {
            int *occurArray = (size_t *) malloc(size * sizeof(int));          // initializing array that will contain the indexes of the overlapping occurrences
            int numOccur = findMultValueInArray(numArray, searchEl, lowerIdx, upperIdx, occurArray);

            std::cout << "Value was firstly found at index " << foundVal << std::endl;
            std::cout << "Total number of occurrences: " << numOccur << std::endl;

            for (int w = 0; w < size; w++) {
                std::cout << occurArray[w] << " | ";
            }
            std::cout << std::endl;

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
    void readArray(int *a, size_t nElem) {
        for (int i = 0; i < nElem; i++) {
            std::cout << "Insert the element number " << i << ": ";
            std::cin >> a[i];
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }


/**
 * @brief displays the array's elements
 *
 * @param a     - array
 * @param nElem - number of elements of the array
 */
    void displayArray(int *a, size_t nElem) {
        std::cout << "Array: ";
        for (int i = 0; i < nElem; i++) {
            std::cout << a[i] << " | ";
        }
        std::cout << std::endl;
    }


/**
 * @brief finds the first occurrence of `value` in `a` between the indexes `pos1` and `pos2`
 *
 * @param a array of ints
 * @param value value to find
 * @param pos1 lower search index
 * @param pos2 upper search index
 * @return int the index of the first occurrence of `value` or -1 if there's no one
 */
    int findValueInArray(int value, const int *pos1, const int *pos2) {
        int cont = 0;
        for (int *i = pos1; i <= pos2; i++) {
            if (*i == value) { return cont; }
            cont++;
        }
        return -1;
    }


/**
 * @brief returns the number of overlaps of `value` in the array `a`
 *
 * @param value value to find
 * @param pos1 pointer to lower search index
 * @param pos2 pointer to upper search index
 * @param index array which will contain the elements of `nElem` that overlap with `value`
 * @return int the number of occurrences of `value`
 */
    int findMultValueInArray(int value, const int *pos1, int *pos2, size_t *index) {
        int cont = 0, counter = 0;
        for (int *i = pos1; i < pos2; i++) {
            index[counter] = 0;
            if (*i == value) {
                index[counter] = *i;
                cont++;
            }
            counter++;
        }
        return cont;
    }