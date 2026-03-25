//Lab 3: Implement Euclid’s algorithm to find GCD of two numbers.Analyze its time and space complexity.

#include <iostream>
using namespace std;

int main() {
    int a, b, temp;
    int i = 1;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\nTracing Table:\n";
    cout << "Iteration\tA\tB\tR=A % B\n";

    while (b != 0) {
        temp = a % b;

        cout << i << "\t\t" << a << "\t" << b << "\t" << temp << endl;

        a = b;
        b = temp;
        i++;
    }

    cout << "\nGCD is " << a << endl;

    return 0;
}

