#include <iostream>

#include <iostream>
#include <vector>
#include <algorithm> 

using std::cout;
using std::endl;
using std::vector;

/*
Bucket Sort is a algorithm that distributes the elements of an array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm or by recursively applying the bucket sort algorithm.

Algorithm Steps:
    - Create an empty array of buckets.
    - Distribute the input array elements into the buckets.
    - Sort each bucket individually.
    - Concatenate the sorted buckets to get the final sorted array.

Time Complexity:
    - Best Case: O(n + k) - occurs when the input is uniformly distributed.
    - Average Case: O(n + k) - depends on the distribution of the input.
    - Worst Case: O(n^2) - occurs when all elements are placed in a single bucket.

Fun Fact: Bucket Sort is particularly useful when the input is uniformly distributed over a range.
*/
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    vector<vector<int>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n / 100; 
        buckets[bucketIndex].push_back(arr[i]);
    }

    arr.clear();
    for (int i = 0; i < n; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); j++) {
            arr.push_back(buckets[i][j]);
        }
    }
}

int main() {
    vector<int> arr = {34, 2, 10, 6, 8, 3, 1, 5};

    bucketSort(arr);
    
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

