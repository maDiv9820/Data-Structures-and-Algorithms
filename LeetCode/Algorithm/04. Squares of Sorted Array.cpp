/*
Squares of a Sorted Array

Given an integer array nums sorted in non-decreasing order, 
return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    /*
        Solution 1:- Square of each value in nums and then sort it
        Time Complexity:- O(nlog(n))
        Space Complexity:- O(n)
        where n is size of nums
    
    vector<int> squares(nums.size(),0);
    for(int index = 0; index < nums.size(); index++)
        squares[index] = nums[index]*nums[index];
    sort(squares.begin(),squares.end());
    return squares;
    */
   /*
        Solution 2:- Using Merge Sorted Array Algo
        Time Complexity: O(n)
        Space Complexity: O(n)
        where n is the size of nums
   */
    vector<int> squares(nums.size(),0);
    int pivot = 0;
    for(; pivot < nums.size() && nums[pivot] < 0; pivot++);
    int index1 = pivot-1, index2 = pivot, index = 0;
    while(index1 >= 0 && index2 < nums.size()) {
        if(abs(nums[index1]) <= abs(nums[index2])) {
            squares[index++] = nums[index1]*nums[index1];
            index1--;
        }
        else {
            squares[index++] = nums[index2]*nums[index2];
            index2++;
        }
    }
    while(index1 >= 0) {
        squares[index++] = nums[index1]*nums[index1];
        index1--;
    }
    while(index2 < nums.size()) {
        squares[index++] = nums[index2]*nums[index2];
        index2++;
    }
    return squares;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    vector<int> squares = sortedSquares(nums);
    for(int x: squares)
        cout << x << " ";
    cout << endl;
}