/*
01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:

Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:

Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.
    There is at least one 0 in mat.
*/
#include <bits/stdc++.h>
using namespace std;
bool isValid(int row, int col, int rowsize, int colsize) {
    if(row < 0 || row >= rowsize || col < 0 || col >= colsize)
        return false;
    return true;
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> matrix(mat.size(),vector<int>(mat[0].size(),-1));
    queue<pair<int,int>> q;
    for(int row = 0; row < mat.size(); row++) {
        for(int col = 0; col < mat[0].size(); col++) {
            if(mat[row][col] == 0) {
                matrix[row][col] = 0;
                q.push({row,col});
            }
        }
    }
    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        if(isValid(row-1,col,matrix.size(),matrix[0].size()) && matrix[row-1][col] == -1) {
            matrix[row-1][col] = 1+matrix[row][col];
            q.push({row-1,col});
        }
        if(isValid(row+1,col,matrix.size(),matrix[0].size()) && matrix[row+1][col] == -1) {
            matrix[row+1][col] = 1+matrix[row][col];
            q.push({row+1,col});
        }
        if(isValid(row,col-1,matrix.size(),matrix[0].size()) && matrix[row][col-1] == -1) {
            matrix[row][col-1] = 1+matrix[row][col];
            q.push({row,col-1});
        }
        if(isValid(row,col+1,matrix.size(),matrix[0].size()) && matrix[row][col+1] == -1) {
            matrix[row][col+1] = 1+matrix[row][col];
            q.push({row,col+1});
        }
    }
    return matrix;
}
int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> mat(m,vector<int>(n,0));
    for(int row = 0; row < m; row++)
        for(int col = 0; col < n; col++)
            cin >> mat[row][col];
    cout << endl;
    vector<vector<int>> matrix = updateMatrix(mat);
    for(auto v: matrix) {
        for(auto x: v)
            cout << x << " ";
        cout << endl;
    }
}