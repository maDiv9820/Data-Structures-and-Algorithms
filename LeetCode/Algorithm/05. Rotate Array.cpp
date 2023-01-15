/*
    Rotate Array
    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.     

    Example 1:

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
    Explanation:
    rotate 1 steps to the right: [7,1,2,3,4,5,6]
    rotate 2 steps to the right: [6,7,1,2,3,4,5]
    rotate 3 steps to the right: [5,6,7,1,2,3,4]

    Example 2:

    Input: nums = [-1,-100,3,99], k = 2
    Output: [3,99,-1,-100]
    Explanation: 
    rotate 1 steps to the right: [99,-1,-100,3]
    rotate 2 steps to the right: [3,99,-1,-100]

    Constraints:

    1 <= nums.length <= 105
    -231 <= nums[i] <= 231 - 1
    0 <= k <= 105

*/

#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    /*
        Solution 1:- Using Nested Loops
        Time Complexity:- O(n*k)
        Space Complexity:- O(1)
        where n is the size of the nums
    
    for(int count = 1; count <= k; count++) {
        int lastValue = nums[nums.size()-1];
        for(int index = nums.size()-1; index > 0; index--)
            nums[index] = nums[index-1];
        nums[0] = lastValue;
    }
    */
    /*
        Solution 2:- Using Reverse Algorithm
        Time Complexity:- O(n)
        Space Complexity:- O(1)
        where n is the size of the nums
    */
    k = k%nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

int main() {
    int n, k;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    cin >> k;
    rotate(nums,k);
    for(int index = 0; index < n; index++)
        cout << nums[index] << " ";
    cout << endl;
}