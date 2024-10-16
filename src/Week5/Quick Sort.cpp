#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];
    int i = low - 1;

    cout << "Pivot: " << pivot << endl;

    for (int j = low; j < high; j++) {
        cout << "Checking arr[" << j << "] = " << arr[j] << " with pivot " << pivot << endl;
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            cout << "Swapped arr[" << i << "] and arr[" << j << "]: ";
            printArray(arr, n);
        }
    }

    swap(arr[i + 1], arr[high]);
    cout << "Placed pivot " << pivot << " at position " << i + 1 << ": ";
    printArray(arr, n);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        cout << "QuickSort called on range [" << low << ", " << high << "]" << endl;
        int pi = partition(arr, low, high, n);

        cout << "Partitioned at index " << pi << endl;
        cout << "Left of pivot (" << pi << "): [" << low << ", " << pi - 1 << "]" << endl;
        cout << "Right of pivot (" << pi << "): [" << pi + 1 << ", " << high << "]" << endl;

        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
		  cout <<"Mai Gia Khanh "<<endl<<"MSSV  23020826"<<endl<<endl;
    int arr[] = {3, 4, 5, 8, 3, 1, 2, 9, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

