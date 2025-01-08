#include <iostream>

using std::cout;
using std::endl;
using std::swap;

/*
Quick Sort is a algorithm that uses a divide and conquer strategy to sort an array. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively.

Algorithm Steps:
    - Choose a pivot element from the array.
    - Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
    - Recursively apply the same logic to the sub-arrays.

Time Complexity:
    - Best Case: O(n log n) - occurs when the pivot divides the array into two equal halves.
    - Average Case: O(n log n) - occurs for random order of elements.
    - Worst Case: O(n^2) - occurs when the pivot is the smallest or largest element in the array.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}