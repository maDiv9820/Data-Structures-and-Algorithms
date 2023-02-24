/*
Next Greater Element I

The next greater element of some element x in an array is 
the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, 
where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] 
and determine the next greater element of nums2[j] in nums2. 
If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Example 2:

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

Constraints:

    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    All integers in nums1 and nums2 are unique.
    All the integers of nums1 also appear in nums2.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    for(int index1 = 0; index1 < nums1.size(); index1++) {
        for(int index2 = 0; index2 < nums2.size(); index2++) {
            if(nums1[index1] == nums2[index2]) {
                bool found = false;
                for(int index3 = index2+1; index3 < nums2.size(); index3++) {
                    if(nums2[index3] > nums1[index1]) {
                        found = true;
                        ans.emplace_back(nums2[index3]);
                        break;
                    }
                }
                if(!found)
                    ans.emplace_back(-1);
                break;
            }
        }
    }
    return ans;    
}
int main() {
    int n1,n2;
    cin >> n1 >> n2;
    vector<int> nums1(n1,0), nums2(n2,0);
    for(int index = 0; index < n1; index++)
        cin >> nums1[index];
    for(int index = 0; index < n2; index++)
        cin >> nums2[index];
    vector<int> ans = nextGreaterElement(nums1,nums2);
    for(const int &x: ans)
        cout << x << " ";
    cout << endl;
}