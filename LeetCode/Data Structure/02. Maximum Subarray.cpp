#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    // Solution 1:- Using Nested Loop, Time Complexity:- O(n^2), Space Complexity:- O(1)
    /*int maxSubArraySum = INT_MIN;
    for(int outerIndex = 0; outerIndex < nums.size(); outerIndex++) {
        int currentSum = 0;
        for(int innerIndex = outerIndex; innerIndex < nums.size(); innerIndex++) {
            currentSum += nums[innerIndex];
            if(currentSum > maxSubArraySum)
            maxSubArraySum = (currentSum>maxSubArraySum) ? currentSum:maxSubArraySum;
        }
    }
    return maxSubArraySum;*/

    // Solution 2:- Using Kadane's Algorithm, Time Complexity:- O(n), Space Complexity:- O(1)
    int maxSubArraySum = INT_MIN, currentSum = 0;
    for(int index = 0; index < nums.size(); index++) {
        currentSum += nums[index];
        maxSubArraySum = (currentSum>maxSubArraySum) ? currentSum:maxSubArraySum;
        if(currentSum < 0)
            currentSum = 0;
    }
    return maxSubArraySum;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    int maxSubArraySum = maxSubArray(nums);
    cout << maxSubArray << endl;
}