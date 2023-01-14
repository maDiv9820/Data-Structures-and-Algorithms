#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int leftsum = 0, rightsum = 0;
    for(int index = 0; index < nums.size(); index++)
        rightsum += nums[index];
    for(int index = 0; index < nums.size(); index++) {
        rightsum = rightsum-nums[index];
        if(leftsum == rightsum)
            return index;
        leftsum = leftsum+nums[index];
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    int pivot = pivotIndex(nums);
    cout << pivot << endl;
}