#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

void factorialCalculator() {
    int n;
    cout << "Enter a non-negative number to calculate its factorial: ";
    cin >> n;
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers!" << endl;
        return;
    }
    if (n > 20) { // Factorial of numbers > 20 will overflow long long
        cout << "Input too large! Factorial may overflow." << endl;
        return;
    }
    long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    cout << "Factorial of " << n << " is " << factorial << endl;
}

void numberPyramid() {
    int rows;
    cout << "Enter the number of rows for the pyramid: ";
    cin >> rows;
    if (rows <= 0) {
        cout << "Number of rows must be a positive integer!" << endl;
        return;
    }
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= rows - i; ++j) {
            cout << " "; // Print spaces for alignment
        }
        for (int k = 1; k <= i; ++k) { // Print 'i' numbers in the row
            cout << k << " "; // Add a space between numbers
        }
        cout << endl;
    }
}

void sumEvenOddNumbers() {
    int choice, n, sum = 0;
    cout << "Enter 1 to sum even numbers or 2 to sum odd numbers: ";
    cin >> choice;
    cout << "Enter the range (1 to n): ";
    cin >> n;
    if (choice == 1) {
        for (int i = 2; i <= n; i += 2) {
            sum += i;
        }
        cout << "Sum of even numbers from 1 to " << n << " is " << sum << endl;
    } else if (choice == 2) {
        for (int i = 1; i <= n; i += 2) {
            sum += i;
        }
        cout << "Sum of odd numbers from 1 to " << n << " is " << sum << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
}

void reverseString() {
    string str;
    cout << "Enter a string to reverse: ";
    cin.ignore(); // To clear the newline character from the buffer
    getline(cin, str);
    if (str.empty()) {
        cout << "You entered an empty string!" << endl;
        return;
    }
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
}

int main() {
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Factorial Calculator\n";
        cout << "2. Number Pyramid\n";
        cout << "3. Sum of Even or Odd Numbers\n";
        cout << "4. Reverse a String\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // Check for invalid input
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                factorialCalculator();
                break;
            case 2:
                numberPyramid();
                break;
            case 3:
                sumEvenOddNumbers();
                break;
            case 4:
                reverseString();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}