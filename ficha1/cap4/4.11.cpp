#include <iostream>
#include <stdlib.h>


void displayArr(int arr[], size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


constexpr int cmp(int a, int b) {
    // Comparator to sort in ascending order
    if (a < b) {
        return -1;
    } else if (a == b) {
        return 0;
    } else {
        return 1;
    }
}


constexpr int cmp2(int a, int b) {
    // Comparator to sort in descending order
    if (a < b) {
        return 1;
    } else if (a == b) {
        return 0;
    } else {
        return -1;
    }
}


int main() {
    int arr[] = {10, 2, 1, 3, 5, 4, 7, 6, 9, 8};
    const int SIZE = 10;

    // Ascending order
    qsort(arr, SIZE, sizeof(int), [](const void *n1, const void *n2){ return cmp(*(int*)n1, *(int*)n2); });
    displayArr(arr, SIZE);

    // Descending order
    qsort(arr, SIZE, sizeof(int), [](const void *n1, const void *n2){ return cmp2(*(int*)n1, *(int*)n2); });
    displayArr(arr, SIZE);


    //Sorting halfs independently
    qsort(arr, SIZE/2, sizeof(int), [](const void *n1, const void *n2){ return cmp(*(int*)n1, *(int*)n2); });
    qsort(arr + 5, SIZE/2, sizeof(int), [](const void *n1, const void *n2){ return cmp(*(int*)n1, *(int*)n2); });
    displayArr(arr, SIZE);
}