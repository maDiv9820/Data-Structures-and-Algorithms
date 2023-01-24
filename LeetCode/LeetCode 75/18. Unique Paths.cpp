/*
Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either 
down or right at any point in time. Given the two integers m and n, return the number of possible unique paths 
that the robot can take to reach the bottom-right corner. The test cases are generated so that the answer will 
be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28

Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

Constraints:

    1 <= m, n <= 100
*/

#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n, int x, int y, vector<vector<int>>& noOfPaths) {
    if(x > m || y > n)
        return 0;
    if(x == m && y == n)
        return 1;
    if(noOfPaths[x][y] != INT_MAX)
        return noOfPaths[x][y];
    noOfPaths[x][y] = uniquePaths(m,n,x+1,y,noOfPaths)+uniquePaths(m,n,x,y+1,noOfPaths);
    return noOfPaths[x][y];
}

int uniquePaths(int m, int n) {
    /*
        Solution 1: Using Recursion
        Time Complexity:- O(2^m*n)
        Space Complexity:- O(m*n)
        where m and n is row and columns of the grid
    
    if(x > m || y > n)
        return 0;
    if(x == m && y == n)
        return 1;
    return (uniquePaths(m,n,x+1,y)+uniquePaths(m,n,x,y+1));
    */
    /*
        Solution 2: Using Dynamic Programming
        Time Complexity:- O(m*n)
        Space Complexity:- O(m*n)
        where m and n is row and columns of the grid

    vector<vector<int>> noOfPaths(m,vector<int>(n,0));
    for(int index = 0; index < m-1; index++)
        noOfPaths[index][n-1] = 1;
    for(int index = 0; index < n-1; index++)
        noOfPaths[m-1][index] = 1;
    for(int row = m-2; row >= 0; row--)
        for(int col = n-2; col >= 0; col--)
            noOfPaths[row][col] = noOfPaths[row+1][col]+noOfPaths[row][col+1];
    return noOfPaths[0][0];
    */
    /*
        Solution 3:- Using Memoization
        Time Complexity:- O(m*n)
        Space Complexity:- O(m*n)
        where m and n is row and columns of the grid
    */
    vector<vector<int>> noOfPaths(m+1,vector<int>(n+1,INT_MAX));
    return uniquePaths(m,n,1,1,noOfPaths);
}

int main() {
    int m,n;
    cin >> m >> n;
    cout << uniquePaths(m,n) << endl;
}