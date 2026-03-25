#include <iostream>
using namespace std;

/* -------- MERGE SORT -------- */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    cout << "Merging [" << l << "..." << r << "] : ";

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    for (int x = l; x <= r; x++)
        cout << arr[x] << " ";
    cout << endl;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* -------- QUICK SORT -------- */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    cout << "Pivot = " << pivot << " | ";

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);

    for (int k = low; k <= high; k++)
        cout << arr[k] << " ";
    cout << endl;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* -------- MAIN -------- */
int main() {
    int choice, n;

    cout << "Choose Sorting Algorithm\n";
    cout << "1. Merge Sort\n";
    cout << "2. Quick Sort\n";
    cout << "Enter choice: ";
    cin >> choice;

    cout << "\nEnter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (choice == 1) {
        cout << "\nMerge Sort Tracing Table:\n";
        mergeSort(arr, 0, n - 1);
    }
    else if (choice == 2) {
        cout << "\nQuick Sort Tracing Table:\n";
        quickSort(arr, 0, n - 1);
    }
    else {
        cout << "Invalid choice!";
        return 0;
    }

    cout << "\nSorted Array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

