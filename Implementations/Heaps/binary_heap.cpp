#include <iostream>
#include <climits>

using namespace std;

/*
A Binary Heap is a Binary Tree with the following properties:
    1. It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible).
    2. A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

Operations on Max Heap:
    1. getMax(): It returns the root element of Max Heap. Time Complexity of this operation is O(1).
    2. extractMax(): Removes the maximum element from MaxHeap. Time Complexity of this Operation is O(log N) where N is the number of nodes.
    3. increaseKey(): Increase value of a key. The time complexity of this operation is O(log N) where N is the number of nodes.
    4. insert(): Insert a new key. The time complexity of this operation is O(log N) where N is the number of nodes.
    5. delete(): Delete a key. The time complexity of this operation is O(log N) where N is the number of nodes.

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

    void MaxHeapify(int index);

    int parent(int index) { return (index - 1) / 2; }
    int left(int index) { return (2 * index + 1); }
    int right(int index) { return (2 * index + 2); }

    int extractMax();
    void increaseKey(int index, int newValue);
    int getMax() { return heapArray[0]; }
    void deleteKey(int index);
    void insertKey(int key);
};

MaxHeap::MaxHeap(int cap) {
    heapSize = 0;
    capacity = cap;
    heapArray = new int[cap];
}

void MaxHeap::insertKey(int key) {
    if (heapSize == capacity) {
        cout << "Overflow: Could not insertKey\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    heapArray[i] = key;

    while (i != 0 && heapArray[parent(i)] < heapArray[i]) {
        swap(heapArray[i], heapArray[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int index, int newValue) {
    heapArray[index] = newValue;
    while (index != 0 && heapArray[parent(index)] < heapArray[index]) {
        swap(heapArray[index], heapArray[parent(index)]);
        index = parent(index);
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

void MaxHeap::deleteKey(int index) {
    increaseKey(index, INT_MAX);
    extractMax();
}

void MaxHeap::MaxHeapify(int index) {
    int l = left(index);
    int r = right(index);
    int largest = index;
    if (l < heapSize && heapArray[l] > heapArray[largest])
        largest = l;
    if (r < heapSize && heapArray[r] > heapArray[largest])
        largest = r;
    if (largest != index) {
        swap(heapArray[index], heapArray[largest]);
        MaxHeapify(largest);
    }
}