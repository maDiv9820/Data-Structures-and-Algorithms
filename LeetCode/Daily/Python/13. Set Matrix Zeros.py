'''
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
'''
class Solution:
    def __setRowZero(self, matrix: list[list[int]], row: int) -> None:
        for col in range(len(matrix[0])):
            matrix[row][col] = 0
    def __setColZero(self, matrix: list[list[int]], col: int) -> None:
        for row in range(len(matrix)):
            matrix[row][col] = 0
    def setZeros(self, matrix: list[list[int]]) -> None:
        pairs = []
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c] == 0:
                    pairs.append((r,c))
        for pair in pairs:
            self.__setRowZero(matrix,pair[0])
            self.__setColZero(matrix,pair[1])
n = int(input())
matrix = [[int(x) for x in input().split()] for i in range(n)]
sol = Solution()
sol.setZeros(matrix)
print(matrix)        