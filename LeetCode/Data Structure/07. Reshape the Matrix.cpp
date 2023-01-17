/*
 Reshape the Matrix

In MATLAB, there is a handy function called reshape which can reshape an m x n matrix 
into a new one with a different size r x c keeping its original data. You are given an m x n matrix mat 
and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.
The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.
If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; 
Otherwise, output the original matrix.

Example 1:

Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

Example 2:

Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 100
    -1000 <= mat[i][j] <= 1000
    1 <= r, c <= 300

*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    /*
        Time Complexity:- O(r*c)
        Space Complexity:- O(1)
    */
    if(mat.size()*mat[0].size() != r*c)
        return mat;
    vector<vector<int>> newmatrix(r,vector<int>(c,0));
    int newMatRowIndex = 0, newMatColIndex = 0;
    for(int currentMatRowIndex = 0; currentMatRowIndex < mat.size(); currentMatRowIndex++) {
        for(int currentMatColIndex = 0; currentMatColIndex < mat[0].size(); currentMatColIndex++) {
            if(newMatColIndex >= c) {
                newMatColIndex = 0;
                newMatRowIndex++;
            }
            newmatrix[newMatRowIndex][newMatColIndex] = mat[currentMatRowIndex][currentMatColIndex];
            newMatColIndex++;
        }
    }
    return newmatrix;
}

int main() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> mat(r,vector<int>(c,0));
    for(int row = 0; row < r; row++)
        for(int col = 0; col < c; col++)
            cin >> mat[row][col];
    cin >> r >> c;
    vector<vector<int>> newmatrix = matrixReshape(mat,r,c);
    for(int row = 0; row < newmatrix.size(); row++) {
        for(int col = 0; col < newmatrix[0].size(); col++)
            cout << newmatrix[row][col] << " ";
        cout << endl;
    }
}