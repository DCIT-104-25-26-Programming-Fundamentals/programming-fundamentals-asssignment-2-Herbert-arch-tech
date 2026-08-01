// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;
#include <vector>

double sum_of_array(vector<int>list) {
        int sum = 0;
        for (int num:list ) {
            sum += num;
        }
        cout << "Sum: " << sum << endl;

        return 0;
}
double average_of_array(vector<int>list) {
        double sum = 0;
        for (int num:list ) {
            sum += num;
        }
        double average = sum / size(list);
        cout << "Average: " << average << endl;

        return 0;
}

double max_of_array(vector<int>list) {
    int max = list[0];
    for (int num : list) {
        if (num > max) {
            max = num;
        }
    }
    cout << "Maximum: " << max << endl;

    return 0;
}

double min_of_array(vector<int>list) {
    int min = list[0];
    for (int num : list) {
        if (num < min) {
            min = num;
        }
    }
    cout << "Minimum: " << min << endl;

    return 0;
}

int main() {
    vector<int> cars = {};

    cout << "How many numbers? " << endl;
    int num_of_numbers;
    cin >> num_of_numbers;
    for(int i = 1; i <= num_of_numbers; i++){
        cout << "Enter number " << i << ": ";
        int num;
        cin >> num;
        if (num <= 0) {
            cout << "Error: The number must be a positive integer" << endl;
            break;
        }
        else {
            cars.emplace_back(num);
        }


    }
    sum_of_array(cars);
    average_of_array(cars);
    max_of_array(cars);
    min_of_array(cars);

    return 0;
}

