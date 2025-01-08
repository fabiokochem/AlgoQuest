#include <iostream>

using std::endl;
using std::cout;

/*
Bubble Sort is a sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order, reapeating the process until the list is sorted.

Algorithm Steps:
    - Start at the beginning of the list.
    - Compare the first two adjacent elements.
    - If the first element is greater than the second, swap them.
    - Move to the next pair of adjacent elements and repeat the comparison and swap if necessary.
    - Continue this process until the end of the list is reached

Time Complexity:
    - Best Case: O(n) - occurs when the list is already sorted.
    - Average Case: O(n^2) - occurs for random order of elements.
    - Worst Case: O(n^2) - occurs when the list is sorted in reverse order.

Fun Fact: Bubble Sort is named because smaller elements "bubble" to the top of the list.
*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);
    
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}