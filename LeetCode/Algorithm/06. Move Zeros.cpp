/*
Move Zeroes

Given an integer array nums, move all 0's to the end of it while 
maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

Constraints:

    1 <= nums.length <= 104
    -231 <= nums[i] <= 231 - 1

*/

#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    /*
        Solution:- Putting non zero value at start
        Time Complexity:- O(n)
        Space Complexity:- O(1)
    */
    int nonZeroIndex = 0;
    for(int index = 0; index < nums.size(); index++) {
        if(nums[index] != 0) {
            swap(nums[index], nums[nonZeroIndex]);
            nonZeroIndex++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    moveZeroes(nums);
    for(int index = 0; index < n; index++)
        cout << nums[index] << " ";
    cout << endl;
}