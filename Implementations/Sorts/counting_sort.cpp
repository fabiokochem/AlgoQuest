#include <iostream>

using std::cout;
using std::endl;

/*
Couting Sort is a algorithm that sorts a list of integers by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence.

Algorithm Steps:
    - Find the maximum value in the array.
    - Create a count array to store the count of each unique object.
    - Store the count of each number in the count array.
    - Change the count array such that each element at each index stores the sum of previous counts.
    - Build the output array by placing the elements in their correct position.

Time Complexity:
    - Best Case: O(n + k) - occurs when the list is already sorted.
    - Average Case: O(n + k) - occurs for random order of elements.
    - Worst Case: O(n + k) - occurs when the list is sorted in reverse order.
*/
void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int count[maxVal + 1] = {0};

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main(){
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}