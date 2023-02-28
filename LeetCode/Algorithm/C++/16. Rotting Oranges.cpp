/*
Rotting Oranges

You are given an m x n grid where each cell can have one of three values:
    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 10
    grid[i][j] is 0, 1, or 2.
*/
#include <bits/stdc++.h>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    int time = 0, fresh = 0;
    queue<pair<int,int>> q;
    for(int r = 0; r < grid.size(); r++) {
        for(int c = 0; c < grid[0].size(); c++) {
            if(grid[r][c] == 1)
                fresh++;
            if(grid[r][c] == 2)
                q.push({r,c});
        }
    }
    while(!q.empty() && fresh > 0) {
        int size = q.size();
        while(size > 0) {
            int r = q.front().first, c = q.front().second;
            q.pop();
            pair<int,int> directions[] = {{0,1},{0,-1},{1,0},{-1,0}};
            for(pair<int,int> p: directions) {
                int row = r+p.first, col = c+p.second;
                if(row < 0 || row == grid.size() 
                    || col < 0 || col == grid[0].size() || grid[row][col] != 1)
                    continue;
                grid[row][col] = 2;
                q.push({row,col});
                fresh--;
            }
            size--;
        }
        time++;
    }
    return (fresh==0)?time:-1;
}
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int row = 0; row < grid.size(); row++)
        for(int col = 0; col < grid[0].size(); col++)
            cin >> grid[row][col];
    cout << orangesRotting(grid) << endl;
}