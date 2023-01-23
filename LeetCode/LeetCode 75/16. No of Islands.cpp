/*
Number of Islands

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
return the number of islands. An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

void checkGrid(vector<vector<char>>& grid, int r, int c) {
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
        return;
    if(grid[r][c] == '1') {
        grid[r][c] = '0';
        checkGrid(grid,r-1,c);
        checkGrid(grid,r+1,c);
        checkGrid(grid,r,c-1);
        checkGrid(grid,r,c+1);
    }
    return;
}

int numIslands(vector<vector<char>> &grid) {
    int count = 0;
    for(int row = 0; row < grid.size(); row++)
        for(int col = 0; col < grid[0].size(); col++)
            if(grid[row][col] == '1') {
                count++;
                checkGrid(grid,row,col);
            }
    return count;
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<char>> grid(m,vector<char>(n,'0'));
    for(int row = 0; row < m; row++)
        for(int col = 0; col < n; col++)
            cin >> grid[row][col];
    cout << numIslands(grid) << endl;
}