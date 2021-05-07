#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

void displayVector(const vector<int> &v);
void readVector(vector<int> &v) ;
size_t findValueInVector(const vector <int> &v, int value, size_t pos1, size_t pos2);
size_t findMultValuesInVector(const vector <int> &v, int value, size_t pos1, size_t pos2, vector<size_t> &index);


int main() {
    vector<int> intVector;
    vector<size_t> occurVec;
    int valueToFind;
    size_t startingInd, endingInd;

    cout << "Insert an element to search and the starting and ending indexes, respectively: ";
    cin >> valueToFind >> startingInd >> endingInd;

    cout << "Input the sequence elements (EOF to stop)" << endl;
    readVector(intVector);          // I read the vector after the other instream calls because by entering eof, the stream is closed permanently

    if (startingInd < 0)
        startingInd = 0;
    else if (endingInd > intVector.size())
        endingInd = intVector.size();


    int numOccurs = findMultValuesInVector(intVector, valueToFind, startingInd, endingInd, occurVec);

    cout << "Original vector: ";
    displayVector(intVector);
    cout << "Number of Overlaps: " << numOccurs << endl;
    cout << "Vector with the overlap indexes: ";
    for_each(occurVec.begin(), occurVec.end(), [](const auto &el) {cout << el << " | ";});
    cout << endl;

    return 0;
}


void readVector(vector<int> &v) {
    int currVal;
    while (!cin.eof()) {
        cout << "Insert a value for: ";
        cin >> currVal;
        v.push_back(currVal);
    }
    v.pop_back();
    cin.clear();
    cin.ignore(1000, '\n');
}

void displayVector(const vector<int> &v) {
    for (auto i : v)
        cout << i << " | ";
    cout << endl;
}




size_t findValueInVector(const vector <int> &v, int value, size_t pos1, size_t pos2) {
    for (int i = pos1; i < pos2; i++) {
        if (v[i] == value)
            return i;
    }
    return -1;
}


size_t findMultValuesInVector(const vector <int> &v, int value, size_t pos1, size_t pos2, vector<size_t> &index) {
    for  (int i = pos1; i < pos2; i++) {
        if (v[i] == value)
            index.push_back(i);
    }
    return index.size();
}
