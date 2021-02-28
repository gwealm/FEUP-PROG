#include <iostream>

using namespace std;

int main() {

    int years; // User input variable which represents the years passed since the deposit
    double amountDeposited, annualInterest;     // User iput variables which represent the amount depposited and the interest rate 

    cout << "How many years passed since the deposit of the money ? ";
    cin >> years;
    cout << "What was the value of the deposit ? ";
    cin >> amountDeposited;
    cout << "Which is the annual interest rate ? ";
    cin >> annualInterest;

    double withdrawAmount;  // The amount the user will be able to withdar after 'years' years and with an 'anualInterest'% interest rate

    for (int i = 0; i < years; i++) 
        amountDeposited *= (1 + annualInterest / 100);

    withdrawAmount = amountDeposited;

    cout << "The amount you can withdraw is: " <<  withdrawAmount << endl;

    return 0;
}