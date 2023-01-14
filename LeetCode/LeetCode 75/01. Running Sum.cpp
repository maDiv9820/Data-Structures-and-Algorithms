#include <bits/stdc++.h>
using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> runningSumVector(nums.size(),0);
    runningSumVector[0] = nums[0];
    for(int index = 0; index < nums.size(); index++)
        runningSumVector[index] = runningSumVector[index-1]+nums[index];
    return runningSumVector;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    vector<int> runningSumVector = runningSum(nums);
    for(int x: runningSumVector)
        cout << x << " ";
    cout << endl;
}