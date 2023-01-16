/*
Intersection of Two Arrays II

Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and 
you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted. 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000

*/

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int start, int end, int val) {
    if(start > end)
        return false;
    int mid = (start+end)/2;
    if(nums[mid] == val) {
        nums[mid] = INT_MAX;
        return true;
    }
    if(nums[mid] == INT_MAX) {
        bool left = search(nums,start,mid-1,val);
        if(left)
            return left;
        return search(nums,mid+1,end,val);
    }
    else if(nums[mid] < val)
        return search(nums,mid+1,end,val);
    return search(nums,start,mid-1,val);
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    /*
        Solution 1:- Using Nested Loops
        Time Complexity:- O(n*m)
        Space Complexity:- O(1)
        where n and m are the size of nums1 and nums2 respectively.
    
    vector<int> intersections;
    for(int outerIndex = 0; outerIndex < nums1.size(); outerIndex++) {
        for(int innerIndex = 0; innerIndex < nums2.size(); innerIndex++) {
            if(nums1[outerIndex] == nums2[innerIndex]) {
                intersections.push_back(nums1[outerIndex]);
                nums2[innerIndex] = INT_MAX;
                break;
            }
        }
    }
    return intersections;
    */
    /*
        Solution 2:- Using Binary Search
        Time Complexity:- O(nlog(n)+mlog(m)+nlog(m))
        Space Complexity:- O(n)
    */
    vector<int> intersections;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for(int x: nums1)
        if(search(nums2,0,nums2.size()-1,x))
            intersections.push_back(x);
    return intersections;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums1[index];
    cin >> n;
    vector<int> nums2(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums2[index];
    vector<int> intersections = intersect(nums1,nums2);
    for(int index = 0; index < intersections.size(); index++)
        cout << intersections[index] << " ";
    cout << endl;
}