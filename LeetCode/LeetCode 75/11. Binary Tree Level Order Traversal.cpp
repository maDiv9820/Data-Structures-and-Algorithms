/*
Binary Tree Level Order Traversal

Given the root of a binary tree, return the level order traversal of its nodes' values. 
(i.e., from left to right, level by level).

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: [] 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> traverse;
    if(root == NULL)
        return traverse;
    queue<TreeNode*> nodeQ;
    vector<int> level;
    nodeQ.push(root);
    nodeQ.push(NULL);
    while(!nodeQ.empty()) {
        TreeNode* front = nodeQ.front();
        nodeQ.pop();
        if(front == NULL) {
            if(level.size() > 0) {
                traverse.push_back(level);
                level.clear();
                nodeQ.push(NULL);
            }
            continue;
        }
        level.push_back(front->val);
        if(front->left)
            nodeQ.push(front->left);
        if(front->right)
            nodeQ.push(front->right);
    }
    return traverse;
}

TreeNode* takeInput() {
    TreeNode* root = NULL;
    int n;
    cin >> n;
    if(n < -1000 || n > 1000)
        return root;
    root = new TreeNode(n);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}

int main() {
    int n;
    cin >> n;
    TreeNode *root;
    root = takeInput();
    vector<vector<int>> traverse = levelOrder(root);
    for(auto x1: traverse) {
        for(auto x2:x1)
            cout << x2 << " ";
        cout << endl;
    }
}