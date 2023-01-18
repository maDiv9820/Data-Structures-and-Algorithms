/*
Search a 2D Matrix

You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104
*/

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    /*
        Solution 1:-
        Time Complexity:- O(n+m)
        Space Complexity:- O(1)
        where m and n is the no of rows and columns
    
    if(target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1])
        return false;
    int rowNo = 0, colNo = matrix[0].size()-1;
    while(rowNo < matrix.size() && colNo >= 0) {
        if(matrix[rowNo][colNo] == target)
            return true;
        if(matrix[rowNo][colNo] > target)
            colNo--;
        else
            rowNo++;
    }
    return true;
    */
    /*
        Solution 2:-
        Time Complexity:- O(log(m)*log(n))
        Space Complexity:- O(1)
        where m and n is the no of rows and columns
    */
    if(matrix.size()==0) 
        return false;
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    int low = 0;
    int high = (n*m)-1;
    
    while(low<=high)
    {
        int mid = (low +(high-low)/2);
        if(matrix[mid/m][mid%m]==target)
            return true;
        
        if(matrix[mid/m][mid%m]<target)
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}

int main() {
    int m,n,target;
    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n,0));
    for(int rowIndex = 0; rowIndex < m; rowIndex++)
        for(int colIndex = 0; colIndex < n; colIndex++)
            cin >> matrix[rowIndex][colIndex];
    cin >> target;
    bool found = searchMatrix(matrix,target);
    cout << ((found == 1) ? "true":"false") << endl;
}