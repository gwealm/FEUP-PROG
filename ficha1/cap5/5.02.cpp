#include <iostream>
#include <vector>
#include <string>


void bubbleSort(std::vector<std::string> &v, char order = 'a') {
    // there are only going to be needed numberofElements - 1 outer iterations to fully sort the list (worst case)
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (order == 'a') {                     // ascending order
                if (v.at(j) > v.at(j + 1))
                    swap(v.at(j), v.at(j + 1));
            } else {                                // if the user sends an order that is not supported the function just orders by ascending order (default)
                if (v.at(j) < v.at(j+1))
                    swap(v.at(j), v.at(j + 1));
            }
        }
    }
}


void displayVec(std::vector<std::string> strVec) {
    for (auto i : strVec) {
        std::cout << i << " | ";
    }
    std::cout << std::endl;
}

void readVector(std::vector<std::string> &nameVec) {
    std::string name;
    std::cout << "Insert a name (EOF to stop): ";
    while (std::cin >> name && !std::cin.eof()) {
        std::cout << "Insert a name (EOF to stop): ";
        nameVec.push_back(name);
    }
    std::cout << std::endl;
}

int main() {

    char order;
    std::cout << "Sort by ascending or descending order ['a', 'd']: " << std::flush;
    std::cin >> order;

    order = static_cast<char>(tolower(order));

    if (order != 'a' && order != 'd') {
        std::cerr << "Bad input!\n";
        return -1; 
    }


    // Reading the vector
    std::vector<std::string> strVec;
    readVector(strVec);

    // Sorting
    bubbleSort(strVec, order);

    // Displaying the vector
    displayVec(strVec);

    return 0;
}