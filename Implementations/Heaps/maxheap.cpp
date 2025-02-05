#include <iostream>
#include <climits>

using namespace std;

/*
Max-Heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node. To easily understand, we can think of a binary heap as a binary tree, where the tree satisfies two properties:

    - Shape Property: A binary heap is a complete binary tree; that is, all levels of the tree, except possibly the last one (deepest) are fully filled, and, if the last level of the tree is not complete, the nodes of that level are filled from left to right.
    - Heap Property: The key stored in each node is either greater than or equal to (≥) or less than or equal to (≤) the keys in the node's children, according to some total order.

With this, we can say that the root element will always be the maximum element in the heap.

Time Complexity:
    - getMax(): O(1)
    - extractMax(): O(log N)
    - increaseKey(): O(log N)
    - insert(): O(log N)
    - delete(): O(log N)
*/
class MaxHeap {
    int *heapArray;
    int capacity;
    int heapSize;

public:
    MaxHeap(int capacity);

    void MaxHeapify(int);

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    int extractMax();
    void increaseKey(int i, int new_val);
    int getMax() { return heapArray[0]; }
    void deleteKey(int i);
    void insertKey(int k);
};

MaxHeap::MaxHeap(int cap) {
    heapSize = 0;
    capacity = cap;
    heapArray = new int[cap];
}

void MaxHeap::insertKey(int k) {
    if (heapSize == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    heapArray[i] = k;

    while (i != 0 && heapArray[parent(i)] < heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int i, int new_val) {
    heapArray[i] = new_val;
    while (i != 0 && heapArray[parent(i)] < heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::extractMax() {
    if (heapSize <= 0)
        return INT_MIN;
    if (heapSize == 1) {
        heapSize--;
        return heapArray[0];
    }

    int root = heapArray[0];
    heapArray[0] = heapArray[heapSize - 1];
    heapSize--;
    MaxHeapify(0);

    return root;
}

void MaxHeap::deleteKey(int i) {
    increaseKey(i, INT_MAX);
    extractMax();
}

void MaxHeap::MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heapSize && heapArray[l] > heapArray[i])
        largest = l;
    if (r < heapSize && heapArray[r] > heapArray[largest])
        largest = r;
    if (largest != i) {
        swap(heapArray[i], heapArray[largest]);
        MaxHeapify(largest);
    }
}