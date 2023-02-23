/*
IPO

Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, 
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited resources, 
it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total 
capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and
a minimum capital of capital[i] is needed to start it. Initially, you have w capital. 
When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, 
and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:

Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

Example 2:

Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6

 

Constraints:

    1 <= k <= 105
    0 <= w <= 109
    n == profits.length
    n == capital.length
    1 <= n <= 105
    0 <= profits[i] <= 104
    0 <= capital[i] <= 109


*/
#include <bits/stdc++.h>
using namespace std;
bool condition(vector<int> v1, vector<int> v2) {
    if(v1[1] > v2[1])
        return true;
    if(v1[1] == v2[1] && v1[2] > v2[2])
        return true;
    return false;
}
int findMaximizedCapital(int k, int w, vector<int>& profits,vector<int>& capital) {
    /*
    Solution 1:-
    Time Complexity:- O(profits.size()^2)
    Space Complexity:- O(profits.size())
    if(k == 0 || index >= capital.size())
        return w;
    if(w >= capital[index]) {
        int ch1 = findMaximizedCapital(k-1,w+profits[index],profits,capital,index+1);
        int ch2 = findMaximizedCapital(k,w,profits,capital,index+1);
        return max(ch1,ch2);

    }
    return findMaximizedCapital(k,w,profits,capital,index+1);
    */
    /*
        Solution 2:-
        Time Complexity:- O(nlogn)
        Space Complexity:- O(n)
        where n is the size of profits
    */
    vector<pair<int,int>> projects(profits.size());
    for(int index = 0; index < profits.size(); index++) {
        projects[index] = {capital[index],profits[index]};
    }
    sort(projects.begin(),projects.end());
    priority_queue<int> best_profit;
    for(const auto& [cost,profit]: projects) {
        while(!best_profit.empty() && w < cost && k--) {
            w += best_profit.top(); best_profit.pop();
        }
        if(!k && w < cost) return w;
        best_profit.push(profit);
    }
    while(k-- && !best_profit.empty()) {
        w += best_profit.top(); best_profit.pop();
    }
    return w;
}
int main() {
    int k,w,n;
    cin >> k >> w >> n;
    vector<int> profits(n,0), capital(n,0);
    for(int index = 0; index < n; index++)
        cin >> profits[index];
    for(int index = 0; index < n; index++)
        cin >> capital[index];
    cout << findMaximizedCapital(k,w,profits,capital) << endl;
}