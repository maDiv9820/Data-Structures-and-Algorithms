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

TreeNode* takeInput() {
    TreeNode *root = NULL;
    int n,left, right;
    cin >> n;
    if(n == -1)
        return root;
    root = new TreeNode(n);
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        cin >> left >> right;
        if(left != -1) {
            TreeNode* leftT = new TreeNode(left);
            front->left = leftT;
            q.push(leftT);
        }
        if(right != -1) {
            TreeNode* rightT = new TreeNode(right);
            front->right = rightT;
            q.push(rightT);
        }
    }
    return root;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> traverse;
    vector<int> v;
    queue<TreeNode*> nodeQ;
    nodeQ.push(root);
    nodeQ.push(NULL);
    while(!nodeQ.empty()) {
        TreeNode* front = nodeQ.front();
        nodeQ.pop();
        if(front == NULL) {
            if(v.size() > 0) {
                traverse.push_back(v);
                v.clear();
                nodeQ.push(NULL);
            }
            continue;
        }
        v.push_back(front->val);
        if(front->left)
            nodeQ.push(front->left);
        if(front->right)
            nodeQ.push(front->right);
    }
    return traverse;
}

int main() {
    TreeNode* root = takeInput();
    vector<vector<int>> traverse = levelOrder(root);
    for(vector<int> level: traverse) {
        for(int x: level)
            cout << x << " ";
        cout << endl;
    }
}