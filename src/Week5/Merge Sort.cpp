#include<bits/stdc++.h>
using namespace std;

void merging(int arr[], int l, int h, int m) {
    int N1 = m - l + 1;
    int N2 = h - m;
    int left[N1];
    int right[N2];
    for (int i = 0; i < N1; i++) {
        left[i] = arr[l + i];
    }
    for (int j = 0; j < N2; j++) {
        right[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < N1 && j < N2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    for (; i < N1; i++) {
        arr[k++] = left[i];
    }
    for (; j < N2; j++) {
        arr[k++] = right[j];
    }
}

void merge_sort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + ((h - l) / 2));
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merging(arr, l, h, mid);
    }
}

int main() {
    int arr[] = {1, 0, 13, 7, 6, 2, 16};
    cout << "Day truoc khi sap xep:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    merge_sort(arr, 0, 6);
    cout << "Day sau khi sap xep:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
