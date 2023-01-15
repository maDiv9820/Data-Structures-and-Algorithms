/*
    Merge Sorted Array

    You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
    and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
    Merge nums1 and nums2 into a single array sorted in non-decreasing order.
    The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
    To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n. 

    Example 1:

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

    Example 2:

    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]
    Explanation: The arrays we are merging are [1] and [].
    The result of the merge is [1].

    Example 3:

    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]
    Explanation: The arrays we are merging are [] and [1].
    The result of the merge is [1].
    Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.

    Constraints:

        nums1.length == m + n
        nums2.length == n
        0 <= m, n <= 200
        1 <= m + n <= 200
        -109 <= nums1[i], nums2[j] <= 109

*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /*
        Time Complexity: O(n+m)
        Space Complexity: O(m)
        where n and m are the size of nums2 and nums1 respectively
    */
    int index1 = 0, index2 = 0, index = 0;
    vector<int> temp(m,0);
    for(int ind = 0; ind < m; ind++)
        temp[ind] = nums1[ind];
    while(index1 < m && index2 < n) {
        if(temp[index1] <= nums2[index2])
            nums1[index++] = temp[index1++];
        else
            nums1[index++] = nums2[index2++];
    }
    while(index1 < m)
        nums1[index++] = temp[index1++];
    while(index2 < n)
        nums1[index++] = nums2[index2++];
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<int> nums1(m+n,0), nums2(n,0);
    for(int index = 0; index < m; index++)
        cin >> nums1[index];
    for(int index = 0; index < n; index++)
        cin >> nums2[index];
    merge(nums1,m,nums2,n);
    for(int index = 0; index < m+n; index++)
        cout << nums1[index] << " ";
    cout << endl;
}