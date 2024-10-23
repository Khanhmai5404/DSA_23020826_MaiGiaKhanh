#include <iostream>
#include <stdexcept>
using namespace std;

void heapify(int* heap, int size, int index) {
    int min = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if (l < size && heap[l] < heap[min])
        min = l;

    if (r < size && heap[r] < heap[min])
        min = r;

    if (min != index) {
        swap(heap[index], heap[min]);
        heapify(heap, size, min);
    }
}

void buildheap(int* heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, size, i);
}

struct PriorityQueue {
    int* heap;
    int capacity;
    int size;

    PriorityQueue(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        heap = new int[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {
        if (size == capacity) {
            throw overflow_error("Priority Queue is full");
        }
        heap[size] = data;
        size++;
        buildheap(heap, size);
    }

    int dequeue() {
        if (isEmpty()) {
            throw underflow_error("Priority Queue is empty");
        }
        int root = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapify(heap, size, 0);
        return root;
    }

    int peak() {
        if (isEmpty()) {
            throw underflow_error("Priority Queue is empty");
        }
        return heap[0];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);

    pq.enqueue(30);
    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(40);

    pq.print();

    cout << "Peak: " << pq.peak() << endl;

    cout << "Dequeue: " << pq.dequeue() << endl;

    pq.print();

    return 0;
}
