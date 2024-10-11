#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* queue;

public:
    Queue(int maxSize) {
        front = rear = -1;
        size = maxSize;
        queue = new int[size];
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int item) {
       
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    int dequeue() {
        
        int item = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        cout << "Dequeued: " << item << endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue rong." << endl;
            return -1;
        }
        return queue[front];
    }

    int getSize() {
        if (isEmpty()) return 0;
        return (rear - front + 1);
    }
 void display() {
        
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }


    
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    cout << "Peek: " << q.peek() << endl;
    q.display();

    return 0;
}

