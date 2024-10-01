#include <iostream>
using namespace std;

class linkList{
private:
    class Node{
    public:
        int data;
        Node *next;

        Node(int value)
		{
            data = value;
            next = NULL;
        }
    };

    Node *head;
public:
    linkList(){
        head = NULL;
    }

    int countNode() // O(n)
	{
        int count=1;
        Node *temp = head;
        while (temp){
            temp=temp->next;
            count++;
        }
        return count;
    }
    
    int getNode (int index) // O(n)
	{
        Node *p = head;
        int count = 0;

        while(p)
		{
            if(count == index)
			{
                return p->data;
            }
            p=p->next;
            count++;
        }
        return -1;
    }
    
    void addFirst(int x) // O(1)
	{
        Node *newNode = new Node(x);
        if (head != NULL){
            newNode->next = head;
            head = newNode;
        }
    }
    
    void addEnd(int x) // O(n)
	{
        Node *newNode = new Node(x);
        Node *p = head;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
    }
    
    void insert(int i, int x) // O(n)
	{
        Node *newNode = new Node(x);
        Node *p = head;
        int n = countNode();
        if (i < 1 || i > n+1) return;
        if (i==1) addFirst(x); return;
        for (int j=1; j <= i-2; j++){
            p = p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    
    void xoaDau() // O(1)
	{
        if(head == NULL) return;
        Node *p = head;
        head = head -> next;
        delete p;
    }
   
    void xoaCuoi() // O(n)
	{
        if (head == NULL) return;
        Node *p = head;
        if(p->next == NULL)
		{
            head = NULL;
            delete p;
            return;
        }
        while (p->next->next != NULL)
		{
            p = p->next;
        }
        Node *cuoi = p->next;
        p->next = NULL;
        delete cuoi;
    }
    
    void deleteNode(int i) // O(n)
	{
        if (head == NULL) return;
        Node *p = head;
        int n = countNode();
        if (i<1 || i>n) return;
        if (i == 1) xoaDau(); return;
        for (int j=1; j<i-2; j++){
            p = p->next;
        }
        Node *nodei = p->next;
        p->next = p->next->next;
        delete nodei;
    }
    
    void duyetXuoi() // O(n)
	{
        Node *p = head;
        while (p){
            cout << p -> data << ' ';
            p = p -> next;
        }
    }
   
    void duyetNguoc() // O(n)
	{
        int n=countNode();
        int arr[n];
        Node *p = head;
        for (int i=0; i<n; i++){
            arr[i] = p->data;
            p = p->next;
        }
        for (int i=n-1; i>=0; i--){
            cout << arr[n] << ' ';
        }
    }
    
};

int main()
{

}
