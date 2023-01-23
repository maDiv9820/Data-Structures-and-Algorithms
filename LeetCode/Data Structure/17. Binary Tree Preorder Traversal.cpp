/*
Binary Tree Preorder Traversal

Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:

Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traversal;
    if(root == NULL)
        return traversal;
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    traversal.push_back(root->val);
    traversal.insert(traversal.end(),left.begin(),left.end());
    traversal.insert(traversal.end(),right.begin(),right.end());
    return traversal;
}

int main() {
    TreeNode* root = takeInput();
    vector<int> traversal = preorderTraversal(root);
    for(int x: traversal)
        cout << x << " ";
    cout << endl;
}