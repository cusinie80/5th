//Lab 4:Write programs to generate Fibonacci numbers using:?Iteration?Recursion?Compare their time and space complexity.
#include <iostream>
using namespace std;

/* Recursive Fibonacci */

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int choice, n;

    cout << "Choose Method to Generate Fibonacci Series\n";
    cout << "1. Iteration\n";
    cout << "2. Recursion\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter number of terms: ";
    cin >> n;

    switch (choice) {

    case 1: {
        int a = 0, b = 1, c;

        cout << "\nTracing Table (Iteration):\n";
        cout << "Step\tA\tB\tC\n";

        if (n >= 1)
            cout << "0\t" << a << "\t-\t-\n";
        if (n >= 2)
            cout << "1\t" << a << "\t" << b << "\t-\n";

        for (int i = 2; i < n; i++) {
            c = a + b;
            cout << i << "\t" << a << "\t" << b << "\t" << c << endl;
            a = b;
            b = c;
        }

        cout << "\nFibonacci Series: ";
        a = 0; b = 1;
        if (n >= 1) cout << a << " ";
        if (n >= 2) cout << b << " ";
        for (int i = 2; i < n; i++) {
            c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
        break;
    }

    case 2:
        cout << "\nTracing Table (Recursion):\n";
        cout << "i\tfib(i)\n";

        for (int i = 0; i < n; i++) {
            cout << i << "\t" << fib(i) << endl;
        }

        cout << "\nFibonacci Series: ";
        for (int i = 0; i < n; i++) {
            cout << fib(i) << " ";
        }
        break;

    default:
        cout << "Invalid choice!";
    }

    return 0;
}

