#include <iostream>
using namespace std;

int main() {

    char inputSymbol;

    cout << "Enter a symbol: ";
    cin >> inputSymbol;
    cout << "The ASCII code of '" << inputSymbol << "' is " << static_cast<int>(inputSymbol) << endl;
    
    return 0;
}

