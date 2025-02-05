#include <iostream>
#include <climits>

using namespace std;

/*
A Heapify Operation is a process of converting a complete binary tree into a Heap data structure. It is used to create a heap from a binary tree. It is a bottom-up process that converts a binary tree satisfying the heap property into a heap. The heapify operation is performed on the internal nodes of a binary tree. The leaf nodes are already heapified.

Time Complexity:
    - getMax(): O(1)
    - extractMax(): O(log N)
    - increaseKey(): O(log N)
    - insert(): O(log N)
    - delete(): O(log N)
*/
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void printHeap(int arr[], int n) {
    cout << "Array representation of Heap is:\n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    buildHeap(arr, n);

    printHeap(arr, n);

    return 0;
}