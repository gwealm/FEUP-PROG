#include <iostream>
#include <cstring>


constexpr int comparator(const void *a, const void *b) {
    const char *A = *(const char**)a;
    const char *B = *(const char**)b;

    return strcmp(A, B);
}


void displayArr(const char *strVec[], const int size) {
    for (int i = 0; i < size; i++) {
        std::cout << strVec[i] << " | ";
    }
    std::cout << std::endl;
}


int main() {

    const int SIZE = 5;
    // Vector
    const char *strArr[] = {"Gui", "Ajj", "Cdd", "Abc", "ZZZ"};

    // Sorting
    qsort(strArr, SIZE, sizeof(const char *), comparator);

    // Displaying the vector
    displayArr(strArr, SIZE);

    return 0;
}