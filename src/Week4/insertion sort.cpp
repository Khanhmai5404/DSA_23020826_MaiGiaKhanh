#include<iostream>
using namespace std;

void InsertionSort(int a[], int n) {
    for(int i = 2; i <= n; i++) {       
        int j = i - 1;                  
        bool ok = false;                
        int temp = a[i];               

        while ((j >= 1) && !ok) {        
            if (a[j] > temp) {           
                a[j + 1] = a[j];         
                j--;                    
            } else ok = true;            
        }
        a[j + 1] = temp;              
    }
}

int main()
{
	int i,a[100],n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	InsertionSort(a,n);
	for(i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	 } 
}