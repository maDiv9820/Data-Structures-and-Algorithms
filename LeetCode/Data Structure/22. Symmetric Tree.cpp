/*
Symmetric Tree

Given the root of a binary tree, check whether 
it is a mirror of itself (i.e., symmetric around its center).

Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
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

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if(left == NULL && right == NULL)
        return true;
    if((left && !right) || (!left && right) || (left->val != right->val))
        return false;
    bool check1 = isSymmetric(left->left,right->right);
    bool check2 = isSymmetric(left->right,right->left);
    return check1&&check2;
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL)
        return true;
    return isSymmetric(root->left,root->right);
}

int main() {
    TreeNode* root = takeInput();
    cout << ((isSymmetric(root) == 1) ? "true":"false") << endl;    
}