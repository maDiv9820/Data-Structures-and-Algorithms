/*
Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -2^31 <= matrix[i][j] <= 2^31 - 1
*/
#include <bits/stdc++.h>
using namespace std;
void setRowZero(vector<vector<int>>& matrix, int row) {
    for(int col = 0; col < matrix[0].size(); col++)
        matrix[row][col] = 0;
}
void setColZero(vector<vector<int>>& matrix, int col) {
    for(int row = 0; row < matrix.size(); row++)
        matrix[row][col] = 0;
}
void setZeros(vector<vector<int>>& matrix) {
    vector<pair<int,int>> pairs;
    for(int r = 0; r < matrix.size(); r++)
        for(int c = 0; c < matrix[0].size(); c++)
            if(!matrix[r][c])
                pairs.push_back({r,c}); 
    for(auto p: pairs) {
        setRowZero(matrix,p.first);
        setColZero(matrix,p.second);
    }
}
int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    for(int r = 0; r < m; r++)
        for(int c = 0; c < n; c++)
            cin >> matrix[r][c];
    setZeros(matrix);
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++)
            cout << matrix[r][c] << " ";
        cout << endl;
    }
}