#include <iostream>

using std::cout;
using std::endl;

/*
Radix Sort is a algorithm that sorts numbers by processing individual digits. It works by sorting the numbers based on each digit, starting from the least significant digit (LSD) to the most significant digit (MSD). Radix Sort is not a comparison-based sort and can be more efficient than comparison-based algorithms like Quick Sort or Merge Sort for certain types of data.

Algorithm Steps:
    - Find the maximum number to determine the number of digits.
    - Perform counting sort for each digit, starting from the least significant digit to the most significant digit.
    - Repeat the counting sort for each digit.

Time Complexity:
    - Best Case: O(nk)
    - Average Case: O(nk)
    - Worst Case: O(nk)
*/
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] > max)
            max = arr[i];
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}