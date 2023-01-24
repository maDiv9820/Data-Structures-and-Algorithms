/*
Min Cost Climbing Stairs

You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.

Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.

Constraints:

    2 <= cost.length <= 1000
    0 <= cost[i] <= 999
*/

#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(int pos, vector<int>& cost, vector<int>& minCost) {
    if(pos >= cost.size())
        return 0;
    if(minCost[pos] != INT_MAX)
        return minCost[pos];
    int cost1 = minCostClimbingStairs(pos+1,cost,minCost);
    int cost2 = minCostClimbingStairs(pos+2,cost,minCost);
    minCost[pos] = cost[pos]+min(cost1,cost2);
    return minCost[pos];
}

int minCostClimbingStairs(vector<int>& cost) {
    /*
        Solution 1:- Using Recursion
        Time Complexity:- O(2^n)
        Space Complexity:- O(n)
    
    return min(minCostClimbingStairs(0,cost),minCostClimbingStairs(1,cost));
    */
    /*
        Solution 2:- Using Memoization
        Time Complexity:- O(n)
        Space Complexity:- O(n)

    vector<int>minCost(cost.size(),INT_MAX);
    minCost[0] = min(minCostClimbingStairs(0,cost,minCost),minCostClimbingStairs(1,cost,minCost));
    return minCost[0];
    */
    /*
        Solution 3:- Dynamic Programming
        Time Complexity:- O(n)
        Space Complexity:- O(n)
    */
    vector<int> minCost(cost.size(),INT_MAX);
    minCost[cost.size()-1] = cost[cost.size()-1];
    minCost[cost.size()-2] = cost[cost.size()-2];
    for(int index = cost.size()-3; index >= 0; index--)
        minCost[index] = cost[index] + min(minCost[index+1],minCost[index+2]);
    return min(minCost[0],minCost[1]);
}

int main() {
    int n;
    cin >> n;
    vector<int> cost(n,0);
    for(int index = 0; index < n; index++)
        cin >> cost[index];
    cout << minCostClimbingStairs(cost) << endl;
}