#include <iostream>

using namespace std;

int main() {

    int weight, bonus;  // User input and bonus (which depends on the the weight range)
    float cost;         // Final transport price

    cout << "Insert a weight for the merchandise: ";
    cin >> weight;

    // Conditions for different weight ranges
    if (weight <= 500) {
        cost = 5;
    } else if (501 <= weight <= 1000) {
        cost = 5;
        bonus = (weight - 500) / 100;
        cost += 1.5 * bonus;
    } else {
        cost = 12.5;
        bonus = (weight - 1000) / 250;
        cost += 5 * bonus;
    }

    cout << "The price of the trasnport is: " << cost << "€" << endl;

    return 0;
}