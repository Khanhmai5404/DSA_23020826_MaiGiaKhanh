#include <iostream>
using namespace std;

void SelectionSort(int a[],int n) {
	for(int i=1;i<=n-1;i++){
		int min=a[i];
		int index=i;
		for(int j=i+1;j<=n;j++)
		{
			if(min>a[j]){
				min=a[j];
				index=j ;
			} 
		 } 
		int temp=a[i];
		a[i]=a[index];
		a[index]=temp;
	} 
}

int main()
{
	int i,a[100],n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	SelectionSort(a,n);
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	 } 
	 
 } 










