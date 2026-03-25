//Lab 1:Write an algorithm and program to compute factorial of a number using:?Iterative method?Analyze time and space complexity using the RAM model.

#include <iostream>
using namespace std;

int main() {
    int n;
    long long fact = 1;

    cout << "Enter a number: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        fact = fact * i;
    }

    cout << "Factorial of " << n << " is " << fact << endl;

    return 0;
}

/*
| Statement                               | Frequency | Cost per execution | Total Cost |
| --------------------------------------- | --------- | ------------------ | ---------- |
| `int n;`                                | 1         | O(1)               | O(1)       |
| `fact = 1;`                             | 1         | O(1)               | O(1)       |
| `cin >> n;`                             | 1         | O(1)               | O(1)       |
| `for (i = 1; i <= n; i++)` (loop check) | n + 1     | O(1)               | O(n)       |
| `fact = fact * i;`                      | n         | O(1)               | O(n)       |
| `i++`                                   | n         | O(1)               | O(n)       |
| `cout << fact;`                         | 1         | O(1)               | O(1)       |
Time Complexity =O(n)?

space
n ? integer
fact ? long long
i ? loop variable
Space Complexity =O(1)?
*/
