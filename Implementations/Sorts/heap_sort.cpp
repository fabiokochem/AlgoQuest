#include <iostream>

using std::cout;
using std::endl;

/*
Heap Sort is a algorithm that uses a binary heap data structure to sort elements. It works by first building a max heap from the input data, and then repeatedly extracting the maximum element from the heap and rebuilding the heap until all elements are sorted.

Algorithm Steps:
    - Build a max heap from the input data.
    - Swap the root of the heap (the maximum element) with the last element of the heap.
    - Reduce the size of the heap by one and heapify the root.
    - Repeat the process until the heap is empty.

Time Complexity:   
    - Best Case: O(n log n) - when the input data is already sorted.
    - Average Case: O(n log n) - when the input data is randomly ordered.
    - Worst Case: O(n log n) - when the input data is in reverse order.
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
        std::swap(arr[i], arr[largest]); 

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}