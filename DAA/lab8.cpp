#include <iostream>
using namespace std;

int comparisons = 0;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int arr[], int low, int high) {
    MinMax result, left, right;

    // Case 1: Single element
    if (low == high) {
        result.min = result.max = arr[low];

        cout << low << "\t" << high << "\t"
             << result.min << "\t" << result.max << endl;

        return result;
    }

    // Case 2: Two elements
    if (high == low + 1) {
        comparisons++;
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }

        cout << low << "\t" << high << "\t"
             << result.min << "\t" << result.max << endl;

        return result;
    }

    // Case 3: More than two elements
    int mid = (low + high) / 2;

    left = findMinMax(arr, low, mid);
    right = findMinMax(arr, mid + 1, high);

    comparisons++;
    result.min = (left.min < right.min) ? left.min : right.min;

    comparisons++;
    result.max = (left.max > right.max) ? left.max : right.max;

    cout << low << "\t" << high << "\t"
         << result.min << "\t" << result.max << endl;

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements (even): ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nTracing Table\n";
    cout << "Low\tHigh\tMin\tMax\n";
    cout << "--------------------------------\n";

    MinMax ans = findMinMax(arr, 0, n - 1);

    cout << "\nFinal Result:\n";
    cout << "Minimum = " << ans.min << endl;
    cout << "Maximum = " << ans.max << endl;

    cout << "\nTotal Comparisons = " << comparisons << endl;
    cout << "Theoretical Comparisons = " << (3 * n) / 2 - 2 << endl;

    return 0;
}

