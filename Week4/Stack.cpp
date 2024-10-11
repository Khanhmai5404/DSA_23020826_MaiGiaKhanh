#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int* stack;

public:
    Stack(int maxSize) {
        top = -1;
        size = maxSize;
        stack = new int[size];
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == size - 1);
    }

    void push(int item) {
        if (isFull()) {
            cout << "Stack day, khong the them." << endl;
            return;
        }
        stack[++top] = item;
        cout << "Pushed: " << item << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong." << endl;
            return -1;
        }
        int item = stack[top--];
        cout << "Popped: " << item << endl;
        return item;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack rong." << endl;
            return -1;
        }
        return stack[top];
    }

    int getSize() {
        return top + 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] stack;
    }
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.pop();
    cout << "Peek: " << s.peek() << endl;
    s.display();

    return 0;
}

