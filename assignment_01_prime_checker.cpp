// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

static void isPrime() {
    int num;
    int factor = 0;
    cin >> num;
    if (num < 2) {
        cout << num << " is not a prime number since it is less than 2" << endl;
    }
    else {
        for (int i = 2; i <= num;i++) {
            if (num % i == 0) {
                factor = factor + 1;
            }
        }
        if (factor == 1) {
            cout << num << " is a Prime number." << endl;
        }
        else {
            cout << num << " is Not a prime number.";
        }
    }
}
int main() {
    cout << "++++++++Prime Number Checker++++++++++" << endl;
    cout << "Enter a number:" << endl;
    isPrime();


    return 0;
}