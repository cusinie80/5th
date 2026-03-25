#include <iostream>
using namespace std;

/* ---------- HEAPIFY ---------- */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        cout << "Heapify at index " << i << " : ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;

        heapify(arr, n, largest);
    }
}

/* ---------- BUILD HEAP ---------- */
void buildHeap(int arr[], int n) {
    cout << "\nBuilding Max Heap:\n";
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

/* ---------- HEAP SORT ---------- */
void heapSort(int arr[], int n) {
    buildHeap(arr, n);

    cout << "\nHeap Sort Steps:\n";
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);

        cout << "Swap root with index " << i << " : ";
        for (int k = 0; k < n; k++)
            cout << arr[k] << " ";
        cout << endl;

        heapify(arr, i, 0);
    }
}

/* ---------- MAIN ---------- */
int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nInitial Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n);

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

