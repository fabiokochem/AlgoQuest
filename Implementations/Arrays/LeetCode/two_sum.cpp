#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
This code was the my first attempt to solve the problem. It is a brute force solution, which is not the best way to solve this problem.
I was trying to think in a better solution but i prefered to submit this one to see if was correct my idea and to show one way to solve this problem.

The steps that i built to reach this solution:
    - I will need a vector of 2 positions to return, so i will create it.
    - From this, i will compare the sum of each pair of elements from the array starting in index 0, until i find a answer for my target.
    - Since i found a answer, i'll copy the index of both elements in arr and return it

Solve the problem but is a bad solution, O(n²).
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr(2);

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    arr[0] = i;
                    arr[1] = j;
                    return arr;
                }
            }
        }

        return arr;
    }
};

/*
This solution is the best way to solve this problem. In this solution, we use a hash table to store the elements that we already saw.
The steps that i built to reach this solution:
    - I will need a hash table to store the elements that i already saw, so i will create it.
    - From this, i will iterate over the array and for each element, i will calculate the complement of the element and the target.
    - If the complement is in the hash table, i will return the indexes of the elements that i found.
    - If the complement is not in the hash table, i will store the element in the hash table.

Good solution, O(n).
*/
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};