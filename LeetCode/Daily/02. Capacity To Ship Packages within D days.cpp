#include <bits/stdc++.h>
using namespace std;
int isPossible(vector<int>& weights, int midWeight, int days) {
    int currentWeight = 0, currentDay = 1;
    for(int index = 0; index < weights.size(); index++) {
        if(currentWeight + weights[index] <= midWeight)
            currentWeight += weights[index];
        else {
            currentWeight = weights[index];
            currentDay++;
        }
    }
    return currentDay <= days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = 0;
    int minWeight = INT_MAX;
    high = accumulate(weights.begin(), weights.end(), high);
    while(low <= high) {
        int midWeight = (low+high)/2;
        if(isPossible(weights,midWeight,days)) {
            minWeight = midWeight;
            high = midWeight-1;
        }
        else
            low = midWeight+1;
    }
    return minWeight;
}
int main() {
    int n, days;
    cin >> n;
    vector<int> weights(n,0);
    for(int index = 0; index < n; index++)
        cin >> weights[index];
    cin >> days;
    cout << shipWithinDays(weights,days) << endl;
}