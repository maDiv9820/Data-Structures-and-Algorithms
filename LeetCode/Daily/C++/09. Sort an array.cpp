/*
Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity 
and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

Constraints:

    1 <= nums.length <= 5 * 104
    -5 * 104 <= nums[i] <= 5 * 104
*/
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums, int start, int mid, int end) {
    vector<int> temp1, temp2;
    for(int index = start; index <= mid; index++)
        temp1.emplace_back(nums[index]);
    for(int index = mid+1; index <= end; index++)
        temp2.emplace_back(nums[index]);
    int index1 = 0, index2 = 0, index = start;
    while(index1 < temp1.size() && index2 < temp2.size()) {
        if(temp1[index1] <= temp2[index2])
            nums[index++] = temp1[index1++];
        else
            nums[index++] = temp2[index2++];
    }
    while(index1 < temp1.size())
        nums[index++] = temp1[index1++];
    while(index2 < temp2.size())
        nums[index++] = temp2[index2++];
}
void mergeSort(vector<int>& nums, int start, int end) {
    if(start >= end)
        return;
    int mid = (start+end)/2;
    mergeSort(nums,start,mid);
    mergeSort(nums,mid+1,end);
    merge(nums,start,mid,end);
}
vector<int> sortArray(vector<int>& nums) {
    /*
    Solution 1: Using merge sort algorithm
    Time Complexity:- O(nlogn)
    Space Complexity:- O(n)
    
    mergeSort(nums,0,nums.size()-1);
    return nums;
    */
    /*
    Solution 2: Using priority queues
    Time Complexity:- O(nlogn)
    Space Complexity:- O(n)
    */
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int index = 0; index < nums.size(); index++)
        pq.push(nums[index]);
    int index = 0;
    while(!pq.empty()) {
        nums[index++] = pq.top();
        pq.pop();
    }
    return nums;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    vector<int> sortedArray = sortArray(nums);
    for(const int& x: sortedArray)
        cout << x << " ";
    cout << endl;
}