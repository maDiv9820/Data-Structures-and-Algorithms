/*
Max Area of Island

You are given an m x n binary matrix grid. An island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the 
grid are surrounded by water. The area of an island is the number of cells with a value 1 
in the island. Return the maximum area of an island in grid. If there is no island, return 0.
 
Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.

Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int checkGrid(vector<vector<int>>& grid, int r, int c) {
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
        return 0;
    grid[r][c] = 0;
    return 1+checkGrid(grid,r-1,c)+checkGrid(grid,r+1,c)+checkGrid(grid,r,c-1)+checkGrid(grid,r,c+1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxarea = 0;
    for(int row = 0; row < grid.size(); row++)
        for(int col = 0; col < grid[0].size(); col++)
            if(grid[row][col] == 1) {
                int area = checkGrid(grid,row,col);
                maxarea = max(maxarea,area);
            }
    return maxarea;
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n,0));
    for(int row = 0; row < m; row++)
        for(int col = 0; col < n; col++)
            cin >> grid[row][col];
    cout << maxAreaOfIsland(grid) << endl;
}