#include <iostream>

using namespace std;

int main() {

    int inputNum1, inputNum2; // User input 
    
    cout << "Insert 2 nums to sum: ";
    cin >> inputNum1 >> inputNum2;
    
    // Checks if both the inputs are integers and if they aren't, immediatly displays an error message and ends the execution
    if (!cin) {
        cerr << "Invalid input type!\n";
        return 0;
    };

    int sumRes = inputNum1 + inputNum2; // Contains the sum of the input variables

    if (inputNum1 > 0 && inputNum2 > 0 && sumRes < 0) // Overflow!
            cerr << "Sum overflow\n";
    else if (inputNum1 < 0 && inputNum2 < 0 && sumRes > 0) // Underflow!
        cerr << "Sum underflow\n";
    else
        cout << inputNum1 << " + " << inputNum2 << " = " << sumRes << endl; // Displays the sum if no overflow or underflow happens

    return 0;
}




/* This was my first approach , but I ended up preferring the resolution above 

#include <iostream>
#include <climits>

using namespace std;

int main() {

    long long int inputNum1, inputNum2;

    const int INT_MIN = numeric_limits<int>::min();
    const int INT_MAX = numeric_limits<int>::max();

    cout << "Input 2 numbers: ";
    cin >> inputNum1 >> inputNum2;

    long long int sum = inputNum1 + inputNum2;

    if (sum > INT_MAX)
        cout << "Sum underflow" << endl;
    else if (sum < INT_MIN)
        cout << "Sum overflow" << endl;
    else
        cout << "The value of the sum is: " << sum << endl;

    return 0;
}
*/