#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    // Solution 1:- Using sorting technique, Time Complexity = O(nlog(n)), Space Complexity = O(1)
    /*
    sort(nums.begin(), nums.end());
    for(int index = 0; index < nums.size()-1; index++)
        if(nums[index] == nums[index+1])
            return true;
    return false;
    */
    // Solution 2:- Using hashmap, Time Complexity = O(n), Space Complexity = O(n)
    map<int,int> m;
    for(int index = 0; index < nums.size(); index++) {
        if(m.count(nums[index]) == 1)
            return true;
        m[nums[index]]++;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    bool ans = containsDuplicate(nums);
    cout << ans << endl;
}