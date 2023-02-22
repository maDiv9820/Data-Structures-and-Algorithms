#include <bits/stdc++.h>
using namespace std;
int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int ans = -1, minDist = INT_MAX;
    for(int index = 0; index < points.size(); index++) {
        if(points[index][0] == x || points[index][1] == y) {
            int dist = abs(x-points[index][0])+abs(y-points[index][1]);
            if(minDist > dist) {
                ans = index;
                minDist = dist;
            }
        }
    }
    return ans;
}
int main() {
    int x,y,n;
    cin >> x >> y >> n;
    vector<vector<int>> points(n,vector<int>(2,0));
    for(int index = 0; index < n; index++)
        cin >> points[index][0] >> points[index][1];
    cout << nearestValidPoint(x,y,points) << endl;
}