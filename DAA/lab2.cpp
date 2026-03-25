//Lab 2:Write an algorithm and program to compute factorial of a number using:?Recursive method?Analyze time and space complexity using the RAM model.

#include <iostream>
using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    return 0;
}
