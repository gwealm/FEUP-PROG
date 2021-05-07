#include <iostream>
#include <string>
#include <vector>


void removeSpaces(std::string name, std::vector<std::string> &nameParts) {
    std::string aux;

    for (auto chr : name) {
        if (isspace(chr)) {                     // Char is ' '
            // If the name is valid it is appended to the vector `nameParts`
            if (aux.size() != 0 && aux != "DE" && aux != "DO" && aux != "DA" && aux != "DOS" && aux != "DAS" && aux != "E") { 
                nameParts.push_back(aux);
            }
            aux.clear();                        // clear auxiliar substring container
        } else if (!isspace(chr)) {             // Char is different from ' '
            if (chr >= 'a' && chr <= 'z')
                aux += toupper(chr);            // Converting lower to uppercase
            else 
                aux += chr;
        }
    }
}


std::string normalizeName(const std::string &name) {
    std::string normalizedName;
    std::vector<std::string> aux;
    removeSpaces(name, aux);
    for (auto part : aux) { normalizedName += part + " "; }

    return normalizedName;
    // removes the last space
    return normalizedName.substr(0, normalizedName.size() - 1);

}


int main() {
    std::string name = "     Maria  da  Felicidade   dos Reis e Passos Dias de Aguiar   ";
    std::string normalizedName = normalizeName(name);
    std::cout << normalizedName << std::endl;

    return 0;
}