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