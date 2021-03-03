#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {

    int length, i = 0;                              // Length of the sequence
    int input;                                      // User input

    vector<int> values;                             // Initializes the array for the sequence
    int max, min, sum = 0;                          // Minimum, maximum and the sum of the sequence elements
    float mean, stddeviaton  = 0;                   // Mean and the standard deviation of the sequence

    while (true) {

        cout << "Insert sequence item no." << i << " [press 0 to end]" << ": ";
        cin >> input;

        if (input == 0) {
            length = i;
            break;
        }

        values.push_back(input);

        values[i] = input;

        if (i == 0) {                                // Setting initial value for min and max
            max = values[0];   
            min = values[0];
        } else if (values[i] < min) {                   // Changes min if the number is smaller than the current min
            min = values[i];
        } else {                                     // Changes max if the number is larger than the current max
            max = values[i];       
        }

        sum += values[i];                               // Adding the current number to the sum
        i++;
    }

    

    mean = static_cast<double> (sum) / length;        // Calculates the mean

    // Calculates the standard deviation
    for (int j = 0; j < length; j++)
        stddeviaton += static_cast<double> (pow(values[j] - mean, 2)) / length;         
    
    stddeviaton = sqrt(stddeviaton);

    cout << fixed << setprecision(3);
    cout << "Sum: " << sum << endl
         << "Mean: " << mean << endl
         << "Standard deviation: " << stddeviaton << endl
         << "Smallest value: " << min << endl
         << "Largest value: " << max << endl;

    return 0;
}