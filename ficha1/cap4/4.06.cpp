#include <iostream>
#include <vector>


using namespace std;


void displayVector(const vector<int> &v) {
    for (auto i : v) {cout << i << " | ";}
    cout << endl;
}


void removeFromVec(vector<int> &v, unsigned int idxToRemove) {
    const uint VECTOR_LENGTH = v.size();

    for (int i = idxToRemove; i < VECTOR_LENGTH - 1; i++) {
        swap(v.at(i), v.at(i + 1));
    }
    v.resize(VECTOR_LENGTH - 1);
}


void removeDuplicates(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v.at(i) == v.at(j)) {
                removeFromVec(v, j);
            }
        }
    }
}


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


void vectorUnion(const vector<int> &v1, const vector<int> &v2, vector<int> &v3) {
    v3 = v1;                                                        // Shallow copy of v1
    v3.insert(v3.end(), v2.begin(), v2.end());                      // Appends v2 to v3
    removeDuplicates(v3);                                           // Removes duplicates from v3
    return bubbleSortV2(v3, [](int n1, int n2){return n1 > n2;});   // sorts v3
}


void vectorIntersections(const vector<int> &v1, const vector<int> &v2, vector<int> &v3) {
    vector<int> v4 = v1;
    v4.insert(v4.end(), v2.begin(), v2.end());
    bubbleSortV2(v4, [](int n1, int n2) {return n1 > n2;});

    for (int i = 0; i < v4.size() - 1; i++) {
        if (v4.at(i) == v4.at(i + 1)) { v3.push_back(v4.at(i));}
    }
    bubbleSortV2(v3, [](int n1, int n2) {return n1 > n2;});
}



int main() {
    // Vector initializations
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {2, 4, 5, 6, 7, 8};
    vector<int> intersectionVec;

    // Displaying the results
    cout << "Vector 1: ";
    displayVector(v1);

    cout << "Vector 2: ";
    displayVector(v2);


    // Function calls
    vectorIntersections(v1, v2, intersectionVec);

    cout << "Intersection: ";
    displayVector(intersectionVec);

    intersectionVec.clear();

    vectorUnion(v1, v2, intersectionVec);
    cout << "Union: ";
    displayVector(intersectionVec);

    return 0;
}