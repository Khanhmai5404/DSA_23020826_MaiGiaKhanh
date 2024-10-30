#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int value) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return mid;
        }
        else if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 7;

    int result = binarySearch(arr, size, value);
    if (result != -1) {
        cout << "Phan tu " << value << " tim thay tai vi tri " << result + 1 << endl;
    } else {
        cout << "Phan tu " << value << " khong tim thay" << endl;
    }

    return 0;
}
