/*
Check If It Is a Straight Line

You are given an array coordinates, coordinates[i] = [x, y], 
where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane. 

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

    2 <= coordinates.length <= 1000
    coordinates[i].length == 2
    -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
    coordinates contains no duplicate point.
*/
#include <bits/stdc++.h>
using namespace std;
bool checkStraightLine(vector<vector<int>>& coordinates) {
    if(coordinates.size() <= 2)
        return true;
    int x0 = coordinates[0][0], x1 = coordinates[1][0];
    int y0 = coordinates[0][1], y1 = coordinates[1][1];
    int dx = x1-x0;
    int dy = y1-y0;
    for(int index = 0; index < coordinates.size(); index++)
        if(dx*(coordinates[index][1]-y1) != dy*(coordinates[index][0]-x1))
            return false;
    return true;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> coordinates(n,vector<int>(2,0));
    for(int index = 0; index < n; index++)
        cin >> coordinates[index][0] >> coordinates[index][1];
    cout << ((checkStraightLine(coordinates) == 1) ? "true":"false") << endl;    
}