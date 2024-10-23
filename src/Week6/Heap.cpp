#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr,int n, int i)
{
	int min=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n&&arr[l]<arr[min])
	min=l;
	
	if(r<n&&arr[r]<arr[min])
	min=r;
	
	if(min!=i){
	swap(arr[i],arr[min]);
	heapify(arr,n,min);
    }
}

void buildheap(vector<int>& arr,int n)
{
	for(int i= n/2 - 1;i>=0;i--)
    heapify(arr,n,i);
}

void printarr(const vector<int>& arr,int n)
{
	for(int i=0;i<n;i++)
	cout<<arr[i]<<' ';
}

int main()
{
	int n,i;
	cin>>n;
	vector<int> arr(n);
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	buildheap(arr,n);
	cout<<"Mang sau khi tao Minheap"<<endl;
	printarr(arr,n);
}