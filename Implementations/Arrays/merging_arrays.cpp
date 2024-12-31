#include <iostream>
#include <array>

using std::cout;
using std::endl;

/*
For this approach, we will consider that the arrays are unsorted.
The process is straightforward:
    - Create a new array with the size of the sum of the sizes of the two arrays.
    - Copy the elements of the first array to the new array.
    - Copy the elements of the second array to the new array.
    - Time Complexity: O(n + m)
*/
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int mergedArr[]){
    int index = 0;
    
    for(int i = 0; i < size1; i++){
        mergedArr[index] = arr1[i];
        index++;
    }
    
    for(int i = 0; i < size2; i++){
        mergedArr[index] = arr2[i];
        index++;
    }
}

int main(){
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int mergedArr[size1 + size2];
    
    mergeArrays(arr1, size1, arr2, size2, mergedArr);
    
    for(int i = 0; i < size1 + size2; i++){
        cout << mergedArr[i] << " ";
    }
    
    return 0;
}