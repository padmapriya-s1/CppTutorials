#include <iostream>

using namespace std;

class PriorityQueue {
private:
    int heap[100]; // Fixed-size array implementation
    int size;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int max = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[max])
            max = l;
        if (r < size && heap[r] > heap[max])
            max = r;
        if (max != i) {
            swap(heap[i], heap[max]);
            heapifyDown(max);
        }
    }

public:
    PriorityQueue() { size = 0; }

    void enqueue(int x) {
        if (size >= 100) {
            cout << "Priority Queue is full!" << endl;
            return;
        }
        heap[size] = x;
        heapifyUp(size);
        size++;
    }

    int first() {
        if (size > 0)
            return heap[0];
        throw out_of_range("Priority Queue is empty!");
    }

    int dequeue() {
        if (size == 0)
            throw out_of_range("Priority Queue is empty!");

        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    int getSize() {
        return size;
    }

    bool is_full() {
        return size == 100;
    }

    bool is_empty() {
        return size == 0;
    }

    void printQueue() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(15);
    pq.enqueue(30);

    cout << "Priority Queue: ";
    pq.printQueue();

    cout << "First element: " << pq.first() << endl;

    cout << "Dequeue: " << pq.dequeue() << endl;

    cout << "Priority Queue after dequeue: ";
    pq.printQueue();

    return 0;
}
