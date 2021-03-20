#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void displayMenu();
double calcOperation(double op1, double op2, char op, bool &valid);
void memoryOperation(string op, double &lastRes, double &mem);


int main() {

bool anotherOperation = true;                   // Bool to check if the user wants to make another operation
    double op1, op2, res = 0, mem = 0; 
    char op;
    string aditionalOp;                         // Tracks if the user wants to continue using the calculator

    displayMenu();                              // Displays the menu

    do {

        bool valid = true;                      // Valid checks if the operand is valid (+, -, *, /)

        cout << "To perform a calculation insert (<operand1> <operation> <operand2>): ";
        cin >> op1 >> op >> op2;

        if (cin.eof()) {
            anotherOperation = false;
        }

        if (cin.good()) {
            res = calcOperation(op1, op2, op, valid);

            if (valid) {
                cout << "res = " << res << endl;

                cout << "Aditional operation: ";
                cin >> aditionalOp;

                memoryOperation(aditionalOp, res, mem);


            } else {                            // Prints an error message and clears the buffer
                cout << "Invalid operation. Try again" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }

        } else {                                // Prints an error message and clears the buffer
            cout << "Invalid input. Try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    } while (anotherOperation);

    return 0;
}


double calcOperation(double op1, double op2, char op, bool &valid) {
    switch (op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            valid = false;
            cout << "Invalid operation!" << endl;
    }
}


void memoryOperation(string op, double &lastRes, double &mem) {

    if (op == "M") {                            // saves result on memory
        mem = lastRes;
    } else if (op == "MC") {                    // clears memor
        mem = 0;
    } else if (op == "M+") {                    // adds the current result to memor
        mem += lastRes;
    } else if (op == "M-") {                    // subtracts the current result to memory
        mem -= lastRes;
    } else if (op == "MR") {                    // displays the value present on memory
        cout << mem << endl;
    } else if (op == "C") {                     // clear the contents of the display
        lastRes = 0;
    } else {
        cout << "Invalid memory option" << endl;
    }

}


void displayMenu() {
    cout << " ______________________________________________________________________________________ " << endl;
    cout << "|                             |Calculator Menu|                                        |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|    *BASIC OPERATIONS*                                                                |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|    + -> sum                                                                          |" << endl;
    cout << "|    - -> subtract                                                                     |" << endl;
    cout << "|    * -> multiplication                                                               |" << endl;
    cout << "|    / -> division                                                                     |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|    *Memory*                                                                          |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "|    M  -> save the values on memory                                                   |" << endl;
    cout << "|    MC -> clears the contents on memory                                               |" << endl;
    cout << "|    M+ -> adds the value on display to the value on memory                            |" << endl;
    cout << "|    M- -> subtracts the value on display to the value on memory                       |" << endl;
    cout << "|    MR -> shows the contents on memory                                                |" << endl;
    cout << "|    C  -> clears the contents on display                                              |" << endl;
    cout << "|                                                                                      |" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
}