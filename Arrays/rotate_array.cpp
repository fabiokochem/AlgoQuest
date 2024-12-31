#include <iostream>

using std::cout;
using std::endl;

/*
Rotating an array involves shifting its elements to the left or right while keeping its circular continuity. 
For example, rotating the array [1, 2, 3, 4, 5] to the right by 2 steps results in [4, 5, 1, 2, 3].

Types of Array Rotation
    - Left Rotation: Shift elements to the left.
    - Right Rotation: Shift elements to the right.
*/



/*
Left Rotate an Array by One Position
    - Time Complexity: O(n)
*/
void leftRotateByOne(int arr[], int size){
    int temp = arr[0]; // Store the first element in a temporary variable
    
    for(int i = 0; i < size - 1; i++){
        arr[i] = arr[i + 1]; // Shift each element one position to the left
    }
    
    arr[size - 1] = temp; // Move the first element to the last position
}

/* 
Complete Left Rotation of an Array
    - Time Complexity: O(n * d)
*/
void leftRotate(int arr[], int size, int steps){
    for(int i = 0; i < steps; i++){
        leftRotateByOne(arr, size); // Perform a single left rotation
    }
}

/* 
Right Rotate an Array by One Position
    - Time Complexity: O(n)
*/
void rightRotateByOne(int arr[], int size){
    int temp = arr[size - 1]; // Store the last element in a temporary variable
    
    for(int i = size - 1; i > 0; i--){
        arr[i] = arr[i - 1]; // Shift each element one position to the right
    }
    
    arr[0] = temp; // Move the last element to the first position
}

/*
Complete Right Rotation of an Array
    - Time Complexity: O(n * d)
*/
void rightRotate(int arr[], int size, int steps){
    for(int i = 0; i < steps; i++){
        rightRotateByOne(arr, size); // Perform a single right rotation
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int steps = 2;
    
    cout << "Original Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    leftRotate(arr, size, steps);
    
    cout << "\nLeft Rotated Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    rightRotate(arr, size, steps);
    
    cout << "\nRight Rotated Array: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}