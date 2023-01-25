/*
Invert Binary Tree

Given the root of a binary tree, invert the tree, and return its root.

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

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
void printLevelWise(TreeNode* root) {
    queue<TreeNode*> nodeQ;
    vector<int> v;
    nodeQ.push(root);
    nodeQ.push(NULL);
    while(!nodeQ.empty()) {
        TreeNode* front = nodeQ.front();
        nodeQ.pop();
        if(front == NULL) {
            if(v.size() > 0) {
                for(int x: v)
                    cout << x << " ";
                cout << endl;
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
}
TreeNode* invertTree(TreeNode* root) {
    if(root == NULL)
        return root;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}
int main() {
    TreeNode* root = takeInput();
    root = invertTree(root);
    printLevelWise(root);
}