#include <iostream>
#include <vector>

using namespace std;

/*
This code was my only attempt to the problem. Basically here i use the Kadane's algorithm to solve the problem.
If you don't know the algorithm, you can see it in this repository in the file Arrays/kadane_algo.cpp

The steps that i built to reach this solution:
    - I will need two variables to store the current value and the global value, so i will create them.
    - From this, i will iterate over the array and for each element, i will calculate the maximum value between the element and the sum of the current value and the element.
    - If the current value is greater than the global value, i will update the global value.
    - At the end, i will return the global value.

Good solution, O(n).
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_val = nums[0];
        int global_val = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            curr_val = max(nums[i], curr_val + nums[i]);
            global_val = max(global_val, curr_val);
        }

        return global_val;
    }
};