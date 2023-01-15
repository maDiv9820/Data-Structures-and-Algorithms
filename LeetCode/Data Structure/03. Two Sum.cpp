/*
    Two Sum

    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.
    You can return the answer in any order. 

    Example 1:

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

    Example 2:

    Input: nums = [3,2,4], target = 6
    Output: [1,2]

    Example 3:

    Input: nums = [3,3], target = 6
    Output: [0,1]   

    Constraints:

        2 <= nums.length <= 104
        -109 <= nums[i] <= 109
        -109 <= target <= 109
        Only one valid answer exists.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    /*
        Solution 1:- Using nested loops
        Time Complexity:- O(n^2)
        Space Complexity:- O(1)
        where n is the size of the nums
    */
    vector<int> pairs(2,-1);
    for(int index1 = 0; index1 < nums.size()-1; index1++) {
        bool found = false;
        for(int index2 = index1+1; index2 < nums.size(); index2++) {
            if(nums[index1]+nums[index2] == target) {
                found = true;
                pairs[0] = index1;
                pairs[1] = index2;
                break;
            }
        }
        if(found)
            break;
    }
    return pairs;
}

int main() {
    int n, target;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    cin >> target;
    vector<int> pair = twoSum(nums,target);
    cout << pair[0] << " " << pair[1] << endl;
}