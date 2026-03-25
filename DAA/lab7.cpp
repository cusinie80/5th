#include <iostream>
using namespace std;

// Recursive Binary Search with tracing
int stepR = 1;
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    cout << stepR++ << "\t" << low << "\t" << high << "\t"
         << mid << "\t" << arr[mid] << "\t";

    if (arr[mid] == key) {
        cout << "Found\n";
        return mid;
    }
    else if (key < arr[mid]) {
        cout << "Go Left\n";
        return recursiveBinarySearch(arr, low, mid - 1, key);
    }
    else {
        cout << "Go Right\n";
        return recursiveBinarySearch(arr, mid + 1, high, key);
    }
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    /* -------- Iterative Binary Search -------- */
    int low = 0, high = n - 1, stepI = 1;

    cout << "\nTracing Table (Iterative Binary Search):\n";
    cout << "Step\tLow\tHigh\tMid\tElement\tResult\n";

    bool found = false;
    while (low <= high) {
        int mid = (low + high) / 2;

        cout << stepI++ << "\t" << low << "\t" << high << "\t"
             << mid << "\t" << arr[mid] << "\t";
  if (arr[mid] == key) {
            cout << "Found\n";
            cout << "Element found at position " << mid + 1 << endl;
            found = true;
            break;
        }
        else if (key < arr[mid]) {
            cout << "Go Left\n";
            high = mid - 1;
        }
        else {
            cout << "Go Right\n";
            low = mid + 1;
        }
    }

    if (!found)
        cout << "Element not found (Iterative)\n";

    /*-------- Recursive Binary Search -------- */
    cout << "\nTracing Table (Recursive Binary Search):\n";
    cout << "Step\tLow\tHigh\tMid\tElement\tResult\n";

    int result = recursiveBinarySearch(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found (Recursive)\n";

    return 0;
}
