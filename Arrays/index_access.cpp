#include <iostream>

using std::cout;
using std::endl;

/*
What is an Index?
    - An index is the position of an element in an array.
    - Arrays are zero-indexed, meaning the first element is at index 0, the second element is at index 1, and so on.
    - The index of the last element in an array is the size of the array minus one.
*/

int main(){
    int arr[5] = {0, 1, 2, 3, 4}; // Array of 5 integers
    
    cout << arr[0] << endl; // To access an element, you specify the array name followed by the index in square brackets ([]). Output = 0
    cout << arr[1] << endl; // Output = 1

    return 0;
}

/*
Time Complexity of Index Access
Accessing an element by index is very efficient:
    - Time Complexity: O(1) (constant time)
    - This is because arrays allow direct access to any element using its index. 
*/