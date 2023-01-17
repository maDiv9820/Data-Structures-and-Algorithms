/*
Pascal's Triangle

Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:

Input: numRows = 1
Output: [[1]]

Constraints:

    1 <= numRows <= 30
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    /*
        Time Complexity:- O(numRows^2)
        Space Complexity:- O(1)
    */
    vector<vector<int>> triangle;
    for(int row = 0; row < numRows; row++) {
        vector<int> eachrow(row+1,1);
        triangle.push_back(eachrow);
    }
    for(int row = 2; row < numRows; row++) {
        for(int col = 1; col < triangle[row].size()-1; col++)
            triangle[row][col] = triangle[row-1][col-1]+triangle[row-1][col];
    }
    return triangle;
}

int main() {
    int numRows;
    cin >> numRows;
    vector<vector<int>> triangle = generate(numRows);
    for(int row = 0; row < triangle.size(); row++) {
        for(int col = 0; col < triangle[row].size(); col++)
            cout << triangle[row][col] << " ";
        cout << endl;
    }
}