/*
Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules. 

Example 1:

Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true

Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. 
Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit 1-9 or '.'.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkRow(vector<vector<char>>& board, int row, int col) {
   set<char> s;
   for(int index = 0; index < 9; index++) {
        char val = board[index][col];
        if(s.find(val) != s.end())
            return false;
        if(val != '.')
            s.insert(val);
   }
   return true;
}

bool checkCol(vector<vector<char>>& board, int row, int col) {
    set<char> s;
    for(int index = 0; index < 9; index++) {
        char val = board[row][index];
        if(s.find(val) != s.end())
            return false;
        if(val != '.')
            s.insert(val);
    }
    return true;
}

bool checkMatrix(vector<vector<char>>& board, int row, int col) {
    set<char> s;
    for(int rowNo = 0; rowNo < 3; rowNo++) {
        for(int colNo = 0; colNo < 3; colNo++) {
            char val = board[row+rowNo][col+colNo];
            if(s.find(val) != s.end())
                return false;
            if(val != '.')
                s.insert(val);
        }
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            if(!checkRow(board,row,col) || !checkCol(board,row,col) || 
                !checkMatrix(board,row-row%3,col-col%3))
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(9,vector<char>(9,0));
    for(int outerIndex = 0; outerIndex < 9; outerIndex++)
        for(int innerIndex = 0; innerIndex < 9; innerIndex++)
            cin >> board[outerIndex][innerIndex];
    bool isValid = isValidSudoku(board);
    cout << ((isValid == 1)? "true":"false") << endl;
}