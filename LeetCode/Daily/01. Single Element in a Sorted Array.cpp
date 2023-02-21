#include <bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1;
    while(low <= high) {
        if(low == high)
            return nums[low];
        int mid = (low+high)/2;
        if(mid%2 == 0) {
            if(nums[mid] == nums[mid+1])
                low = mid+2;
            else
                high = mid;
        }
        else{
            if(nums[mid] == nums[mid-1])
                low = mid+1;
            else
                high = mid-1;
        }
    } 
    return INT_MAX;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    int nonDuplicate = singleNonDuplicate(nums);
    cout << nonDuplicate << endl;
}