#include <iostream>
#include <string>
#include <cstring>


char encryptChar(char c, int key) {
    if (c == ' ') { return c; }

    if (key > 0) {              // Positive key
        if (isupper(c)) {       // Uppercase
            return static_cast<char>((c + key - 65) % 26 + 65);
        } else {                // Lowercase
            return static_cast<char>((c + key - 97) % 26 + 97);
        }
    } else {                    // Negative key
        int aux = 0;            // additional value to be summed if the result is negative
        if (isupper(c)) {       // Uppercase
            int result = ((c + key - 65) % 26);
            if (result < 0) { aux += 26; }
            return static_cast<char>(result + aux + 65);
        } else {                // Lowercase
            int result = ((c + key - 97) % 26);
            if (result < 0) { aux += 26; }
            return static_cast<char>(result + aux + 97);
        }
    }
}

char* encryptString(const char *str,  int key) {
    int i = 0;

    size_t len = strlen(str); 
    char *str2 = (char*)malloc(len + 2);           // 2 -> extra char + trailing zero
    str2[len + 1] = '\0';                           // trailing zero

    while (str[i] != '\0') {
        char c = encryptChar(str[i], key);
        str2[i] = c;
        i++;
    }
    return str2;
}

int main() {
    char str[] = "Ab C d";
    char *str2 = encryptString(str, 3);
    std::cout << str2 << std::endl;
    free(str2);
    return 0;
}