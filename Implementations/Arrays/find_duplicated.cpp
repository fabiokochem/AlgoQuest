#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;

/*
When we are searching for duplicates in a Array, we can use two methods:
    - Brute Force: Compare each element with every other element in the array.
    - Sorting: Sort the array and then check for duplicates.

The brute force case is simple but inefficient. It has a time complexity of O(n^2).
The sorting case is more efficient with a time complexity of O(n log n).
*/

/*
This function finds duplicates in an array using the Brute Force method.
Pay attention that we need to compare each element with every other element in the array.

Time Complexity: O(n^2)
*/
void Find_BF(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(arr[i] == arr[j]){
                cout << "Duplicated found of " << arr[i] << endl;
            }
        }
    }
}

/*
This function finds duplicates in an array using the Sorting method.
Pay attention that we need to sort the array first and then check for duplicates. In that way, we can compare each element with the next one.

Time Complexity: O(n log n)
*/
void Find_Sort(int arr[], int arrSize){
    std::sort(arr, arr + arrSize);

    for(int i = 0; i < arrSize - 1; i++){
        if(arr[i] == arr[i + 1]){
            cout << "Duplicated found of " << arr[i] << endl;
        }
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 2, 5, 6, 1};
    
    //Find_BF(arr, sizeof(arr) / sizeof(arr[0]));
    // Find_Sort(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}