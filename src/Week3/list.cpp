#include <iostream>
using namespace std;

struct list{
    int count=0;
    int *arr;

    list (int size){arr = new int (size);}

    int getNode (int index){
        return arr[index];
    }

    void addFirst(int x) // O(n)
	{
        count++;
        for (int i=count; i>0; i--){
            arr[count]= arr[count-1];
        }
        arr[0]=x;
    }
    
    void addEnd(int y) // O(1)
	{
        count++;
        arr[count]=y;
    }
    
    void insert(int i, int z) // O(n)
	{
        count++;
        for (int j=i; i>0; j--){
            arr[count]= arr[count-1];
        }
        arr[i-1]=z;
    }
    
    void xoaDau() // O(n)
	{
        for (int i=0; i<count; i++){
            arr[i]=arr[i+1];
        }
        count--;
    }
    
    void xoaCuoi() // O(1)
	{
        count--;
    }
    
    void xoaKhac(int i) // O(n)
	{
        for (int j=i; j<count; j++){
            arr[i]=arr[i+1];
        }
        count--;
    }
    
    void duyetXuoi() // O(n)
	{
        for (int i=0; i<count; i++){
            cout << arr[i] << " ";
        }
    }
    
    void duyetNguoc() // O(n)
	{
        for (int i=count-1; i>=0; i--){
            cout << arr[i] << " ";
        }
    }
    
};

int main()
{

}
