/*
Matrix Diagonal Sum

Given a square matrix mat, return the sum of the matrix diagonals.
Only include the sum of all the elements on the primary diagonal 
and all the elements on the secondary diagonal that are not part 
of the primary diagonal. 

Example 1:

Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.

Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8

Example 3:

Input: mat = [[5]]
Output: 5

Constraints:

    n == mat.length == mat[i].length
    1 <= n <= 100
    1 <= mat[i][j] <= 100
*/
#include <bits/stdc++.h>
using namespace std;
int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    for(int index = 0; index < mat.size(); index++)
        if(index == (mat[0].size()-1-index))
            sum += mat[index][index];
        else
            sum += (mat[index][index] + mat[index][mat[0].size()-1-index]);
    return sum;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(int row = 0; row < n; row++)
        for(int col = 0; col < n; col++)
            cin >> mat[row][col];
    cout << diagonalSum(mat) << endl;
}