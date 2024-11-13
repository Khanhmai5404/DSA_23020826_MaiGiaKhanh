#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    class Node {
    public:
        int data;
        Node *prev, *next;

        Node(int value) 
		{
            data = value;
            prev = NULL;
            next = NULL;
        }
    };

    Node *head, *tail;

public:
    DoublyLinkedList() {
        head = tail = NULL;
    }

    int countNode() // O(n)
	{ 
        int count = 0;
        Node *p = head;
        while (p) {
            count++;
            p = p->next;
        }
        return count;
    }

    int getNode(int index) // O(n)
	{ 
        Node *p = head;
        int count = 0;
        while (p) {
            if (count == index) {
                return p->data;
            }
            p = p->next;
            count++;
        }
        return -1;
    }

    void addFirst(int x) // O(1)
	{ 
        Node *newNode = new Node(x);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addEnd(int x) // O(1)
	{ 
        Node *newNode = new Node(x);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insert(int i, int x) // O(n)
	{ 
        int n = countNode();
        if (i < 1 || i > n + 1) return;

        if (i == 1) {
            addFirst(x);
            return;
        } else if (i == n + 1) {
            addEnd(x);
            return;
        }

        Node *newNode = new Node(x);
        Node *p = head;

        for (int j = 1; j < i - 1; j++) {
            p = p->next;
        }

        newNode->next = p->next;
        newNode->prev = p;
        p->next->prev = newNode;
        p->next = newNode;
    }

    void deleteFirst() // O(1)
	{ 
        if (head == NULL) return;

        Node *temp = head;
        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete temp;
    }

    void deleteLast() // O(1)
	{ 
        if (tail == NULL) return;

        Node *p = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }
        delete p;
    }

    void deleteNode(int i) // O(n)
	{ 
        int n = countNode();
        if (i < 1 || i > n) return;

        if (i == 1) {
            deleteFirst();
            return;
        } else if (i == n) {
            deleteLast();
            return;
        }

        Node *p = head;
        for (int j = 1; j < i; j++) {
            p = p->next;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }

    void duyetDau() // O(n)
	{ 
        Node *p = head;
        while (p) {
            cout << p->data << ' ';
            p = p->next;
        }
        cout << endl;
    }

    void duyetCuoi() // O(n)
	{ 
        Node *p = tail;
        while (p) {
            cout << p->data << ' ';
            p = p->prev;
        }
        cout << endl;
    }
};

int main() 
{
    DoublyLinkedList list;

    list.addFirst(10);
    
    list.addEnd(11);

    list.insert(15,2);

    list.duyetDau(); 
    
    list.duyetCuoi();  

    cout << "Phan tu vi tri 2: " << list.getNode(2) << endl;

    list.deleteFirst();
    
    list.deleteLast();
        
	list.deleteNode(2); 

    list.duyetDau();

    return 0;
}

