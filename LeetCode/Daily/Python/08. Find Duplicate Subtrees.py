'''
Find Duplicate Subtrees

Given the root of a binary tree, return all duplicate subtrees.
For each kind of duplicate subtrees, you only need to return the root node of any one of them.
Two trees are duplicate if they have the same structure with the same node values.

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]

Example 2:

Input: root = [2,1,1]
Output: [[1]]

Example 3:

Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]

Constraints:

    The number of the nodes in the tree will be in the range [1, 5000]
    -200 <= Node.val <= 200
'''
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def findDuplicateSubtrees(root: TreeNode) -> list[TreeNode]:
    m = {}
    ans = []
    def traverse(root: TreeNode) -> str:
        if not root:
            return "null"
        path = str(root.val)+traverse(root.left)+traverse(root.right)
        if m.get(path,None) != None and len(m[path]) == 1:
           ans.append(root)
        if m.get(path,None) == None:
            m[path] = list()
        m[path].append(root) 
        return path
    traverse(root)
    return ans

def takeInput() -> TreeNode:
    val = int(input())
    if val < -200 and val > 200:
        return None
    root = TreeNode(val)
    root.left = takeInput()
    root.right = takeInput()
    return root

def traverse(root: TreeNode):
    if not root:
        return
    print(root, end = ' ')
    traverse(root.left)
    traverse(root.right)

root = takeInput()
duplicates = findDuplicateSubtrees(root)
for r in duplicates:
    traverse(r)
    print()