#include <iostream>

using namespace std;

int main() {

    int weight;  // User input and bonus (which depends on the the weight range)
    float cost, bonus;         // Final transport price

    cout << "Insert a weight for the merchandise: ";
    cin >> weight;

    // Conditions for different weight ranges
    if (weight <= 500) {
        cost = 5;
    } else if (weight >= 501 && weight <= 1000) {
        cost = 5;
        bonus = (weight - 500) / 100;
        cost += 1.5 * bonus;
    } else {
        cost = 12.5;
        bonus = (weight - 1000) / 250 + ((weight - 1000) % 250) / 250.0;
        cost += 5 * bonus;
    }

    cout << "The price of the transport is: " << cost << "€" << endl;

    return 0;
}