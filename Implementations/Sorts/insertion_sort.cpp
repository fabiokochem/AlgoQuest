#include <iostream>

using std::cout;
using std::endl;

/*
Insertion Sort is a algorithm that builds the final sorted array one item at a time.

Algorithm Steps:
    - Start with the first element as the sorted part.
    - Take the next element and insert it into the sorted part by comparing it with each element in the sorted part from right to left.
    - Shift elements in the sorted part to make space for the new element.
    - Repeat until all elements are sorted.

Time Complexity:
    - Best Case: O(n) - occurs when the list is already sorted.
    - Average Case: O(n^2) - occurs for random order of elements.
    - Worst Case: O(n^2) - occurs when the list is sorted in reverse order.
*/
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}