#include <iostream>

using std::swap;
using std::endl;
using std::cout;

/*
In sorting algorithms, the terms stable and unstable refer to whether or not the algorithm preserves the relative order of elements with equal keys (or values).
    - Stable Sort: A sorting algorithm is said to be stable if it maintains the relative order of equal elements.
    - Unstable Sort: An unstable sort does not guarantee the relative order of equal elements. If two elements are equal, their order may change after sorting.

Stable Sorting Algorithms:
    - Merge Sort
    - Insertion Sort
    - Bubble Sort

Unstable Sorting Algorithms:
    - Quick Sort
    - Heap Sort
    - Selection Sort

Stability is important when sorting records where the sorting key is not unique. 
For example, consider sorting a list of students by their grades, but maintaining the relative order of students with the same grade based on their names.
*/

// Implementation of Insertion Sort (Stable Sort). You can find the explanation of the algorithm in Sorts/insertion_sort.cpp 
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Implementation of Selection Sort (Unstable Sort). You can find the explanation of the algorithm in Sorts/selection_sort.cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main(){
    int arr1[] = {12, 11, 13, 5, 6};
    int arr2[] = {12, 11, 13, 5, 6};
    
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    insertionSort(arr1, n1);
    selectionSort(arr2, n2);

    cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < n1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < n2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}