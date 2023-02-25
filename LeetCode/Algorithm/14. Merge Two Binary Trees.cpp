/*
Merge Two Binary Trees

You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, s
ome nodes of the two trees are overlapped while the others are not. 
You need to merge the two trees into a new binary tree. 
The merge rule is that if two nodes overlap, 
then sum node values up as the new value of the merged node. 
Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.

Note: The merging process must start from the root nodes of both trees.

Example 1:

Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]

Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]

Constraints:

    The number of nodes in both trees is in the range [0, 2000].
    -104 <= Node.val <= 104
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

TreeNode* mergeTrees(TreeNode* root1 = NULL, TreeNode* root2 = NULL) {
    TreeNode* root = NULL;
    if(root1 && root2) {
        root = new TreeNode(root1->val+root2->val);
        root->left = mergeTrees(root1->left,root2->left);
        root->right = mergeTrees(root1->right,root2->right);
    }
    else if(root1) {
        root = new TreeNode(root1->val);
        root->left = mergeTrees(root1->left);
        root->right = mergeTrees(root1->right);
    }
    else if(root2) {
        root = new TreeNode(root2->val);
        root->left = mergeTrees(root2->left);
        root->right = mergeTrees(root2->right);
    }
    return root;
}

int main() {
    TreeNode* root1 = takeInput();
    TreeNode* root2 = takeInput();
    TreeNode* root = mergeTrees(root1,root2);
}