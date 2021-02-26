#include <iostream>

using namespace std;


void bubbleSort(int arr[], int arrSize) {
    bool sorted = false;

    // The following while-loop will happen until we have an iteration where the array is fully sorted
    while (!sorted) {
        sorted = true;
    
        // The following loop iterates through the loop and swaps following positions if they're not sorted
        for (int i = 0; i < arrSize - 1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
                sorted = false;    
            }
        }
    }
}


int main() {

    const unsigned int ARRAY_LENGTH = 3;    // Constant containing the length of the array

    int inputArr[ARRAY_LENGTH];
    bool sorted = false;

    //The following loop will iterate as many times as the number of elements of the array and will ask
    // for values to fill in the elements of the array
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        cout << "Insert value number " << i + 1 << ": ";
        cin >> inputArr[i];
    }

    bubbleSort(inputArr, ARRAY_LENGTH); // Sorting the array in ascending order

    // First part of the exercise

    cout << "\nSmallest value: " << inputArr[0] << endl; 
    cout << "Biggest value: " << inputArr[ARRAY_LENGTH - 1] << endl; //The last element of the array (with index ARRAY_LENGTH - 1) will have the highest value

    // Second part of the exercise

    cout << "\nValues sorted in ascending order:" << endl;

    for (int i = 0; i < ARRAY_LENGTH; i++)
        cout << "Value " << i + 1 << ": " << inputArr[i] << endl;

    // Third part of the exercise 

    cout << endl;   // Works as a separator, since I decided to make exercises a, b and c on the same file

    if (inputArr[0] < 0)  // Since the values of inputArr are ordered we only need to check if the 1st one is negative, and if it isn't, all of them are positive
        cerr << "Invalid values. The length of the triangle sides can't be negative.\n";

    else {
        if (inputArr[0] + inputArr[1] < inputArr[2])
            cout << "The values can't form a triangle" << endl;
        else
            cout << "The values form a triangle" << endl;
    }

    return 0;
}