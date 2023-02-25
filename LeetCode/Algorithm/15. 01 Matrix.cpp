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

int getDistance(vector<vector<int>>& mat, int row, int col) {
    if(row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size())
        return 100000;
    return mat[row][col];
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    vector<vector<int>> matrix(mat.size(),vector<int>(mat[0].size(),0));
    for(int row = 0; row < mat.size(); row++) {
        for(int col = 0; col < mat[0].size(); col++) {
            if(mat[row][col] == 1) {
                int left = getDistance(matrix,row,col-1);
                int up = getDistance(matrix,row-1,col);
                matrix[row][col] = 1+min(left,up);
            }
            cout << endl;
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