#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    // Time Complexity:- O(log(n)), Space Complexity:- O(1)
    for(int start = 0, end = nums.size()-1; start <= end;) {
        int mid = (start+end)/2;
        if(nums[mid] == target)
            return mid;
        start = (nums[mid]<target) ? mid+1:start;
        end = (nums[mid]>target) ? mid-1:end;
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
    int index = search(nums,target);
    cout << index << endl;
}