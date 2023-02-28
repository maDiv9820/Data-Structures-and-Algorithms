'''
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
'''
def isValid(r: int, c: int, rsize: int, csize: int):
    if r < 0 or r >= rsize or c < 0 or c >= csize:
        return False
    return True
def updateMatrix(mat: list[list[int]]) -> list[list[int]]:
    q = []
    ans = [[-1 for c in range(len(mat[0]))] for r in range(len(mat))]
    for r in range(len(mat)):
        for c in range(len(mat[0])):
            if mat[r][c] == 0:
                q.append((r,c))
                ans[r][c] = 0
    while len(q) > 0:
        r,c = q[0][0],q[0][1]
        q.pop(0)
        if isValid(r-1,c,len(mat),len(mat[0])) and ans[r-1][c] == -1:
            ans[r-1][c] = 1+ans[r][c]
            q.append((r-1,c))
        if isValid(r+1,c,len(mat),len(mat[0])) and ans[r+1][c] == -1:
            ans[r+1][c] = 1+ans[r][c]
            q.append((r+1,c))
        if isValid(r,c-1,len(mat),len(mat[0])) and ans[r][c-1] == -1:
            ans[r][c-1] = 1+ans[r][c]
            q.append((r,c-1))
        if isValid(r,c+1,len(mat),len(mat[0])) and ans[r][c+1] == -1:
            ans[r][c+1] = 1+ans[r][c]
            q.append((r,c+1))
    return ans

if __name__ == "__main__":
    n,m = map(int,input().split())
    mat = [[int(x) for x in input().split()] for r in range(n)]
    ans = updateMatrix(mat)
    print(ans)