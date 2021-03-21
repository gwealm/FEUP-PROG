#include <iostream>

using namespace std;

void readArray(int a[], size_t nElem);
int findValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2);
int findMultValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]);

int main() {

    int size, needle, lb, ub;
    int arr[1000];
    size_t matchIndex[1000];

    cout << "What's the size of the array? ";
    cin >> size;

    readArray(arr, size);

    cout << "Insert the element you want to search: ";
    cin >> needle;

    cout << "Insert, respectively a lower and an upper bound: ";
    cin >> lb >> ub;

    if (ub > size)
        ub = size;
    if (lb < 0)
        lb = 0;

    int firstFound = findValueInArray(arr, size, needle, lb, ub); 

    if (firstFound != -1) {
        cout << "The item was first found in position " << firstFound << endl;

        int numOfItems = findMultValueInArray(arr, size, needle, lb, ub, matchIndex);
        for (int i = 0; i < numOfItems; i++)
            cout << "All of the matching indexes: " << matchIndex[i] << "  ";
        cout << endl;

    } else {
        cout << "The item was not found" << endl;
    }

    return 0;
}


void readArray(int a[], size_t nElem) {
    for (int i = 0; i < nElem; i++) {
        cin >> a[i];
        cin.clear();
        cin.ignore(1000,'\n');
    }
}


int findValueInArray(const int a[], size_t nElem, int value, size_t pos1=0, size_t pos2=1000) {
    for (int i = pos1; i <= pos2; i++) {
        if (a[i] == value)
            return i;
    }
    return -1;
}


int findMultValueInArray(const int a[], size_t nElem, int value, size_t pos1, size_t pos2, size_t index[]) {
    int cont = 0;
    for (int i = pos1; i <= pos2; i++) {
        if (a[i] == value) {
            index[cont] = i;
            cont++;
        }
    }
    return cont;
}
