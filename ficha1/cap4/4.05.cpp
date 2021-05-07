#include <iostream>
#include <vector>


using namespace std;


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


void displayVector(const vector<int> &vec) {
    for (auto i : vec) {
        cout << i << " | ";
    }
    cout << endl;
}

int main() {
    // Vector to remove duplicates
    vector<int> vec = {1, 2, 3, 1, 4, 5, 2, 6, 4, 7, 7, 8, 9, 10};

    removeDuplicates(vec);      // Removing duplicates

    displayVector(vec);         // Displays the vector

    return 0;
}