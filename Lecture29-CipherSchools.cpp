#include "bits/stdc++.h"
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Helper function to maintain the heap property
    void heapify(int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != idx) {
            swap(heap[idx], heap[largest]);
            heapify(largest);
        }
    }

public:
    // Push an element into the heap
    void push(int val) {
        heap.push_back(val);
        int idx = heap.size() - 1;

        while (idx > 0 && heap[idx] > heap[(idx - 1) / 2]) {
            swap(heap[idx], heap[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    // Remove the top element from the heap
    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    // Return the size of the heap
    int size() {
        return heap.size();
    }

    // Return the top element of the heap
    int top() {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        return heap[0];
    }
};

class MinHeap {
private:
    vector<int> heap;

    // Helper function to maintain the heap property
    void heapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != idx) {
            swap(heap[idx], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    // Push an element into the heap
    void push(int val) {
        heap.push_back(val);
        int idx = heap.size() - 1;

        while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
            swap(heap[idx], heap[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }

    // Remove the top element from the heap
    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();
        heapify(0);
    }

    // Return the size of the heap
    int size() {
        return heap.size();
    }

    // Return the top element of the heap
    int top() {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        return heap[0];
    }
};

int main() {
    MinHeap heap;//MaxHeap heap;
    heap.push(5);
    heap.push(2);
    heap.push(10);
    heap.push(8);
    heap.push(3);

    cout << "Size: " << heap.size() << endl;
    cout << "Top: " << heap.top() << endl;

    heap.pop();
    cout << "Size after pop: " << heap.size() << endl;
    cout << "Top after pop: " << heap.top() << endl;

    return 0;
}
