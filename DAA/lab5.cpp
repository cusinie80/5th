//Lab 5: Implement Sequential (Linear) Search. 
//Count number of comparisons and analyze: 
//• Best case, Worst case, Average case using c++ also include tracing table
#include <iostream>
using namespace std;

int main() {
    int n, key;
    int comparisons = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    cout << "\nTracing Table:\n";
    cout << "Step\tIndex\tElement\tComparison\n";

    for (int i = 0; i < n; i++) 
	{
        comparisons++;
        cout << comparisons << "\t" << i << "\t" << arr[i] << "\t";

        if (arr[i] == key) {
            cout << "Match Found\n";
            cout << "\nElement found at position " << i + 1 << endl;
            cout << "Total comparisons = " << comparisons << endl;
            return 0;
        } else {
            cout << "Not Matched\n";
        }
    }

    cout << "\nElement not found\n";
    cout << "Total comparisons = " << comparisons << endl;

    return 0;
}

