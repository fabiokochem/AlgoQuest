#include <iostream>

using std::cout;
using std::endl;

/*
The Kadane's Algorithm is used to find the maximum sum of a contiguous subarray within a one-dimensional array of numbers.
The algorithm is based on the idea that a subarray ending at index i will have the maximum sum if the sum of the subarray ending at index i-1 is positive.

The algorithm works as follows:
1. Initialize two variables, curr_val and global_val, to the first element of the array.
2. Iterate over the array starting from the second element.
3. At each iteration, update curr_val to be the maximum of the current element and the sum of the current element and curr_val.
4. Update global_val to be the maximum of curr_val and global_val.
5. Return global_val as the maximum sum of a contiguous subarray.
*/

// Simple function to return the maximum of two integers
int max(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

// The Kadane's Algorithm function
// Time Complexity: O(n)
int KadaneAlgo(int arr[], int arrSize){
    int curr_val = arr[0];
    int global_val = arr[0];

    for(int i = 1; i < arrSize; i++){
        curr_val = max(arr[i], curr_val + arr[i]);
        global_val = max(curr_val, global_val);
    }

    return global_val;
}

int main(){
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum sum of contiguous subarray: " << KadaneAlgo(arr, arrSize) << endl;

    return 0;
}