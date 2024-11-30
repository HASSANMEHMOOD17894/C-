#include <iostream>
using namespace std;

void merge(int array[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];

    // Copy data to temporary arrays a[] and b[]
    for (int i = 0; i < n1; i++) {
        a[i] = array[l + i];
    }
    for (int i = 0; i < n2; i++) {
        b[i] = array[mid + 1 + i];
    }

    // Merge the temporary arrays back into array[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            array[k] = a[i];
            i++;
        } else {
            array[k] = b[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of a[], if any
    while (i < n1) {
        array[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements of b[], if any
    while (j < n2) {
        array[k] = b[j];
        j++;
        k++;
    }
}

void mergesort(int array[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;  // Avoids overflow for large l and r
        mergesort(array, l, mid);
        mergesort(array, mid + 1, r);
        merge(array, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int array[n];  // Fixed size issue, now n is initialized before use
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {  // Added i++ in the loop
        cin >> array[i];
    }

    mergesort(array, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
