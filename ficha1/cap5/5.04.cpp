#include <iostream>
#include <string>


bool sequenceSearch(const std::string &s, int nc, char c) {
    bool search = false;
    int appear = 0;
    for (int i = 0; i < s.size(); i++) {
        char currChar = s.at(i);

        if (search) {                   // flag on
            if (currChar == c) {        // match
                appear++;
            } else {                    // reset flag and counter
                search = false;
                appear = 0;
            }
        } else {                        // flag off
            if (currChar == c) {        // match
            search = true;
            appear++;
            }
        }

        if (appear >= nc) { return true; }
    }

    return false;
}


bool sequenceSearch2(const std::string &s, int nc, char c) {
    std::string aux;
    for (int i = 0; i < nc; i++) { aux += c; }                  // creating string with char `c`, nc times
    size_t found = s.find(aux);

    // if the substring was found the index was returned, if not std::string::npos was
    return found != std::string::npos;
}


int main() {
    std::cout << sequenceSearch2("abcddeedddf", 3, 'd') << std::endl;
    std::cout << sequenceSearch2("abcddeedddf", 4, 'd') << std::endl;
    return 0;
}