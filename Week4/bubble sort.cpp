#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
	int i,a[100],n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	bubbleSort(a,n);
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	 } 
}