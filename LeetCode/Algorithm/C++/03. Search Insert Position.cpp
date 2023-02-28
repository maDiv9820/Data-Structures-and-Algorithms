#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    // Time Complexity:- O(log(n)), Space Complexity:- O(1)
    if(nums[0] >= target)
        return 0;
    if(target > nums[nums.size()-1])
        return nums.size();
    for(int start = 0, end = nums.size()-1; start <= end;) {
        int mid = (start+end)/2;
        if((nums[mid] == target && nums[mid-1] < target) || (nums[mid] > target && nums[mid-1] < target))
            return mid;
        else if(nums[mid] < target)
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    int target;
    cin >> target;
    int insertIndex = searchInsert(nums,target);
    cout << insertIndex << endl;
}