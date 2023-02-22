#include <bits/stdc++.h>
using namespace std;
int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    for(int index = 0; index < nums.size()-2; index++) {
    int a = nums[index], b = nums[index+1], c = nums[index+2];
        if(a + b <= c || a + c <= b || b + c <= a) continue;
        else return a+b+c;
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    cout << largestPerimeter(nums) << endl;
}