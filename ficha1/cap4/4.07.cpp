#include <iostream>
#include <vector>

using namespace std;

// Global Variables
const int NE = 5;                       // Dimensions of the matrix


bool isInBounds(const vector<int> &pos) {
    // Returns true if inside maze bounds, otherwise false
    return (pos.at(0) >= 0 && pos.at(0) < NE && pos.at(1) >= 0 && pos.at(1) < NE);
}


bool isInCorner(const vector<int> &pos) {
    // Returns true if the position passed through the parameter is on a corner column or row of the maze 
    return (pos.at(0) == 0 || pos.at(0) == NE - 1 || pos.at(1) == 0 || pos.at(1) == NE - 1);
}


void findNear(const vector<int> currPos, vector<vector<int>> &adjPos) {
    int x = currPos.at(0), y = currPos.at(1);
    vector<vector<int>> aux = {
                                {y-1, x-1}, {y-1, x}, {y-1, x+1},
                                {y, x-1},             {y, x+1}  ,
                                {y+1, x-1}, {y+1, x}, {y+1, x+1},
                              };
    for (int i = 0; i < aux.size(); i++) {
        if (isInBounds({aux.at(i).at(0), aux.at(i).at(1)})) {adjPos.push_back(aux.at(i));}
    }
}


bool isLocalMax(const int a[][NE], const vector<int> currPos) {
    // Checks if the value is a local maxima
    int x = currPos.at(0), y = currPos.at(1);
    vector<vector<int>> adjacentPositions;
    findNear({x, y}, adjacentPositions);

    for (auto pos : adjacentPositions) {
        if (a[y][x] < a[pos.at(0)][pos.at(1)]) {return false;}
    }

    return true;
}


void getlocalMax(const int a[][NE], vector<vector<int>> &localMaxVec, bool allMaxima) {
    /*
     * Gets a vector with all the local maximas 
     * {{a, b}, {c, d}, ...}
     */
    vector<vector<int>> localMax;
    for (int y = 0; y < NE; y++) {
        for (int x = 0; x < NE; x++) {
            if (!allMaxima) {
                if (isLocalMax(a, {x, y}) && !isInCorner({x, y})) {localMaxVec.push_back({y, x});}
            } else {
                if (isLocalMax(a, {x, y})) {localMaxVec.push_back({y, x});}
            }
        }
    }
}


void displayMatrix(int matrix[][NE]) {
    // Displays a square matrix
    for (int i = 0; i < NE; i++) {
        for (int j = 0; j < NE; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    // Matrix
    int matrix[NE][NE] = {
                            {7, 3, 4, 1, 3},
                            {2, 9, 6, 2, 1},
                            {1, 3, 5, 1, 4},
                            {6, 5, 2, 7, 5},
                            {4, 2, 1, 3, 6}
                            };
    vector<vector<int>> localMaxVec;


    char userInput;                                                             // Char to track if the user wants or not all local maxima
    cout << "Do you want all local maxima to be displayed? ['y'/'n'] ";
    cin >> userInput;


    if (!cin.eof() && cin.good() && cin.peek() == '\n') {

        char lowerCase = static_cast<char> (tolower(userInput));                // Converts the input char to lowercase

        if (lowerCase == 'y' || lowerCase == 'n') {
            bool allMaxima = lowerCase == 'y' ? true : false;

            displayMatrix(matrix);                                              // Displays the matrix
            getlocalMax(matrix, localMaxVec, allMaxima);                        // Gets the local maxima list

            // Displaying the Local maxima points
            cout << "\nLocal Maximum Points: \n{" << endl;
            for (auto point : localMaxVec) {
                cout << "\t(" << point.at(0) << ", " << point.at(1) << ") ->"
                        << matrix[point.at(0)][point.at(1)] << ";" << endl;
            }
            cout << "}" << endl;

        } else {                                                                // Valid input, but not 'y' or 'n'
            cerr << "Invalid input\n";
        }

    } else {                                                                    // Invalid input
        cerr << "Invalid input\n";
    }
    return 0;
}