/*
Two Sum

Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indices;
    if(nums.size() == 0)
        return indices;
    map<int,vector<int>*> m;
    for(int index = 0; index < nums.size(); index++) {
        if(m.count(nums[index]) == 0) {
            vector<int>* v = new vector<int>();
            m[nums[index]] = v;
        }
        m[nums[index]]->push_back(index);
    }
    for(int index = 0; index < nums.size(); index++) {
        if(m.count(target-nums[index]) == 1 && (target-nums[index] == nums[index])) {
            if(m[nums[index]]->size() > 1) {
                if(indices.size() == 0) {
                    indices.push_back(m[nums[index]]->at(0));
                    indices.push_back(m[nums[index]]->at(1));
                }
                else {
                    indices[0] = m[nums[index]]->at(0);
                    indices[1] = m[nums[index]]->at(1);
                }
            }
            else {
                if(indices.size() == 0) {
                    indices.push_back(index);
                    indices.push_back(index);
                }
                else {
                    indices[0] = index;
                    indices[1] = index;
                }
            }
            continue;
        }
        if(m.count(target-nums[index]) == 1 && (target-nums[index] != nums[index])) {
            if(indices.size() == 0){
                indices.push_back(index);
                indices.push_back(m[target-nums[index]]->at(0));
            }
            else {
                indices[0] = index;
                indices[1] = m[target-nums[index]]->at(0);
            }
            break;
        }
    }
    return indices;
}

int main() {
    int n,target;
    cin >> n;
    vector<int> nums(n,0);
    for(int index = 0; index < n; index++)
        cin >> nums[index];
    cin >> target;
    vector<int> indices = twoSum(nums,target);
    if(indices.size() > 0)
        cout << indices[0] << " " << indices[1] << endl;
}