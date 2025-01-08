#include <iostream>

using std::endl;
using std::cout;
using std::swap;

/*
Selection Sort is a algorithm that divides the input list into two parts: a sorted part and an unsorted part. It repeatedly selects the smallest (or largest, depending on the order) element from the unsorted part and moves it to the end of the sorted part.

Algorithm Steps:
    - Start with the first element as the minimum.
    - Compare this minimum with the next element in the list.
    - If the next element is smaller than the current minimum, update the minimum.
    - Continue this process until the end of the list is reached.
    - Swap the found minimum element with the first element of the unsorted part.
    - Move to the next element and repeat the process until the entire list is sorted.

Time Complexity:
    - Best Case: O(n^2) - occurs when the list is already sorted.
    - Average Case: O(n^2) - occurs for random order of elements.
    - Worst Case: O(n^2) - occurs when the list is sorted in reverse order.
*/
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}