#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

    int length;                                     // User input

    cout <<  "How many elements do you want the sequence to have ? ";
    cin >> length;

    int arr[length];                                // Initializes the array for the sequence
    int max, min, sum = 0;                          // Minimum, maximum and the sum of the sequence elements
    float mean, stddeviaton  = 0;                   // Mean and the standard deviation of the sequence

    for (int i = 0; i < length; i++) {

        cout << "Insert sequence item no." << i + 1 << ": ";
        cin >> arr[i];

        if (i == 0) {                                // Setting initial value for min and max
            max = arr[0];   
            min = arr[0];
        } else if (arr[i] < min) {                   // Changes min if the number is smaller than the current min
            min = arr[i];
        } else {                                     // Changes max if the number is larger than the current max
            max = arr[i];       
        }

        sum += arr[i];                               // Adding the current number to the sum
    }

    mean = static_cast<double> (sum) / length;        // Calculates the mean

    // Calculates the standard deviation
    for (int j = 0; j < length; j++)
        stddeviaton += static_cast<double> (pow(arr[j] - mean, 2)) / length;         
    
    stddeviaton = sqrt(stddeviaton);

    cout << fixed << setprecision(3);
    cout << "Sum: " << sum << endl
         << "Mean: " << mean << endl
         << "Standard deviation: " << stddeviaton << endl
         << "Smallest value: " << min << endl
         << "Largest value: " << max << endl;

    return 0;
}