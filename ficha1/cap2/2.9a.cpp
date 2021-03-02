#include <iostream>
#include <cmath>

using namespace std;

int sizeOf(int num);

int main() {
    
    unsigned int num;                           // User input 
    int exp = 0;
    bool isPalindrome = true;                   // Boolean that tracks if num is a Palindrome

    cout << "Input a number: ";
    cin >> num;
    
    /* 
     * Loop that for each iteration checks if the most and less significant digits are the same and, if they are,
     * removes them from the number. If they aren't (the number isn't a palindrome) it breaks out of the loop
    */
    while (num > 0) {

        int size = sizeOf(num);

        int lastDig = num % 10;
        int firstDigit = num / pow(10, size - 1);


        if (firstDigit != lastDig) {
            isPalindrome = false;
            break;
        }

        num = (num / pow(10, size - 1)) / 10 ;

    }

    if (isPalindrome)
        cout << num << " is a palyndrome" << endl;
    else
        cout << num << " is not a palyndrome" << endl;

    return 0;
}


int sizeOf(int num) {
    int cont = 0;

    while(num > 0) {
        num /= 10;
        cont ++;
    }
    return cont;
}
















/*
int main() {

    int i = 0, sum = 0;

    while (i <= 5) {
        int value;
        cout << "Value no. " << i << " ? ";
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000000000, '\n');
            cout << "Invalid number" << endl;
        } else {
            sum += value;
            i++;
        }
    }

    cout << "The sum is: "<< sum << endl;
    return 0;
} */