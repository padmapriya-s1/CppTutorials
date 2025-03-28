#include <iostream>
using namespace std;

class MaxHeap {
private:
    int* heap;
    int capacity;
    int size;

    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }
    int parent(int i) { return (i - 1) / 2; }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = new int[capacity];
    }

    ~MaxHeap() { delete[] heap; }

    void maxHeapify(int A[], int i, int n) {
        int l = left(i);
        int r = right(i);
        int max = i;
    
        if (l < n && A[max] < A[l])
            max = l;
    
        if (r < n && A[max] < A[r])
            max = r;
    
        if (max == i)
            return;
    
        swap(A[i], A[max]);
        maxHeapify(A, max, n);
    }    

    void buildHeap(int arr[], int n) {
        if (n > capacity) return;
        size = n;
        for (int i = 0; i < n; i++)
            heap[i] = arr[i];
        for (int i = (size / 2) - 1; i >= 0; i--)
        maxHeapify(heap, i, n);
    }

    int getMax() {
        if (size == 0) return -1;
        return heap[0];
    }

    int removeMax() {
        if (size == 0) return -1;
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;
        maxHeapify(heap,0,size);
        return maxVal;
    }

    int length() { return size; }

    void increaseKey(int i, int newVal) {
        if (i >= size || heap[i] > newVal) return;
        heap[i] = newVal;
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void insert(int x) {
        if (size == capacity) return;
        heap[size] = -1e9;
        size++;
        increaseKey(size - 1, x);
    }
};

//Heap Sort
void HeapSort(int A[],int m){
    int n = m;
    MaxHeap Heap(n);
    Heap.buildHeap(A,n);
    while(n>1){
        int temp = A[0];
        A[0]=A[n-1];
        A[n-1]=temp;
        n=n-1;
        Heap.maxHeapify(A,0,n);
    }
}

int main() {
    int arr[] = {10, 20, 15, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    MaxHeap heap(n);
    heap.buildHeap(arr, n);

    cout << "Max: " << heap.getMax() << endl;
    heap.insert(50);
    cout << "Max after insert: " << heap.getMax() << endl;
    cout << "Removed Max: " << heap.removeMax() << endl;
    cout << "New Max: " << heap.getMax() << endl;

    
    return 0;
}
