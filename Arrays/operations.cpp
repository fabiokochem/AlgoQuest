#include <iostream>
#include <array>

using std::cout;
using std::endl;

/*
Insertion Operation: For this operation, we can have the following cases:
    - Insertion at the beginning of the array.
    - Insertion at the end of the array.
    - Insertion at any given position in the array.

Deletion Operation: For this operation, we can have the following cases:
    - Deletion at the beginning of the array.
    - Deletion at the end of the array.
    - Deletion at any given position in the array.

Search Operation: For this operation, we can have the following cases:
    - Linear Search
    - Binary Search
*/

/*
Insertion at the beginning of the array.
    - Shift all elements to the right, then insert the new element at index 0.
    - Time complexity: O(n)
*/
void insertionBeggining(int arr[], int &size, int element){
    // Verifying if is possible to insert a new element
    if(size == sizeof(arr) / sizeof(arr[0])){
        cout << "Array is full" << endl;
    }

    // Shifting all elements to the right
    for(int i = size; i > 0; i--){
        arr[i] = arr[i-1];
    }

    arr[0] = element;
    size++;
}

/*
Insertion at the end of the array.
    - Insert the new element at the end of the array.
    - Time complexity: O(1)
*/
void insertionEnd(int arr[], int &size, int element){
    // Verifying if is possible to insert a new element
    if(size == sizeof(arr) / sizeof(arr[0])){
        cout << "Array is full" << endl;
    }

    arr[size] = element;
    size++;
}

/*
Insertion at any given position in the array.
    - Shift all elements to the right, then insert the new element at the given index.
    - Time complexity: O(n)
*/
void insertionAt(int arr[], int &size, int element, int index){
    // Verifying if is possible to insert a new element
    if(size == sizeof(arr) / sizeof(arr[0])){
        cout << "Array is full" << endl;
    }

    // Shifting all elements to the right
    for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
    }

    arr[index] = element;
    size++;
}

/*
Deletion at the beginning of the array.
    - Shift all elements to the left, then delete the element at index 0.
    - Time complexity: O(n)
*/
void deletionBeggining(int arr[], int &size){
    // Verifying if is possible to delete an element
    if(size == 0){
        cout << "Array is empty" << endl;
    }

    // Shifting all elements to the left
    for(int i = 0; i < size; i++){
        arr[i] = arr[i+1];
    }

    size--;
}

/*
Deletion at the end of the array.
    - Delete the element at the end of the array.
    - Time complexity: O(1)
*/ 
void deletionEnd(int arr[], int &size){
    // Verifying if is possible to delete an element
    if(size == 0){
        cout << "Array is empty" << endl;
    }

    size--;
}

/*
Deletion at any given position in the array.
    - Shift all elements to the left, then delete the element at the given index.
    - Time complexity: O(n)
*/
void deletionAt(int arr[], int &size, int index){
    // Verifying if is possible to delete an element
    if(size == 0){
        cout << "Array is empty" << endl;
    }

    // Shifting all elements to the left
    for(int i = index; i < size; i++){
        arr[i] = arr[i+1];
    }

    size--;
}

/*
Linear Search
    - Search for an element in the array.
    - Time complexity: O(n)
*/
int linearSearch(int arr[], int size, int element){
    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            return i;
        }
    }

    return -1;
}

/*
Binary Search (For sorted arrays)
    - Search for an element in the array.
    - Time complexity: O(log n)
*/
int binarySearch(int arr[], int size, int element){
    int left = 0;
    int right = size - 1;

    while(left <= right){
        int middle = left + (right - left) / 2;

        if(arr[middle] == element){
            return middle;
        }

        if(arr[middle] < element){
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

int main(){
    int arr[5] = {0, 1, 2, 3, 4}; // Array of 5 integers
    int size = 5;

    // Insertion at the beginning of the array
    insertionBeggining(arr, size, -1);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insertion at the end of the array
    insertionEnd(arr, size, 5);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Insertion at any given position in the array
    insertionAt(arr, size, 2, 2);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deletion at the beginning of the array
    deletionBeggining(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deletion at the end of the array
    deletionEnd(arr, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deletion at any given position in the array
    deletionAt(arr, size, 2);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Linear Search
    cout << linearSearch(arr, size, 3) << endl;

    // Binary Search
    cout << binarySearch(arr, size, 3) << endl;

    return 0;
}